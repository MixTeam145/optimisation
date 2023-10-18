#pragma once
#include "Function.h"

class McCormickFunction : public Function
{
public:
	McCormickFunction();
	~McCormickFunction();
	double eval(const Vector& x) const override;
	Vector grad(const Vector& x) const override;
	const char* print_function() const override;
};

