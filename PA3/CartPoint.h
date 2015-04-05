#ifndef CART_POINT_H  
#define CART_POINT_H
#include <iostream>
#include "CartVector.h"
#include "math.h"
using namespace std;

//CartPoint Class
class CartPoint
{
public:
	double x, y;
	CartPoint();
	CartPoint(double in_x, double in_y);
};

double cart_distance(CartPoint p1, CartPoint p2);
CartVector operator- (const CartPoint&, const CartPoint&);
CartPoint operator+ (const CartPoint&, const CartVector&);
ostream& operator<< (ostream&, const CartPoint&);

#endif
