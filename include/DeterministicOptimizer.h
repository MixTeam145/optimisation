#pragma once
#include "Optimizer.h"

class DeterministicOptimizer : public Optimizer
{
public:
	DeterministicOptimizer(Function* f, StopCriterion* criterion);
	~DeterministicOptimizer();
private:
	double max_direction_magnitude() const;
	double one_dim_optimization(double left_border, double right_border, double eps = 1e-8) const;
	void next_point() override;
	Vector newton_direction;
};

