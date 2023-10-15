#pragma once
#include "Function.h"

class BoothFunction : public Function
{
public:
	BoothFunction();
	~BoothFunction();
	double eval(const VectorXd& x) const override;
	VectorXd grad(const VectorXd& x) const override;
	const char* print_function() const override;
};

