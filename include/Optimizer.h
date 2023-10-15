#pragma once
#include "Function.h"
#include "StopCriterion.h"

class Optimizer
{
public:
	Optimizer(Function* _f, StopCriterion* _criterion);
	virtual ~Optimizer();
	void optimize(const VectorXd& start_point);
	std::vector<VectorXd> get_trajectory() { return trajectory; }
	void set_f(Function* _f);
	void set_criterion(StopCriterion* _criterion);
	void set_cubic_domain(const VectorXd& min_point, const VectorXd& max_point);
	void set_default_cubic_domain();
protected:
	Function* f;
	VectorXd current_point;
	std::pair<VectorXd, VectorXd> cubic_domain;
private:
	virtual void set_start(const VectorXd& start_point) = 0;
	virtual void next_point() = 0;
	StopCriterion* criterion;
	std::vector<VectorXd> trajectory;
};
