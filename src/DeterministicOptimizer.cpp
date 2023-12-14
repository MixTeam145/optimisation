#include "DeterministicOptimizer.h"

DeterministicOptimizer::DeterministicOptimizer(Function* f, StopCriterion* criterion) : Optimizer(f, criterion)
{

}

DeterministicOptimizer::~DeterministicOptimizer()
{

}

double DeterministicOptimizer::max_direction_magnitude() const
{
	double magnitude = 0;
	bool flag = true;
	for (Index i = 0; i < newton_direction.size(); ++i) {
		if (std::abs(newton_direction[i]) > 1e-16) {
			if (!flag)
				magnitude = std::min(magnitude,
					((newton_direction[i] >= 0 ? domain.max_point[i] : domain.min_point[i]) - current_point[i]) / newton_direction[i]);
			else {
				magnitude = ((newton_direction[i] >= 0 ? domain.max_point[i] : domain.min_point[i]) - current_point[i]) / newton_direction[i];
				flag = false;
			}
		}
	}
	return magnitude;
}

double DeterministicOptimizer::one_dim_optimization(double left_border, double right_border, double eps) const
{
	double l = left_border, r = right_border;
	while (r - l > eps) {
		double tl = (2 * l + r) / 3, tr = (l + 2 * r) / 3;
		if (f->eval(current_point + tl * newton_direction) < f->eval(current_point + tr * newton_direction))
			r = tr;
		else
			l = tl;
	}
	return (l + r) / 2;
}

void DeterministicOptimizer::next_point()
{
	newton_direction = -f->hessian_approx(current_point, domain).colPivHouseholderQr().solve(f->grad(current_point));
	double alpha = one_dim_optimization(0, max_direction_magnitude());
	current_point += alpha * newton_direction;
}
