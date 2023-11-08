#include <iostream>
#include "DeterministicOptimizer.h"
#include "StochasticOptimizer.h"
#include "BoothFunction.h"
#include "McCormickFunction.h"
#include "RosenbrockFunction.h"
#include "AbsValueSC.h"
#include "NumIterSC.h"

int main()
{
	std::cout << "Deterministic optimization:\n\n";

	Function* f = new McCormickFunction;
	f->print_function();
	StopCriterion* criterion = new AbsValueSC(1e+4, 1e-4);
	Optimizer* optim = new DeterministicOptimizer(f, criterion);
	optim->set_domain({ -1.5, -3 }, {4, 4});
	optim->optimize({-1, 0.5});
	std::vector<Vector> traj = optim->get_trajectory();
	std::cout << "Number of iterations: " << traj.size() - 1<<
		"\nApproximate local mimimum: " << traj.back() <<
		"\nFunction value: " << f->eval(traj.back()) << "\n\n";

	delete f;

	f = new BoothFunction;
	f->print_function();
	optim->set_f(f);
	optim->set_domain({-10, -10}, {10, 10});
	optim->optimize({-10, -10});
	traj = optim->get_trajectory();
	std::cout << "Number of iterations: " << traj.size() - 1 <<
		"\nApproximate local mimimum: " << traj.back() <<
		"\nFunction value: " << f->eval(traj.back()) << "\n\n";

	delete f;

	f = new RosenbrockFunction(3);
	f->print_function();
	optim->set_f(f);
	optim->set_domain({-1.5, -1.5, -1.5}, {1.5, 1.5, 1.5});
	optim->optimize({-1, -1, -1});
	traj = optim->get_trajectory();
	std::cout << "Number of iterations: " << traj.size() - 1 <<
		"\nApproximate local mimimum: " << traj.back() <<
		"\nFunction value: " << f->eval(traj.back()) << "\n\n";

	delete optim;

	std::cout << "Stochastic optimization:\n\n";

	delete f;

	f = new RosenbrockFunction;
	f->print_function();
	optim = new StochasticOptimizer(f, criterion, 0.4, 2, 0.5, 0);
	optim->set_domain({ -1.5, -1.5 }, { 1.5, 1.5 });
	optim->optimize({ -1, -1 });
	traj = optim->get_trajectory();
	std::cout << "Number of iterations: " << traj.size() - 1 <<
		"\nApproximate local mimimum: " << traj.back() <<
		"\nFunction value: " << f->eval(traj.back()) << '\n';

	return 0;
}
