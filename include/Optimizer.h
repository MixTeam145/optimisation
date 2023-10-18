#pragma once
#include "Function.h"
#include "StopCriterion.h"

class Optimizer
{
public:
	Optimizer(Function* _f, StopCriterion* _criterion);
	virtual ~Optimizer();
	void optimize(const Vector& start_point);
	std::vector<Vector> get_trajectory() { return trajectory; }
	void set_f(Function* _f);
	void set_criterion(StopCriterion* _criterion);
	void set_cubic_domain(const Vector& min_point, const Vector& max_point);
	void set_default_cubic_domain();
protected:
	Function* f;
	Vector current_point;
	std::pair<Vector, Vector> cubic_domain;
private:
	void set_start(const Vector& start_point);
	virtual void next_point() = 0;
	StopCriterion* criterion;
	std::vector<Vector> trajectory;
};
