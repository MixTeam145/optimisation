#pragma once
#include "StopCriterion.h"

class NumIterSC : public StopCriterion
{
public:
	NumIterSC(size_t _n = 100);
	~NumIterSC();
	bool condition(const Function* f, const std::vector<VectorXd>& trajectory) const override;
};

