#pragma once
#include <iostream>
#include "RectArea.h"

/**
* The abstract class for real-valued functions
*/
class Function
{
public:
	/**
	* Constructs a Function object with given dimensionality
	* 
	* \param dim Dimensionality of the function
	*/ 
	Function(size_t dim);

	virtual ~Function();

	/**
	* Calculates the value of the function at a given point 
	* 
	* \param x Point
	*/
	virtual double eval(const VectorXd& x) const = 0;

	/**
	* Calculates the gradient of the function at a given point
	* 
	* \param x Point
	*/
	virtual VectorXd grad(const VectorXd& x) const = 0;

	/**
	* Calculates the i-th row of the Hessian matrix (using numerical differentiation) at a given point
	* 
	* \param x Point
	* \param i Row number
	* \param a Domain of the function
	*/
	VectorXd hessian_approx(const VectorXd& x, Index i, const RectArea& a) const;

	/**
	* Calculates the Hessian matrix (using numerical differentiation) at a given point
	* 
	* \param x Point
	* \param a Domain of the function
	*/
	MatrixXd hessian_approx(const VectorXd& x, const RectArea& a) const;

	size_t get_dim() const;
	
	/**
	* Print the function
	*/
	virtual void print_function(std::ostream& os = std::cout) const = 0;
protected:
	/**
	* Dimensionality of the function
	*/
	size_t dim;
};
