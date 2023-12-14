#include "McCormickFunction.h"

McCormickFunction::McCormickFunction() : Function(2)
{

}

McCormickFunction::~McCormickFunction()
{

}

double McCormickFunction::eval(const VectorXd& x) const
{
	return sin(x[0] + x[1]) + (x[0] - x[1]) * (x[0] - x[1]) - 1.5 * x[0] + 2.5 * x[1] + 1;
}

VectorXd McCormickFunction::grad(const VectorXd& x) const
{
	VectorXd g(2);
	g[0] = -1.5 + 2 * x[0] - 2 * x[1] + cos(x[0] + x[1]);
	g[1] = 2.5 - 2 * x[0] + 2 * x[1] + cos(x[0] + x[1]);
	return g;
}

void McCormickFunction::print_function(std::ostream& os) const
{
	os << "f(x,y) = sin(x + y) + (x - y)^2 - 1.5x + 2.5y + 1\n";
}
