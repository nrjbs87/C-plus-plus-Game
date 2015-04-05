#include "Tuna.h"

Tuna::Tuna(Model* model):Fish('T', 10, model)
{
size=10;
}

Tuna::Tuna(int id, Cave* home, Model* model):Fish('T', id, home, 10, model)
{
size=10;
}

double Tuna::get_speed()
{
	speed=(1/size)* energy * 4;
	return speed;
}

bool Tuna::update()
{
if (((this -> state) == 'm') && checkflag)
	{
		if (mateTime < 2)
			{
				mateTime++;
			}
		else
			{
				(this->state) = 'h';
				(mate->state) = 'h';
				
				
			}

		return false;
	}

else if ((this -> state) == 'h')
	{
		start_mating(this);
	}
	else
	{
		Fish::update();
		return false;
	}
return false;
}



void Tuna::show_status()
{
	cout<< "Tuna Status";
	Fish::show_status();
	cout<<endl;
}

void Tuna::start_mating(Tuna* fish_mate)
{
	checkflag ="false";
	if (my_world -> find_a_mate_for(fish_mate))
	{
		(this->state) = 'm';
		(mate->state) = 'm';
		checkflag = "true";
		mateTime=0;
	}
	else
	state=state;
}

