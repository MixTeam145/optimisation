#pragma once
#include "StopCriterion.h"

class AbsValueSC : public StopCriterion
{
public:
	AbsValueSC(size_t n = 100, double epsilon = 1e-3);
	~AbsValueSC();
	bool condition(const Function* f, const std::vector<Vector>& trajectory) const override;
private:
	double epsilon;
};

