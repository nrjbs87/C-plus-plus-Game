#include "Shark.h"
#include <ctime>
using namespace std;

Shark::Shark(Model* world):Fish('S', 20,world)
{
	attack_strength=2;
	range = 1;
	cout<<"Shark Default Constructed"<<endl; 
}

Shark::Shark(int in_id,Model* world):Fish('S', in_id, CartPoint(rand()%21, rand()%21), 20, world)
{
	srand((world ->get_time()));	
	attack_strength=2;
	range=1;
}
double Shark::get_speed()
{
	speed= (1/size) * energy * 8;
	return speed;
}

void Shark::start_attack(Fish* target)
{
	target -> get_bitten(attack_strength);
	CartPoint shark_loc=(this->get_location());
	CartPoint target_loc=(target ->get_location());
	distance_to_fish= cart_distance(shark_loc, target_loc);
	if (distance_to_fish <= range)
	{
		cout<<"Chomp"<<endl;
		this-> target = target;
		state = 'a';
	}
	else
		cout<<"Fish are friends, not food."<<endl;
}

bool Shark::update()
{
	switch(state)
	{
		case 'x':
		{
			return false;
			break;	
		}

		case 's':
		{
			return false;	
			break;
		}
		case 'e':
		{		

			double reefy = (reef->reef_amount());
			if (reefy < prefeast_size)
				{
					if(reef->is_empty())
					{	
						state='f';
						cout<<display_code<<get_id()<<"This reef has no more food for me..."<<endl;
						return true;
					}
					else 
					{
						size += (this ->reef)->provide_food();
						//state='z';
						setup_destination(home -> get_location ());
						cout<<display_code<<get_id()<<": I'm full. I'm heading home"<<endl;
						return false;
					}
				}	
			else 
			{
				size=prefeast_size +((this->reef) -> provide_food()/2);
				state='z';
				setup_destination(home->get_location());
				cout<<display_code<<get_id()<<" :I'm full. I'm heading home"<<endl;
				return true;
			}

		return true;
		break;
		}

		case'a':
		{
			CartPoint shark_loc = (this->get_location());
			CartPoint target_loc= (target -> get_location());

			distance_to_fish=cart_distance(shark_loc, target_loc);
			if (distance_to_fish>range)
			{		
				cout<<"Darn! It escaped."<<endl;
				(this->target) = NULL;
				(this->state) = 's';
				return true;
			}

			else
			{
				if ((target->get_state()) != 'x')
				{
					cout<<"I triumph!"<<endl;
					(this-> state) = 's';
					return true;
				}
				else 
				{
					cout<<"Chomp!"<<endl;	
					//target -> get_bitten(attack_strength);
					energy +=5;
					state = state;
					return false;
				}
			}
				

		}

	}	

}

void Shark::show_status()
{
	cout<<"Shark Status: ";
	Fish::show_status();
	cout<<endl;
}


