#include "AbsValueSC.h"

AbsValueSC::AbsValueSC(size_t _n, double _epsilon): StopCriterion(_n), epsilon(_epsilon)
{

}

AbsValueSC::~AbsValueSC()
{

}

bool AbsValueSC::condition(const Function* f, const std::vector<Vector>& trajectory) const
{
    return trajectory.size() - 1 < n && f->grad(trajectory.back()).norm() > epsilon;
}
