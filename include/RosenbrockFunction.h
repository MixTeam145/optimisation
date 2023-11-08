#pragma once
#include "Function.h"
class RosenbrockFunction : public Function
{
public:
	RosenbrockFunction(size_t d = 2);
	~RosenbrockFunction();
	double eval(const Vector& x) const override;
	Vector grad(const Vector& x) const override;
	void print_function(std::ostream& os) const override;
};

