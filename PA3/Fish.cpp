#include "Fish.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "CoralReef.h"
#include "Cave.h"
#include<iostream>
#include<cmath>

Fish::Fish(char display_code , int size, Model* world):GameObject('F',0)
{
	state = 'h';
	energy = 15;
	size = 10;
	prefeast_size = size;
	destination = CartPoint() ;
	reef = NULL;
	home = NULL;
	cout << "Fish Default Constructed" << endl;
	my_world=world;
}

Fish::Fish(char display_code, int in_id, Cave* home, int size, Model* world) :GameObject(display_code,in_id, home -> get_location())
{
	state = 'h';
	energy = 15;
	size = 10;
	prefeast_size = size;
	destination = CartPoint();
	reef = NULL;
	this->home = home;
	home->hide_fish(this);
	location = home->get_location();
	cout << "Fish Constructed" << endl;
	my_world=world;
	//cout << location;
}

Fish::Fish(char display_code, int in_id, CartPoint location, int size, Model* world):GameObject(display_code,in_id,location)
{
	state = 'f';
	energy = 15;
	size = 10;
	prefeast_size = size;http://
	destination = CartPoint() ;
	reef = NULL;
	home = NULL;
	cout << "Fish Constructed" << endl;

}

void Fish::start_attack(Fish* frank)
{

cout<<"I cannot attack."<<endl;

}

void Fish::start_mating(Fish* frank)
{

cout<<"I cannot mate."<<endl;

}

void Fish::get_bitten(int attack_strength)
{
energy-=attack_strength;
	if (energy<=0)
	{
		state='x';
		cout<<"Oh no. I've become chum!"<<endl;
	}	
	
	else
	{
		cout<<"Ouch!"<<endl;
	}
}



Fish::~Fish()
{
	cout << "Fish destructed" << endl;
}


double Fish::get_size()
{
	return size;
}

double Fish::get_speed()
{
	speed = ((1 / size)*energy) * 5;
	return speed;
}

void Fish::setup_destination(CartPoint dest)//ASK ABOUT THIS
{
	destination = dest;
	speed = get_speed();
	delta = (destination - location) * (speed / cart_distance(destination, location));
}
bool Fish::update_location()
{
	if ((fabs(destination.x - location.x) <= fabs(delta.x)) && (fabs(destination.y - location.y) <= fabs(delta.y)))
	{
		location = destination;
		cout << display_code << get_id()<<": "<<"I'm here. " << endl;
		return true;
		
		
	}
	else
	{

		location = location + delta;
		cout << display_code << get_id()<< ": "<<"Just keep swimming." << endl;
		return false;
		
		
	}
}

void Fish::start_swimming(CartPoint Dest)
{
	setup_destination(Dest);
	state = 's';
	home->release_fish(this);
	cout << "Swimming " << get_id() << " to " << Dest << endl;
	cout << display_code << get_id() << ": On my way." << endl;
}

void Fish::start_eating(CoralReef* destReef)
{

	reef = destReef;
	setup_destination(destReef->get_location());

	state = 'o';
	home->release_fish(this);
	cout << "Fish " << get_id() << " eating at CoralReef " << destReef->get_id() << " and returning back to Cave " << home->get_id() << endl;
	cout << display_code << get_id() << ": Food here I come." << endl;
}

bool Fish::is_hidden()
{
	if (state == 'h')
		return true;
	else
		return false;
}

void Fish::start_hiding(Cave* destCave)
{
	CartPoint home = (destCave->get_location());
	setup_destination(home);
	state = 'z';
	cout << "Fish";
	cout << "Fish " << get_id() << " swimming to Cave " << destCave->get_id() << endl;
	cout << display_code << get_id() << ": Off to safety." << endl;
}

void Fish::float_in_place()
{
	state = 'f';
	cout << "Stopping " << get_id() << "." << endl;
	cout << display_code << get_id() << ": Resting my fins." << endl;
}



void Fish::show_status()
{
cout << "Fish Status: ";
GameObject::show_status();
	switch (state)
	{
		case 'f':
		{
			cout  << " Is floating. Has a size of: " << size << " and energy of: " << energy << endl;
		break;
		}

		case 's':
		{
			
			cout<< " has a speed of: " << get_speed() << " and is heading to " << destination << endl;
			break;
		}

		case 'o':
		{
			cout <<   " Is outbound to Reef: " << reef->get_id() << " with a speed of: " << get_speed() << "." << endl;
			break;
		}

		case 'e':
		{
			cout <<  " Is eating at Reef " << reef->get_id() << "." << endl;
			break;
		}

		case 'z':
		{
			cout << " Is swimming to Cave " << home->get_id() << " with a speed of " << get_speed() << "." << endl;
			break;
		}

		case 'p':
		{
			cout <<  " is panicked." << endl;
			break;
		}

		case'h':
		{
			cout << " is hidden in Cave "<< home->get_id()<<"."<<endl;
			break;
		}
	}

}

bool Fish::update()
{
switch (state)
{
	case 'f':
	{
		show_status();
		break;
	}

	case 's':
	{
		if (update_location() == true)
		{
			state = 'f';
			return true;
		}
		else
			return false;
		//show_status();
		break;
	}


	case 'o':
	{

		if (update_location())
		{
			state = 'e';
			prefeast_size = size;
			return true;
		}
		else
		{
			return false;
		}
		//show_status();
		break;
	}

	case 'e':
		
	{
		//double foodamount = reef -> reef_amount();
		//if (foodamount < prefeast_size)
		//{
			if (reef->is_empty())
			{
				state = 'f';
				cout << display_code << get_id() << ": This reef has no more food for me." << endl;
				return true;
			}
			else
			{
				size = size +  ((this ->reef)->provide_food());
				cout << display_code << get_id() << ": Grew to size " << size << "." << endl;
				if (size >= prefeast_size*2)
					{
						setup_destination(home->get_location());
						state = 'z';
						cout << display_code<< get_id() << ": I'm full. I'm heading home"<<endl;
						return true;
					}

					
			return false;
			}
	
		break;
	}

	case 'z':
	{
		if (update_location() == true)
		{
			bool result = (*home).Cave::hide_fish(this);

			if ((result) == true)
			{
				state = 'h';
				cout << display_code << get_id() << ": I am hidden and safe." << endl;
				return true;
			}
			else
			{
				state = 'p';
				cout << display_code << get_id() << ": Help! My home is full." << endl;
				return true;
			}
		}
		break;
	}

	case 'h':
	{	
		energy-=(energy/4);
		if (energy < 5)
		{
			state='x';
		}
		else
		{
			energy=energy;
		}
	break;
	}

	default:
	{
		return false;
		break;
	}
}
	
return false;
}

CartPoint Fish::home_getter(Fish* frank)
{

	CartPoint home_loc=(frank->home)->get_location();
	return home_loc;
}

CartPoint Fish::get_fish_home_loc()
{
	CartPoint home_location=(home -> get_location());
	return home_location;
}

Cave* Fish::get_fish_home()
{
	return home;
}

void Fish::set_fish_loc(CartPoint loc)
{
	this-> location = loc;
}
