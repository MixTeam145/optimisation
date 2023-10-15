#pragma once
#include "Function.h"
class RosenbrockFunction : public Function
{
public:
	RosenbrockFunction();
	~RosenbrockFunction();
	double eval(const VectorXd& x) const override;
	VectorXd grad(const VectorXd& x) const override;
	const char* print_function() const override;
};

