#include "StochasticOptimizer.h"

StochasticOptimizer::StochasticOptimizer(
	Function* _f,
	StopCriterion* _criterion,
	double _probability,
	double _delta,
	double _alpha,
	unsigned int seed
) :
	Optimizer(_f, _criterion),
	probability(_probability),
	delta(_delta),
	alpha(_alpha),
	generator(seed),
	distr(0., 1.)
{

}

StochasticOptimizer::~StochasticOptimizer()
{

}

void StochasticOptimizer::find_intersection()
{
	for (int i{}; i < neighbourhood.first.size(); ++i)
	{
		neighbourhood.first[i] = std::max(neighbourhood.first[i], cubic_domain.first[i]);
		neighbourhood.second[i] = std::min(neighbourhood.second[i], cubic_domain.second[i]);
	}
}

Vector StochasticOptimizer::random_point(const std::pair<Vector, Vector>& cubic_area)
{
	Vector point(cubic_area.first.size());
	for (int i{}; i < point.size(); ++i)
	{
		std::uniform_real_distribution<double> d(cubic_area.first[i], cubic_area.second[i]);
		point[i] = d(generator);
	}
	return point;
}

void StochasticOptimizer::next_point()
{
	Vector vdelta(current_point.size(), current_delta);
	neighbourhood.first = current_point - vdelta;
	neighbourhood.second = current_point + vdelta;
	find_intersection();
	Vector temp;
	if (distr(generator) < probability)
		temp = random_point(neighbourhood);
	else
		temp = random_point(cubic_domain);
	if (f->eval(temp) > f->eval(current_point))
		current_delta = delta;
	else
	{
		delta *= alpha;
		current_point = temp;
	}
}

