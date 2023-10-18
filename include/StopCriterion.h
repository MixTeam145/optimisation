#pragma once
#include "Function.h"

class StopCriterion
{
public:
	StopCriterion(size_t n = 100);
	virtual ~StopCriterion();
	virtual bool condition(const Function* f, const std::vector<Vector>& trajectory) const = 0;
protected:
	size_t n;
};

