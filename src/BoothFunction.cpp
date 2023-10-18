#include "BoothFunction.h"

BoothFunction::BoothFunction() : Function(2)
{

}

BoothFunction::~BoothFunction()
{

}

double BoothFunction::eval(const Vector& x) const
{
    return (x[0] + 2 * x[1] - 7) * (x[0] + 2 * x[1] - 7) + (2 * x[0] + x[1] - 5) * (2 * x[0] + x[1] - 5);
}

Vector BoothFunction::grad(const Vector& x) const
{
    Vector g(2);
    g[0] = -34 + 10 * x[0] + 8 * x[1];
    g[1] = -38 + 8 * x[0] + 10 * x[1];
    return g;
}

const char* BoothFunction::print_function() const
{
    return "f(x,y) = (x + 2y - 7)^2 + (2x + y - 5)^2";
}
