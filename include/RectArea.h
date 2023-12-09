#pragma once
#include "Vector.h"

/**
* The rectangular area class
*/
class RectArea
{
public:
	RectArea();
	
	/**
	* Constructs a RectArea object with given minimum and maximum points
	* 
	* \param min_point Minimum point
	* \param max_point Maximum point
	*/
	RectArea(const Vector& min_point, const Vector& max_point);

	/**
	* Sets the area with given minimum and maximum points
	* 
	* \param new_min New minimum point
	* \param new_max New maximum point
	*/
	void set_area(const Vector& new_min, const Vector& new_max);

	/**
	* Finds intersection with area a
	* 
	* \param a Rectangular area
	*/ 
	RectArea intersect(const RectArea& a);

	/**
	* Get area dimensionality
	*/
	size_t dim() const;

	/**
	* Checks if the given point is inside the area
	* 
	* \param x Point
	*/
	bool is_inside(const Vector& x) const;

	/**
	* Minimum point of the area
	*/
	Vector min_point;

	/**
	* Maximum point of the area
	*/
	Vector max_point;
};