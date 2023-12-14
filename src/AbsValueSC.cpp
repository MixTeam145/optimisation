#include "AbsValueSC.h"

AbsValueSC::AbsValueSC(size_t n, double epsilon): StopCriterion(n), epsilon(epsilon)
{

}

AbsValueSC::~AbsValueSC()
{

}

bool AbsValueSC::condition(const Function* f, const std::vector<VectorXd>& trajectory) const
{
    return trajectory.size() - 1 < n && f->grad(trajectory.back()).norm() > epsilon;
}
