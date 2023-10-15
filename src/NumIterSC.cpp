#include "NumIterSC.h"

NumIterSC::NumIterSC(size_t _n) : StopCriterion(_n)
{

}

NumIterSC::~NumIterSC()
{

}

bool NumIterSC::condition(const Function* f, const std::vector<VectorXd>& trajectory) const
{
    return trajectory.size() < n;
}
