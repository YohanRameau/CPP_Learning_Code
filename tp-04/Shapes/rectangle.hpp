#pragma once

#include <array>
#include "point.hpp"
#include "shape.hpp"
#include "line.hpp"
#include "line_seg.hpp"

class Rectangle : public Shape
{
	Point lower_left, upper_right;

public:
	Rectangle(const Point &p1, const Point &p2) : lower_left{p1}, upper_right{p2}
	{
		if (lower_left.x > upper_right.x)
			std::swap(lower_left.x, upper_right.x);
		if (lower_left.y > upper_right.y)
			std::swap(lower_left.y, upper_right.y);
	}

	std::ostream &print(std::ostream &os) const override
	{
		return os << "rectangle " << lower_left << " & " << upper_right << std::endl;
	}

	bool point_is_inside(const Point &p) const
	{
		return (p.x >= lower_left.x) && (p.x <= upper_right.x) && (p.y >= lower_left.y) && (p.y <= upper_right.y);
	}

	void filter_points_inside(PointContainer &points) const
	{
		for (auto iter = points.begin(); iter != points.end();)
		{
			if (point_is_inside(*iter))
			{
				++iter;
			}
			else
			{
				iter = points.erase(iter);
			}
		}
	}

	std::array<LineSegment, 4> get_border() const
	{
		return {LineSegment{upper_right, {lower_left.x, upper_right.y}},
				LineSegment{lower_left, {upper_right.x, lower_left.y}},
				LineSegment{upper_right, {upper_right.x, lower_left.y}},
				LineSegment{lower_left, {lower_left.x, upper_right.y}}};
	}

	PointContainer intersect(const Shape &other) const override
	{
		PointContainer result;
		for (const LineSegment &ls : get_border())
		{
			result.merge(ls.intersect(other));
		}
		return result;
	}

	PointContainer intersect(const LineSegment &ln) const
	{

		auto ln_pts = ln.get_points();
		PointContainer pts_ctnr = PointContainer{ln_pts.first, ln_pts.second};
		filter_points_inside(pts_ctnr);
		if (point_is_inside(ln_pts.first) && point_is_inside(ln_pts.second))
		{
			return {};
		}
		if (pts_ctnr.size() == 1)
		{

			PointContainer result;
			auto inside_pts = pts_ctnr.front();
			auto outside_pts = ln_pts.first == inside_pts ? ln_pts.second : ln_pts.first;
			if (outside_pts < lower_left)
			{
				if (outside_pts.y < lower_left.y)
				{
					std::array<LineSegment, 2> potential_seg
					{
						LineSegment{lower_left, {upper_right.x, lower_left.y}},
						LineSegment{lower_left, {lower_left.x, upper_right.y}}
					};
					for (const LineSegment &ls : potential_seg)
					{
						result.merge(ls.intersect(ln));
					}
					
					return result;
				}
				else
				{
					std::array<LineSegment, 2> potential_seg
					{
						LineSegment{upper_right, {lower_left.x, upper_right.y}},
						LineSegment{lower_left, {lower_left.x, upper_right.y}}
					};
					for (const LineSegment &ls : potential_seg)
					{
						result.merge(ls.intersect(ln));
					}
					
					return result;
				}
			}
			else{
				if (outside_pts.y < lower_left.y)
				{
					std::array<LineSegment, 2> potential_seg
					{
						LineSegment{lower_left, {upper_right.x, lower_left.y}},
						LineSegment{upper_right, {upper_right.x, lower_left.y}}
					};
					for (const LineSegment &ls : potential_seg)
					{
						result.merge(ls.intersect(ln));
					}
					
					return result;
				}
				else
				{
					std::array<LineSegment, 2> potential_seg
					{
						LineSegment{upper_right, {lower_left.x, upper_right.y}},
						LineSegment{upper_right, {upper_right.x, lower_left.y}}
					};
					for (const LineSegment &ls : potential_seg)
					{
						result.merge(ls.intersect(ln));
					}
					
					return result;
				}
			}
		}

		// transform linesegment to line, to use intersect with a line.
		Line l = ln;
		return intersect(l);
	}

	PointContainer intersect(const Line &ln) const override
	{
		PointContainer result;
		for (const LineSegment &ls : get_border())
		{
			result.merge(ls.intersect(ln));
		}
		return result;
	}

	~Rectangle() = default;
};
