#pragma once
#include <vector>

class Vector
{
public:
	Vector();
	Vector(size_t n);
	Vector(size_t n, double val);
	Vector(const std::initializer_list<double> _list);
	Vector(const std::vector<double>& _container);
	std::vector<double>::iterator begin();
	std::vector<double>::iterator end();
	void resize(size_t n);
	double& operator[](size_t i);
	const double& operator[](size_t i) const;
	size_t size() const;
	double norm() const;
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	friend Vector operator+(const Vector& v1, const Vector& v2);
	friend Vector operator*(double alpha, const Vector& v);
	friend Vector operator/(const Vector& v, double alpha);
	friend Vector operator-(const Vector& v1, const Vector& v2);
	friend double operator*(const Vector& v1, const Vector& v2);
private:
	std::vector<double> container;
};
