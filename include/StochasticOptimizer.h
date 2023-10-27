#pragma once
#include "Optimizer.h"
#include <random>
#include <chrono>

class StochasticOptimizer : public Optimizer
{
public:
	StochasticOptimizer(
		Function* f,
		StopCriterion* criterion,
		double _probability, double delta,
		double alpha = 1.,
		unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count()
	);
	~StochasticOptimizer();
private:
	Vector random_point(const RectArea& cubic_area);
	void next_point() override;
	double probability;
	double delta;
	double alpha;
	std::mt19937 generator;
	std::uniform_real_distribution<double> distr;
	double current_delta;
	RectArea neighbourhood;
};
