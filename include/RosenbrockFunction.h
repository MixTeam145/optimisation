#pragma once
#include "Function.h"
class RosenbrockFunction : public Function
{
public:
	RosenbrockFunction();
	~RosenbrockFunction();
	double eval(const Vector& x) const override;
	Vector grad(const Vector& x) const override;
	const char* print_function() const override;
};

