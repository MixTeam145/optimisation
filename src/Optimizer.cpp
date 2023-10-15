#include "Optimizer.h"

Optimizer::Optimizer(Function* _f, StopCriterion* _criterion) : f(_f), criterion(_criterion)
{
	set_default_cubic_domain();
}

Optimizer::~Optimizer()
{

}

void Optimizer::optimize(const VectorXd& start_point)
{
	set_start(start_point);
	trajectory.push_back(start_point);
	while (criterion->condition(f, trajectory)) {
		next_point();
		trajectory.push_back(current_point);
	}
}

void Optimizer::set_f(Function* _f)
{
	f = _f;
	trajectory.clear();
	trajectory.shrink_to_fit();
}

void Optimizer::set_criterion(StopCriterion* _criterion)
{
	criterion = _criterion;
	trajectory.clear();
	trajectory.shrink_to_fit();
}

void Optimizer::set_cubic_domain(const VectorXd& min_point, const VectorXd& max_point)
{
	cubic_domain.first = min_point;
	cubic_domain.second = max_point;
}

void Optimizer::set_default_cubic_domain()
{
	trajectory.clear();
	trajectory.shrink_to_fit();
	VectorXd min_point = VectorXd::Constant(f->dim(), -1),
		max_point = VectorXd::Constant(f->dim(), 1);
	/*for (int i = 0; i < f->dim(); ++i)
	{
		min_point[i] = -1;
		max_point[i] = 1;
	}*/
	cubic_domain = std::make_pair(min_point, max_point);
}
