#ifndef CART_VECTOR_H
#define CART_VECTOR_H
#include "math.h"
#include <iostream>
using namespace std;

class CartVector
{
public:
	double x, y;
	CartVector();
	CartVector(double in_x, double in_y);
};

CartVector operator*(const CartVector&, double);
CartVector operator/(const CartVector&, double);
ostream& operator<< (ostream&, const CartVector&);

#endif
