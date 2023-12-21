#include <iostream>
#include <string>
#include "DeterministicOptimizer.h"
#include "StochasticOptimizer.h"
#include "BoothFunction.h"
#include "McCormickFunction.h"
#include "RosenbrockFunction.h"
#include "AbsValueSC.h"
#include "NumIterSC.h"

int main()
{
	std::cout << "Optimization program by Egor Poteshkin\n";

	std::string choise;
	do {
		std::cout << "\nSelect optimization function:\n"
			<< "1. McCormick function (2-dimentional)\n"
			<< "2. Booth function (2-dimentional)\n"
			<< "3. Rosenbrock function (arbitrary dimention)\n"
			<< "> ";
		int key;
		Function* f = nullptr;
		do {
			std::cin >> key;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			switch (key)
			{
			case 1:
				f = new McCormickFunction();
				break;
			case 2:
				f = new BoothFunction();
				break;
			case 3:
				std::cout << "Enter function's dimentionality\n> ";
				int dim;
				do {
					std::cin >> dim;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (dim <= 0)
						std::cout << "Incorrect dimentionality (must be > 0)\n> ";
				} while (dim <= 0);
				f = new RosenbrockFunction(dim);
				break;
			default:
				std::cout << "Incorrect option (must be 1, 2 or 3)\n> ";
				break;
			}

		} while (key != 1 && key != 2 && key != 3);

		std::cout << "Select stop criterion:\n"
			<< "1. Abs value of the gradient\n"
			<< "2. Number of iterations\n"
			<< "< ";
		StopCriterion* criterion = nullptr;
		do {
			std::cin >> key;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (key != 1 && key != 2)
				std::cout << "Incorrect option (must be 1 or 2)\n> ";
		} while (key != 1 && key != 2);

		std::cout << "Enter number of iterations\n> ";
		int niter;
		do {
			std::cin >> niter;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (niter < 0)
				std::cout << "Incorrect number of iterations (must be >= 0)\n> ";
		} while (niter < 0);
		switch (key)
		{
		case 1:
			std::cout << "Enter precision\n> ";
			double eps;
			do {
				std::cin >> eps;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (eps <= 0)
					std::cout << "Incorrect precision (must be > 0)\n> ";
			} while (eps <= 0);
			criterion = new AbsValueSC(niter, eps);
			break;
		case 2:
			criterion = new NumIterSC(niter);
			break;
		}

		std::cout << "Select optimizer type:\n"
			<< "1. Deterministic\n"
			<< "2. Stochastic\n"
			<< "> ";
		Optimizer* optimizer = nullptr;
		do {
			std::cin >> key;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			switch (key)
			{
			case 1:
				optimizer = new DeterministicOptimizer(f, criterion);
				break;
			case 2:
				std::cout << "Enter probability of getting into the neighborhood\n> ";
				double prob;
				do {
					std::cin >> prob;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (prob < 0 || prob > 1)
						std::cout << "Incorrect probability (must be >= 0 and <= 1)\n> ";
				} while (prob < 0 || prob > 1);
				std::cout << "Enter initial radius of the neibourhood\n> ";
				double radius;
				do {
					std::cin >> radius;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (radius <= 0)
						std::cout << "Incorrect radius (must be > 0)\n> ";
				} while (radius <= 0);
				std::cout << "Enter radius reduction coefficient\n> ";
				double coeff;
				do {
					std::cin >> coeff;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (coeff <= 0 || coeff > 1)
						std::cout << "Incorrect coefficient (must be > 0 and <= 1)\n> ";
				} while (coeff <= 0 || coeff > 1);
				std::cout << "Enter seed\n> ";
				int seed;
				do {
					std::cin >> seed;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (seed < 0)
						std::cout << "Incorrect seed (must be >= 0)\n> ";
				} while (seed < 0);
				optimizer = new StochasticOptimizer(f, criterion, prob, radius, coeff, seed);
				break;
			default:
				std::cout << "Incorrect option (must be 1 or 2)\n> ";
				break;
			}
		} while (key != 1 && key != 2);

		std::cout << "Enter cubic domain of the function (" << f->get_dim() << "-dimentional)\n";
		VectorXd min_point(f->get_dim()), max_point(f->get_dim());
		std::cout << "Min point\n> ";
		for (Index i = 0; i < min_point.size(); ++i)
			std::cin >> min_point[i];
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Max point\n> ";
		for (Index i = 0; i < max_point.size(); ++i)
			std::cin >> max_point[i];
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		optimizer->set_domain(min_point, max_point);

		std::cout << "Enter start point (" << f->get_dim() << "-dimentional)\n> ";
		VectorXd start_point(f->get_dim());
		for (Index i = 0; i < start_point.size(); ++i)
			std::cin >> start_point[i];
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		optimizer->optimize(start_point);

		std::vector<VectorXd> traj = optimizer->get_trajectory();
		const IOFormat fmt(StreamPrecision, 0, ", ", ", ", "", "", "(", ")");
		std::cout << "Number of iterations: " << traj.size() - 1 <<
			"\nApproximate local mimimum: " << traj.back().format(fmt) <<
			"\nFunction value: " << f->eval(traj.back()) << "\n\n";

		delete optimizer;
		delete criterion;
		delete f;

		std::cout << "Want to test a different function? [Y/N]\n> ";
		do {
			std::getline(std::cin, choise);
			if (choise.compare("Y") && choise.compare("N"))
				std::cout << "Incorrect option (must be Y or N)\n> ";
		} while (choise.compare("Y") && choise.compare("N"));

	} while (choise.compare("N"));
	return 0;
}
