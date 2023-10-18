#pragma once
#include "Optimizer.h"
#include <random>
#include <chrono>

class StochasticOptimizer : public Optimizer
{
public:
	StochasticOptimizer(
		Function* _f,
		StopCriterion* _criterion,
		double _probability, double _delta,
		double _alpha = 1.,
		unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count()
	);
	~StochasticOptimizer();
private:
	void find_intersection();
	Vector random_point(const std::pair<Vector, Vector>& cubic_area);
	void next_point() override;
	double probability;
	double delta;
	double alpha;
	std::mt19937 generator;
	std::uniform_real_distribution<double> distr;
	double current_delta;
	std::pair<Vector, Vector> neighbourhood;
};

