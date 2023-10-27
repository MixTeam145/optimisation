#pragma once
#include "Function.h"
#include "StopCriterion.h"
#include "RectArea.h"

class Optimizer
{
public:
	Optimizer(Function* f, StopCriterion* criterion);
	virtual ~Optimizer();
	void optimize(const Vector& start_point);
	std::vector<Vector> get_trajectory() { return trajectory; }
	void set_f(Function* new_f);
	void set_criterion(StopCriterion* new_criterion);
	void set_domain(const Vector& min_point, const Vector& max_point);
	void set_default_domain();
protected:
	Function* f;
	Vector current_point;
	RectArea domain;
private:
	void set_start(const Vector& start_point);
	virtual void next_point() = 0;
	StopCriterion* criterion;
	std::vector<Vector> trajectory;
};
