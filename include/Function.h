#pragma once
#include <vector>
#include "Eigen/Dense"

using Eigen::VectorXd;
using Eigen::MatrixXd;

class Function
{
public:
	Function(size_t _d);
	virtual ~Function();
	virtual double eval(const VectorXd& x) const = 0;
	virtual VectorXd grad(const VectorXd& x) const = 0;
	VectorXd hessian_approx(const VectorXd& x, int i) const;
	MatrixXd hessian_approx(const VectorXd& x) const;
	size_t dim() const;
	virtual const char* print_function() const = 0;
protected:
	size_t d;
};
