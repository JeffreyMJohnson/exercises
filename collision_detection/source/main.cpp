
#include "glm/glm.hpp"

typedef glm::vec2 vec;
/*
Uses formula for 2 lines and solves for the point where they cross.
*/
bool LineLine(vec p1, vec p2, vec p3, vec p4, vec& crossPoint)
{
	/*
	line equation-> L = p1 + t(p2 - p1);
	L -> the line
	p1, p2 -> end points of the line
	t -> value from 0 - 1 across the line
	
	using 2 lines p1-p2, p3-p4:
	L(a) = p1 + t(a)(p2 - p1)
	L(b) = p3 + t(b)(p4 - p3)

	set lines equal to eachother
	p1 + t(a)(p2 - p1) = p3 + t(b)(p4 - p3)

	solve for t(a) and t(b) to find crossover point
	split formulas into one for x and one for y (and one for z in 3d)
	x1 + t(a)(x2 - x1) = x3 + t(b)(x4 - x3)
	y1 + t(a)(y2 - y1) = y3 + t(b)(y4 - y3)

	solve for t(a) and t(b)
	t(a) = [(x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)] / [(y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1)]
	t(b) = [(x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)] / [(y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1)]

	NOTE: if denom = 0 then lines are parallel and never cross.
	otherwise, if t(a) and t(b) are both between 0 - 1, then the lines are crossing.
	*/

	//check if lines parallel
	if ((((p4.y - p3.y) * (p2.x - p1.x)) - ((p4.x - p3.x) * (p2.y - p1.y))) == 0)
	{
		return false;
	}

	float tA = (((p4.x - p3.x) * (p1.y - p3.y)) - ((p4.y - p3.y) * (p1.x - p3.x))) / (((p4.y - p3.y) * (p2.x - p1.x)) - ((p4.x - p3.x) * (p2.y - p1.y)));
	float tB = (((p2.x - p1.x) * (p1.y - p3.y)) - ((p2.y - p1.y) * (p1.x - p3.x))) / (((p4.y - p3.y) * (p2.x - p1.x)) - ((p4.x - p3.x) * (p2.y - p1.y)));

	if ((tA >= 0 && tA <= 1) && (tB >= 0 && tB <= 1))
	{
		crossPoint = p1 + tA * (p2 - p1);
		return true;
	}
	return false;
}


int main()
{
	vec p1 = vec(0, 0);
	vec p2 = vec(10, 10);

	vec p3 = vec(0,10);
	vec p4 = vec(10,0);

	vec xPoint;

	bool cross = LineLine(p1, p2, p3, p4, xPoint);

	return 0;
}