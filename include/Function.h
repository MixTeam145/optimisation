#pragma once
#include "Matrix.h"

class Function
{
public:
	Function(size_t _d);
	virtual ~Function();
	virtual double eval(const Vector& x) const = 0;
	virtual Vector grad(const Vector& x) const = 0;
	Vector hessian_approx(const Vector& x, int i) const;
	Matrix hessian_approx(const Vector& x) const;
	size_t dim() const;
	virtual const char* print_function() const = 0;
protected:
	size_t d;
};
