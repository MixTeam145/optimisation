#pragma once
#include "Function.h"

class McCormickFunction : public Function
{
public:
	McCormickFunction();
	~McCormickFunction();
	double eval(const VectorXd& x) const override;
	VectorXd grad(const VectorXd& x) const override;
	const char* print_function() const override;
};

