#include "Function.h"

Function::Function(size_t dim) : dim(dim)
{

}

Function::~Function()
{

}

VectorXd Function::hessian_approx(const VectorXd& x, Index i, const RectArea& a) const
{
	double h = 1e-5;
	VectorXd x_more = x, x_less = x;
	x_more[i] += h;
	x_less[i] -= h;
	if (!a.is_inside(x_more))
		return (grad(x) - grad(x_less)) / h;
	if (!a.is_inside(x_less))
		return (grad(x_more) - grad(x)) / h;
	return (grad(x_more) - grad(x_less)) / (2 * h);
}

MatrixXd Function::hessian_approx(const VectorXd& x, const RectArea& a) const
{
	MatrixXd h(x.size(), x.size());
	for (Index i = 0; i < x.size(); ++i) {
		h.row(i) = hessian_approx(x, i, a);
	}
	return h;
}

size_t Function::get_dim() const
{
	return dim;
}

