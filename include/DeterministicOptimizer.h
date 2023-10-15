#pragma once
#include "Optimizer.h"

class DeterministicOptimizer : public Optimizer
{
public:
	DeterministicOptimizer(Function* _f, StopCriterion* _criterion);
	~DeterministicOptimizer();
private:
	double max_direction_magnitude() const;
	double one_dim_optimization(const double left_border, const double right_border, const double eps = 1e-8) const;
	void set_start(const VectorXd& start_point) override;
	void next_point() override;
	VectorXd newton_direction;
};

