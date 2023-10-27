#pragma once
#include "Vector.h"

class RectArea
{
public:
	RectArea();
	RectArea(const Vector& min_point, const Vector& max_point);
	void set_area(const Vector& new_min, const Vector& new_max);
	RectArea intersect(const RectArea& a);
	size_t dim() const;
	Vector min_point;
	Vector max_point;
};