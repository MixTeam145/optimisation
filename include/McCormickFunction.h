#pragma once
#include "Function.h"

class McCormickFunction : public Function
{
public:
	McCormickFunction();
	~McCormickFunction();
	double eval(const Vector& x) const override;
	Vector grad(const Vector& x) const override;
	void print_function(std::ostream& os) const override;
};

