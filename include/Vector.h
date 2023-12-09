#pragma once
#include <vector>
#include <iostream>

/**
* The real-valued vector class 
*/
class Vector
{
public:
	Vector();

	Vector(size_t n);

	Vector(size_t n, double val);

	Vector(const std::initializer_list<double> list);

	Vector(const std::vector<double>& container);

	std::vector<double>::iterator begin();

	std::vector<double>::iterator end();

	void resize(size_t n);

	double& operator[](size_t i);

	const double& operator[](size_t i) const;

	size_t size() const;

	/**
	* Calculates the Euclidean norm of the vector
	* 
	* \return norm of the vector
	*/
	double norm() const;

	Vector& operator+=(const Vector& v);

	Vector& operator-=(const Vector& v);

	friend Vector operator+(const Vector& v1, const Vector& v2);

	friend Vector operator*(double alpha, const Vector& v);

	friend Vector operator/(const Vector& v, double alpha);

	friend Vector operator-(const Vector& v1, const Vector& v2);

	friend double operator*(const Vector& v1, const Vector& v2);

	friend std::ostream& operator<<(std::ostream& os, const Vector& v);

	friend std::istream& operator>>(std::istream& is, Vector& v);
private:
	std::vector<double> container;
};
