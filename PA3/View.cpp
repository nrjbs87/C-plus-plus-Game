#include <iostream>
#include "View.h"
#include "CartPoint.h"
#include "GameCommand.h"
#include "GameObject.h"
using namespace std;

View::View()
{
	size = 11;
	scale = 2;
	origin = CartPoint(0, 0);
}

void View::clear()
{
	for (int i = 0; i < view_maxsize; i++)
	{
		for (int j = 0; j < view_maxsize; j++)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';

		}
	}

}

bool View::get_subscripts(int& x, int& y, CartPoint location)
{
	x = (location.x - origin.x) / scale;
	y = (location.y - origin.y) / scale;

	if (((x <= view_maxsize) && x >= 0) && ((y <= view_maxsize) && y >= 0))
	{
		return true;
	}
	else
	{
		cout << "An object is outside the display" << endl;
		return false;
	}
}

void View::plot(GameObject* ptr)
{
int x, y;
	if (get_subscripts(x, y, ptr->get_location()))
	{
		if (grid[x][y][0] != '.')
		{
		grid[x][y][0] = '*';
		grid[x][y][1] = ' ';
		}
		else
		{
			ptr->drawself(grid[x][y]);
		}
    }

}

void View::draw()
{
	for (int i = size-1; i >=0; i--)//i=y
	{
		if ((i * 2) % 4 == 0)
		{
			if ((i * 2) > 9)
			{
				cout << i * 2;
			}
			else
			{
				cout << (i * 2)<<" ";
			}
		}
		else
		{
			cout << "  ";
		}
		for (int j = 0; j < size; j++)
		{
			cout << grid[j][i][0];
			cout << grid[j][i][1];
			
		}
		cout << endl;
	}

	cout << "  0   4   8   12  16  20"<<endl;
		
}
