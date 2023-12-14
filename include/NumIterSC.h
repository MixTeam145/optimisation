#pragma once
#include "StopCriterion.h"

/**
* The number of iterations stop criterion class
*/
class NumIterSC : public StopCriterion
{
public:
	/**
	* Constructs a NumIterSC object with given maximum number of iterations
	*
	* \param n Maximum number of iterations
	*/
	NumIterSC(size_t n = 100);

	~NumIterSC();

	/**
	* Checks the stop condition
	*
	* \param f Objective function
	* \param trajectory Sequence of approximations
	*/
	bool condition(const Function* f, const std::vector<VectorXd>& trajectory) const override;
};

