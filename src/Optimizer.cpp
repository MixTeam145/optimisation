#include "Optimizer.h"

Optimizer::Optimizer(Function* _f, StopCriterion* _criterion) : f(_f), criterion(_criterion)
{
	set_default_cubic_domain();
}

Optimizer::~Optimizer()
{

}

void Optimizer::optimize(const Vector& start_point)
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

void Optimizer::set_cubic_domain(const Vector& min_point, const Vector& max_point)
{
	cubic_domain.first = min_point;
	cubic_domain.second = max_point;
}

void Optimizer::set_default_cubic_domain()
{
	trajectory.clear();
	trajectory.shrink_to_fit();
	Vector min_point(f->dim(), 1),
		max_point(f->dim(), 1);
	cubic_domain = std::make_pair(min_point, max_point);
}

void Optimizer::set_start(const Vector& start_point)
{
	current_point = start_point;
}
