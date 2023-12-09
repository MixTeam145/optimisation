#pragma once
#include "Function.h"

/**
* The Rosenbrock function class (arbitrary dimention)
*/
class RosenbrockFunction : public Function
{
public:
	/**
	* Constructs a RosenbrockFunction object with given dimensionality
	* 
	* \param d Dimensionality of the function
	*/
	RosenbrockFunction(size_t d = 2);

	~RosenbrockFunction();

	/**
	* Calculates the value of the function at a given point
	*
	* \param x Point
	*/
	double eval(const Vector& x) const override;

	/**
	* Calculates the gradient of the function at a given point
	*
	* \param x Point
	*/
	Vector grad(const Vector& x) const override;

	/**
	* Prints the function to given output stream
	*
	* \param os Output stream
	*/
	void print_function(std::ostream& os) const override;
};

