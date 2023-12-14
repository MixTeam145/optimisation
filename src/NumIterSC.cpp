#include "NumIterSC.h"

NumIterSC::NumIterSC(size_t n) : StopCriterion(n)
{

}

NumIterSC::~NumIterSC()
{

}

bool NumIterSC::condition(const Function* f, const std::vector<VectorXd>& trajectory) const
{
    return trajectory.size() - 1 < n;
}
