#include "Cave.h"

Cave::Cave() :GameObject('c',0)
{
	state = 'e';
	space = 100;
}
Cave::Cave(int in_id, CartPoint in_loc) : GameObject('c', in_id, in_loc)
{
	state = 'c';
	cout << "Cave Constructed"<<endl;
	space = 100;
}

Cave::~Cave()
{
	cout << "Cave destructed" << endl;
}

bool Cave::hide_fish(Fish* fish_to_hide)
{
	if ((space >= fish_to_hide->get_size()) && state != 'h')
	{
		space -= fish_to_hide->get_size();
		return true;

	}

	else
	{
		return false;
	}
}

bool Cave::release_fish(Fish* fish_to_release)//WHAT STATE SHOULD THIS BE SET TO?
{
	if (state != 'h')
	{
		space += fish_to_release->get_size();
		return true;

	}

	else
	{
		return false;
	}
}

bool Cave::update()
{
	if ((space <= 0) && (state != 'p'))
	{
		state = 'p';
		display_code = 'c';
		cout << "Cave " << get_id() << " is packed.";
		return true;
	}
	else if ((space > 0) && (state = 'p'))
	{
		state = '\0';
		return true;
	}

	else
	{
		return false;
	}
}

void Cave::show_status()
{
	cout << "Cave status ";
	GameObject::show_status();
	cout << "with a space of " << space<<endl;
}

double Cave::get_space()
{
	return space;
}
