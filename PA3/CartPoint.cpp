#include "CartPoint.h"
#include "CartVector.h"

CartPoint::CartPoint()
{
	x = 0.0;
	y = 0.0;
}

CartPoint::CartPoint(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

double cart_distance(CartPoint p1, CartPoint p2)
{
	double distance;
	distance = sqrt(((p1.x - p2.x)*(p1.x - p2.x)) + ((p1.y - p2.y)*(p1.y - p2.y)));
	return distance;
}

CartVector operator-(const CartPoint& p1, const CartPoint& p2)
{
	CartVector cv;
	cv.x = p1.x - p2.x;
	cv.y = p1.y - p2.y;
	return (cv);
}

CartPoint operator+(const CartPoint& p1, const CartVector& v1)
{
	CartPoint cp;
	cp.x = (p1.x + v1.x);
	cp.y = (p1.y + v1.y);
	return cp;
}

ostream& operator<< (ostream& out, const CartPoint& cp)
{
	out << "(" << cp.x << "," << cp.y << ")";
	return out;
}
