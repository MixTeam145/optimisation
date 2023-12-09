#pragma once
#include "Vector.h"

/**
* The real-valued matrix class
*/
class Matrix
{
public:
	Matrix();

	Matrix(size_t nrow, size_t ncol);

	Matrix(const std::vector<Vector>& container);

	size_t size() const;

	Vector& operator()(size_t i);

	const Vector& operator()(size_t i) const;

	double& operator()(size_t i, size_t j);

	const double& operator()(size_t i, size_t j) const;

	/**
	* Computes the inverse matrix using Gaussian elimination
	*/
	Matrix inverse() const;

	friend Matrix operator*(double alpha, const Matrix& m);

	friend Vector operator*(const Matrix& m, const Vector& v);
private:
	std::vector<Vector> container;
};

