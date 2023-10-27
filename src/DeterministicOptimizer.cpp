#include "DeterministicOptimizer.h"

DeterministicOptimizer::DeterministicOptimizer(Function* f, StopCriterion* criterion) : Optimizer(f, criterion)
{

}

DeterministicOptimizer::~DeterministicOptimizer()
{

}

double DeterministicOptimizer::max_direction_magnitude() const
{
	double magnitude = ((newton_direction[0] >= 0 ? domain.max_point[0] : domain.min_point[0]) - current_point[0]) / newton_direction[0];
	for (int i = 1; i < newton_direction.size(); ++i)
	{
		double tm = ((newton_direction[0] >= 0 ? domain.max_point[i] : domain.min_point[i]) - current_point[0]) / newton_direction[0];
		if (magnitude > tm)
			magnitude = tm;
	}
	return magnitude;
}

double DeterministicOptimizer::one_dim_optimization(double left_border, double right_border, double eps) const
{
	double l = left_border, r = right_border;
	for (int i = 0; r - l > eps; ++i)
	{
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
	newton_direction = -1 * f->hessian_approx(current_point).inverse() * f->grad(current_point);
	double alpha = one_dim_optimization(0, max_direction_magnitude());
	current_point += alpha * newton_direction;
}
