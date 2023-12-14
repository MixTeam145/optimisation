#include "RectArea.h"

RectArea::RectArea()
{

}

RectArea::RectArea(const VectorXd& min_point, const VectorXd& max_point) : min_point(min_point), max_point(max_point)
{

}

void RectArea::set_area(const VectorXd& new_min, const VectorXd& new_max)
{
	min_point = new_min;
	max_point = new_max;
}

RectArea RectArea::intersect(const RectArea& a)
{
	VectorXd new_min(min_point.size()),
		new_max(min_point.size());
	for (Index i = 0; i < a.min_point.size(); ++i)
	{
		new_min[i] = std::max(a.min_point[i], min_point[i]);
		new_max[i] = std::min(a.max_point[i], max_point[i]);
	}
	return RectArea(new_min, new_max);
}

size_t RectArea::dim() const
{
	return min_point.size();
}

bool RectArea::is_inside(const VectorXd& x) const
{
	for (Index i = 0; i < x.size(); ++i) {
		if (x[i] > max_point[i] || x[i] < min_point[i])
			return false;
	}
	return true;
}
