#include "StochasticOptimizer.h"

StochasticOptimizer::StochasticOptimizer(
	Function* f,
	StopCriterion* criterion,
	double probability,
	double delta,
	double alpha,
	unsigned int seed
) :
	Optimizer(f, criterion),
	probability(probability),
	delta(delta),
	current_delta(delta),
	alpha(alpha),
	generator(seed),
	distr(0., 1.)
{

}

StochasticOptimizer::~StochasticOptimizer()
{

}

VectorXd StochasticOptimizer::random_point(const RectArea& cubic_area)
{
	VectorXd res(cubic_area.dim());
	for (int i{}; i < res.size(); ++i)
	{
		std::uniform_real_distribution<double> d(cubic_area.min_point[i], cubic_area.max_point[i]);
		res[i] = d(generator);
	}
	return res;
}

void StochasticOptimizer::next_point()
{
	VectorXd vdelta = Eigen::VectorXd::Constant(current_point.size(), current_delta);
	neighbourhood.set_area(current_point - vdelta, current_point + vdelta);
	neighbourhood = domain.intersect(neighbourhood);
	VectorXd temp;
	if (distr(generator) < probability)
		temp = random_point(neighbourhood);
	else
		temp = random_point(domain);
	if (f->eval(temp) > f->eval(current_point))
		current_delta = delta;
	else
	{
		delta *= alpha;
		current_point = temp;
	}
}

