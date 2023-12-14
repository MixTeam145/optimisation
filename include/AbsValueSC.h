#pragma once
#include "StopCriterion.h"

/**
* The absolute value stop criterion class
*/
class AbsValueSC : public StopCriterion
{
public:
	/**
	* Constructs an AbsValueSC object with given maximum number of iterations and precision
	* 
	* \param n Maximum number of iterations
	* \param epsilon Precision
	*/
	AbsValueSC(size_t n = 100, double epsilon = 1e-3);

	~AbsValueSC();

	/**
	* Checks the stop condition
	*
	* \param f Objective function
	* \param trajectory Sequence of approximations
	*/
	bool condition(const Function* f, const std::vector<VectorXd>& trajectory) const override;
private:
	/**
	* Precision
	*/
	double epsilon;
};

