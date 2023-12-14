#pragma once
#include "Function.h"

/**
* The abstract class for stop criterion
*/
class StopCriterion
{
public:
	/**
	* Constructs a StopCriterion object with given maximum number of iterations
	* 
	* \param n Maximum number of iterations
	*/
	StopCriterion(size_t n = 100);

	virtual ~StopCriterion();

	/**
	* Checks the stop condition
	* 
	* \param f Objective function
	* \param trajectory Sequence of approximations
	*/
	virtual bool condition(const Function* f, const std::vector<VectorXd>& trajectory) const = 0;
protected:
	/**
	* Maximum number of iterations
	*/
	size_t n;
};

