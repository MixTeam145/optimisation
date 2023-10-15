#include "Function.h"

Function::Function(size_t _d) : d(_d)
{

}

Function::~Function()
{

}

VectorXd Function::hessian_approx(const VectorXd& x, int i) const
{
	//double eps = sqrt(std::numeric_limits<double>::epsilon()) * std::fabs(x[i]);
	double eps = 1e-5;
	VectorXd x_more = x, x_less = x;
	x_more[i] += eps;
	x_less[i] -= eps;
	return (grad(x_more) - grad(x_less)) / (2 * eps);
}

MatrixXd Function::hessian_approx(const VectorXd& x) const
{
	MatrixXd hess = MatrixXd::Zero(x.size(), x.size());
	for (int i = 0; i < x.size(); ++i) {
		hess.col(i) = hessian_approx(x, i);
	}
	return hess;
}

size_t Function::dim() const
{
	return d;
}

