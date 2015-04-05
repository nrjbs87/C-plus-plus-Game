#ifndef VIEW_H
#define VIEW_H
#include "GameObject.h"

#include <iostream>
using namespace std;

const int view_maxsize = 20;

class View
{
public:
	View();
	void clear();
	void plot(GameObject*);
	void draw();

private:
	int size;
	double scale;
	CartPoint origin;
	char grid[view_maxsize][view_maxsize][2];
	bool get_subscripts(int &ix, int &iy, CartPoint location);

};

#endif
