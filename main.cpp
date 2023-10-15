#include <iostream>
#include "Optimizer.h"
#include "DeterministicOptimizer.h"
#include "BoothFunction.h"
#include "McCormickFunction.h"
#include "RosenbrockFunction.h"
#include "AbsValueSC.h"
#include "NumIterSC.h"

using Eigen::Vector2d;
 
int main()
{
	Function* f = new McCormickFunction;
	std::cout << f->print_function() << '\n';
	StopCriterion* criterion = new AbsValueSC();
	Optimizer* optim = new DeterministicOptimizer(f, criterion);
	Vector2d a(-1.5, -3), b(4, 4);
	optim->set_cubic_domain(a, b);
	Vector2d p(-1, 0.5);
	optim->optimize(p);
	std::vector<VectorXd> traj = optim->get_trajectory();
	std::cout << "Number of iterations: " << traj.size() - 1<<
		"\nApproximate local mimimum: (" << traj.back()[0] << ", " << traj.back()[1] << ")" <<
		"\nFunction value: " << f->eval(traj.back()) << "\n\n";

	delete f;

	f = new BoothFunction;
	std::cout << f->print_function() << '\n';
	optim->set_f(f);
	a << -10, -10;
	b << 10, 10;
	optim->set_cubic_domain(a, b);
	p << -10, -10;
	optim->optimize(p);
	traj = optim->get_trajectory();
	std::cout << "Number of iterations: " << traj.size() - 1 <<
		"\nApproximate local mimimum: (" << traj.back()[0] << ", " << traj.back()[1] << ")" <<
		"\nFunction value: " << f->eval(traj.back()) << "\n\n";

	delete f;

	f = new RosenbrockFunction;
	std::cout << f->print_function() << '\n';
	optim->set_f(f);
	a << -1.5, -1.5;
	b << 1.5, 1.5;
	optim->set_cubic_domain(a, b);
	p << -1, -1;
	optim->optimize(p);
	traj = optim->get_trajectory();
	std::cout << "Number of iterations: " << traj.size() - 1 <<
		"\nApproximate local mimimum: (" << traj.back()[0] << ", " << traj.back()[1] << ")" <<
		"\nFunction value: " << f->eval(traj.back()) << '\n';
}
