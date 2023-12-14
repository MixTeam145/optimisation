#pragma once
#include "Optimizer.h"

/**
* The deterministic optimizer class (Newton's method)
*/
class DeterministicOptimizer : public Optimizer
{
public:
	/**
	* Constructs a DeterministicOptimizer object with given Function and StopCriterion
	* 
	* \param f Objective function
	* \param criterion Stop criterion
	*/
	DeterministicOptimizer(Function* f, StopCriterion* criterion);

	~DeterministicOptimizer();
private:
	/**
	* Calculates maximum directional magnitude for the Newton direction
	*/
	double max_direction_magnitude() const;

	/**
	* One-dimentional optimization (ternary search)
	* 
	* \param left_border Left border of the interval
	* \param right_border Right border of the interval
	* \param eps Precision
	*/
	double one_dim_optimization(double left_border, double right_border, double eps = 1e-8) const;

	/**
	* Calculates the next approximation
	*/
	void next_point() override;

	/**
	* The Newton direction
	*/
	VectorXd newton_direction;
};

