#pragma once
#include "Function.h"

class BoothFunction : public Function
{
public:
	BoothFunction();
	~BoothFunction();
	double eval(const Vector& x) const override;
	Vector grad(const Vector& x) const override;
	const char* print_function() const override;
};

