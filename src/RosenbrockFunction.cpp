#include "RosenbrockFunction.h"

RosenbrockFunction::RosenbrockFunction(size_t d) : Function(d)
{

}

RosenbrockFunction::~RosenbrockFunction()
{

}

double RosenbrockFunction::eval(const VectorXd& x) const
{
    double fvalue = 0;
    for (size_t i = 0; i < dim - 1; ++i) {
        fvalue += 100 * (x[i + 1] - x[i] * x[i]) * (x[i + 1] - x[i] * x[i]) + (1 - x[i]) * (1 - x[i]);
    }
    return fvalue;
}

VectorXd RosenbrockFunction::grad(const VectorXd& x) const
{
    VectorXd g(dim);
    g[0] = -400 * x[0] * (x[1] - x[0] * x[0]) + 2 * (x[0] - 1);
    g[dim - 1] = 200 * (x[dim - 1] - x[dim - 2] * x[dim - 2]);
    for (size_t i = 1; i < dim - 1; ++i) {
        g[i] = -400 * x[i] * (x[i + 1] - x[i] * x[i]) + 2 * (x[i] - 1) + 200 * (x[i] - x[i - 1] * x[i - 1]);
    }
    return g;
}

void RosenbrockFunction::print_function(std::ostream& os) const
{
    size_t d = get_dim();
    os << "f(x) = 100(x_2 - x_1^2)^2 + (1 - x_1)^2 + ... + 100(x_" << d <<" - x_" << d - 1 << "^2)^2 + (1 - x_" << d - 1 <<")\n";
}
