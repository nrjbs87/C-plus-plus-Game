#include "CoralReef.h"

	CoralReef::CoralReef() :GameObject('R', 0)
	{
		amount = 100;
		state = 'f';
		cout << "CoralReef default constructed"<<endl;
	}

	CoralReef::CoralReef(int in_id, CartPoint in_loc) : GameObject('R', in_id, in_loc)
	{
		amount = 100;
		state = 'f';
		cout << "CoralReef constructed"<<endl;
	}

	CoralReef::~CoralReef()
	{
		cout << "CoralReef destructed" << endl;
	}

	bool CoralReef::is_empty()
	{
		if (amount == 0)
		{
			return 1;
		}

		else
			return 0;
	}

	double CoralReef::reef_amount()
	{
		return amount;
	}
	double CoralReef::provide_food(double amount_to_provide)
	{
		if (amount >= amount_to_provide)
		{
			amount -= amount_to_provide;
			return amount_to_provide;
			
		}

		else
		{
			double temp = amount;
			amount = 0;
			return temp;
		}
	}

		bool CoralReef::update()
		{

			if (is_empty() && state!='e')
			{
				state = 'e';
				display_code = 'r';
				return true;
			}
			
			else
			{
				return false;
			}
		}

		void CoralReef::show_status()
		{
			cout << "CoralReef status : ";
			GameObject::show_status();
			cout<<" containing food " << amount << endl;
		}


