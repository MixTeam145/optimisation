#pragma once
#include "Optimizer.h"
#include <random>
#include <chrono>

/**
* The stochastic optimizer class
*/
class StochasticOptimizer : public Optimizer
{
public:
	/**
	* Constructs a StochasticOptimizer object with given Function, StopCriterion, and other parameters
	*
	* \param f Objective function
	* \param criterion Stop criterion
	* \param probability Probability of getting into the neighborhood
	* \param delta Initial radius of the neibourhood
	* \param alpha Radius reduction coefficient
	* \param seed Seed
	*/
	StochasticOptimizer(
		Function* f,
		StopCriterion* criterion,
		double probability, double delta,
		double alpha = 1.,
		unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count()
	);

	~StochasticOptimizer();

	void set_seed(unsigned int new_seed) { generator.seed(new_seed); }
private:
	/**
	* Generates a uniformly distributed point in given area
	* 
	* \param cubic_area Range of the random variable
	*/
	VectorXd random_point(const RectArea& cubic_area);

	/**
	* Calculates the next approximation
	*/
	void next_point() override;

	/**
	* Neighbourhood of current approximation
	*/
	RectArea neighbourhood;

	/**
	* Probability of getting into the neighborhood
	*/
	double probability;

	/**
	* Initial radius of the neibourhood
	*/
	double delta;

	/**
	* Current radius of the neibourhood
	*/
	double current_delta;

	/**
	* Radius reduction coefficient
	*/
	double alpha;

	std::mt19937 generator;

	std::uniform_real_distribution<double> distr;
};
