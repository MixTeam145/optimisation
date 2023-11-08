#include "RosenbrockFunction.h"

RosenbrockFunction::RosenbrockFunction(size_t d) : Function(d)
{

}

RosenbrockFunction::~RosenbrockFunction()
{

}

double RosenbrockFunction::eval(const Vector& x) const
{
    double fvalue = 0;
    for (size_t i{}; i < d - 1; ++i) {
        fvalue += 100 * (x[i + 1] - x[i] * x[i]) * (x[i + 1] - x[i] * x[i]) + (1 - x[i]) * (1 - x[i]);
    }
    return fvalue;
    //return 100 * (x[1] - x[0] * x[0]) * (x[1] - x[0] * x[0]) + (1 - x[0]) * (1 - x[0]);
}

Vector RosenbrockFunction::grad(const Vector& x) const
{
    size_t d = dim();
    Vector g(d);
    g[0] = -400 * x[0] * (x[1] - x[0] * x[0]) + 2 * (x[0] - 1);
    g[d - 1] = 200 * (x[d - 1] - x[d - 2] * x[d - 2]);
    for (size_t i{ 1 }; i < d - 1; ++i) {
        g[i] = -400 * x[i] * (x[i + 1] - x[i] * x[i]) + 2 * (x[i] - 1) + 200 * (x[i] - x[i - 1] * x[i - 1]);
    }
    return g;
    //Vector g(2);
    //g[0] = 2 * (-1 + x[0] + 200 * x[0] * x[0] * x[0] - 200 * x[0] * x[1]);
    //g[1] = 200 * (x[1] - x[0] * x[0]);
    //return g;
}

const char* RosenbrockFunction::print_function() const
{
    char buffer[2000];
    sprintf_s(buffer, "f(x) = 100(x_2 - x_1^2)^2 + (1 - x_1)^2 + ... + 100(x_d - x_{d-1}^2)^2 + (1 - x_{d-1}), d = %zu", dim());
    return buffer;
}
