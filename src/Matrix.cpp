#include "Matrix.h"

Matrix::Matrix()
{

}

Matrix::Matrix(size_t nrow, size_t ncol) : container(std::vector<Vector>(nrow, Vector(ncol)))
{

}

Matrix::Matrix(const std::vector<Vector>& container) : container(container)
{

}

size_t Matrix::size() const
{
	return container.size();
}

Vector& Matrix::operator()(size_t i)
{
	return container[i];
}

const Vector& Matrix::operator()(size_t i) const
{
	return container[i];
}

double& Matrix::operator()(size_t i, size_t j)
{
	return container[i][j];
}

const double& Matrix::operator()(size_t i, size_t j) const
{
	return container[i][j];
}

Matrix Matrix::inverse() const
{ 
	Matrix augmented(container);
	for (size_t i{}; i < augmented.size(); ++i)
	{
		augmented(i).resize(container[0].size() * 2);
		augmented(i, i + container[0].size()) = 1;
	}
	/*for (size_t i{ augmented.size() - 1 }; i > 0; --i)
	{
		if (augmented(i - 1, 0) < augmented(i, 0))
			std::swap(augmented(i - 1), augmented(i));
	}*/
	for (size_t i{}; i < augmented.size(); ++i)
	{
		for (size_t j{}; j < augmented.size(); ++j)
		{
			if (j != i)
			{
				augmented(j) -= augmented(j, i) / augmented(i, i) * augmented(i);
			}
		}
	}
	for (size_t i{}; i < augmented.size(); ++i)
	{
		augmented(i) = augmented(i) / augmented(i, i);
	}

	Matrix inv;
	for (size_t i{}; i < augmented.size(); ++i)
	{
		std::vector<double> temp(augmented(i).begin() + container[0].size(), augmented(i).end());
		inv.container.push_back(temp);
	}

	return inv;
}

Matrix operator*(double alpha, const Matrix& m)
{
	Matrix res(m);
	for (size_t i{}; i < m.size(); ++i)
	{
		res(i) = alpha * res(i);
	}
	return res;
}

Vector operator*(const Matrix& m, const Vector& v)
{
	Vector mult(v.size());
	for (size_t i{}; i < m.size(); ++i)
	{
		mult[i] = m(i) * v;
	}
	return mult;
}
