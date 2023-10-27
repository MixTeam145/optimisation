#include "Function.h"

Function::Function(size_t d) : d(d)
{

}

Function::~Function()
{

}

Vector Function::hessian_approx(const Vector& x, int i) const
{
	double h = 1e-5;
	Vector x_more = x, x_less = x;
	x_more[i] += h;
	x_less[i] -= h;
	return (grad(x_more) - grad(x_less)) / (2 * h);
}

Matrix Function::hessian_approx(const Vector& x) const
{
	Matrix h(x.size(), x.size());
	for (size_t i{}; i < x.size(); ++i) {
		h(i) = hessian_approx(x, i);
	}
	return h;
}

size_t Function::dim() const
{
	return d;
}

