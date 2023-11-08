#include "Vector.h"

Vector::Vector()
{

}

Vector::Vector(size_t n) : container(std::vector<double>(n))
{

}

Vector::Vector(size_t n, double val) : container(std::vector<double>(n, val))
{

}

Vector::Vector(const std::initializer_list<double> list) : container(list)
{

}

Vector::Vector(const std::vector<double>& container) : container(container)
{

}

std::vector<double>::iterator Vector::begin()
{
	return container.begin();
}

std::vector<double>::iterator Vector::end()
{
	return container.end();
}

void Vector::resize(size_t n)
{
	container.resize(n);
}

double& Vector::operator[](size_t i)
{
	return container[i];
}

const double& Vector::operator[](size_t i) const
{
	return container[i];
}

size_t Vector::size() const
{
	return container.size();
}

double Vector::norm() const
{
	return *this * *this;
}

Vector& Vector::operator+=(const Vector& p)
{
	for (size_t i{}; i < container.size(); ++i)
	{
		container[i] += p.container[i];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& p)
{
	*this += -1 * p;
	return *this;
}

Vector operator+(const Vector& p1, const Vector& p2)
{
	Vector sum(p1);
	sum += p2;
	return sum;
}

Vector operator*(double alpha, const Vector& p)
{
	Vector res(p);
	for (size_t i{}; i < p.size(); ++i)
	{
		res[i] *= alpha;
	}
	return res;
}

Vector operator/(const Vector& v, double alpha)
{
	return 1 / alpha * v;
}

Vector operator-(const Vector& p1, const Vector& p2)
{
	return p1 + (-1 * p2);
}

double operator*(const Vector& v1, const Vector& v2)
{
	double dp{};
	for (size_t i{}; i < v1.size(); ++i)
	{
		dp += v1[i] * v2[i];
	}
	return dp;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << '(';
	for (size_t i{}; i < v.size() - 1; ++i) {
		os << v[i] << ", ";
	}
	os << v[v.size() - 1] << ')';
	return os;
}

