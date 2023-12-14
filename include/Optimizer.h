#pragma once
#include "StopCriterion.h"

/**
* The abstract class for function optimizer
*/
class Optimizer
{
public:
	/**
	* Constructs an Optimizer object with given Function and StopCriterion
	* 
	* \param f Objective function
	* \param criterion Stop criterion
	*/ 
	Optimizer(Function* f, StopCriterion* criterion);

	virtual ~Optimizer();

	/**
	* Performs optimization
	* 
	* \param start_point initial guess
	*/
	void optimize(const VectorXd& start_point);

	std::vector<VectorXd> get_trajectory() { return trajectory; }

	void set_f(Function* new_f);

	void set_criterion(StopCriterion* new_criterion);

	void set_domain(const VectorXd& min_point, const VectorXd& max_point);

	void set_default_domain();
protected:
	/**
	* Objective function
	*/
	Function* f;

	/**
	* Current iteration point
	*/

	VectorXd current_point;

	/**
	* Domain of the function
	*/
	RectArea domain;
private:
	/**
	* Calculates the next approximation
	*/
	virtual void next_point() = 0;

	/**
	* Stop criterion
	*/
	StopCriterion* criterion;

	/**
	* Sequence of approximations
	*/
	std::vector<VectorXd> trajectory;
};
