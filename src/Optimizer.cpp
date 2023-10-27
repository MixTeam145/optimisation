#include "Optimizer.h"

Optimizer::Optimizer(Function* f, StopCriterion* criterion) : f(f), criterion(criterion)
{
	set_default_domain();
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

void Optimizer::set_f(Function* new_f)
{
	f = new_f;
	trajectory.clear();
	trajectory.shrink_to_fit();
}

void Optimizer::set_criterion(StopCriterion* new_criterion)
{
	criterion = new_criterion;
	trajectory.clear();
	trajectory.shrink_to_fit();
}

void Optimizer::set_domain(const Vector& min_point, const Vector& max_point)
{
	domain.set_area(min_point, max_point);
}

void Optimizer::set_default_domain()
{
	trajectory.clear();
	trajectory.shrink_to_fit();
	domain.set_area(Vector(f->dim(), -1), Vector(f->dim(), 1));
}

void Optimizer::set_start(const Vector& start_point)
{
	current_point = start_point;
}
