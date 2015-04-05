#include "CartVector.h"
#include "CartPoint.h"


CartVector::CartVector()
{
	x = 0.0;
	y = 0.0;
}

CartVector::CartVector(const double in_x, const double in_y)
{
	x = in_x;
	y = in_y;
}

CartVector operator*(const CartVector& v1, double d)
{
	CartVector cv;
	cv.x = v1.x*d;
	cv.y = v1.y*d;
	return cv;
}

CartVector operator/(const CartVector& v1, double d)
{
	CartVector cv;
	cv.x = v1.x / d;
	cv.y = v1.y / d;
	return cv;

}

ostream& operator<< (ostream& out, const CartVector& cp)
{
	out << "<" << cp.x << "," << cp.y << ">";
	return out;
}
