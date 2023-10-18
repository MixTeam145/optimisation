#include "RosenbrockFunction.h"

RosenbrockFunction::RosenbrockFunction() : Function(2)
{

}

RosenbrockFunction::~RosenbrockFunction()
{

}

double RosenbrockFunction::eval(const Vector& x) const
{
    return 100 * (x[1] - x[0] * x[0]) * (x[1] - x[0] * x[0]) + (1 - x[0]) * (1 - x[0]);
}

Vector RosenbrockFunction::grad(const Vector& x) const
{
    Vector g(2);
    g[0] = 2 * (-1 + x[0] + 200 * x[0] * x[0] * x[0] - 200 * x[0] * x[1]);
    g[1] = 200 * (x[1] - x[0] * x[0]);
    return g;
}

const char* RosenbrockFunction::print_function() const
{
    return "f(x,y) = 100(y - x^2)^2 + (1 - x)^2";
}
