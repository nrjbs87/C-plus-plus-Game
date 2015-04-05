#include "Model.h"
#include "GameCommand.h"
//#include "InputHandling.h"
#include <string>
#include <fstream>
#include <typeinfo>
#include <iostream>
using namespace std;

void do_swim_command(Model& model)
{
	int id, x, y;
	cin >> id >> x >> y;
	Fish* F1 = model.get_Fish_ptr(id);
	F1->start_swimming(CartPoint(x, y));
}

void do_go_command(Model& model)
{
	cout << "Advancing by one tick." << endl;
	model.update();
}

void do_run_command(Model& model)
{
	for (int i = 0; i < 5; i++)
	{
		if (model.update())
			break;
	}

}

void do_float_command(Model& model)
{
	int id;
	cin >> id;
	Fish *F1 = model.get_Fish_ptr(id);
	F1->float_in_place();
}

void do_zoom_command(Model &model)
{
	int id_1;
	int id_2;
	cin >> id_1, id_2;
	Fish *F1 = model.get_Fish_ptr(id_1);
	Cave *C1 = model.get_Cave_ptr(id_2);
	F1->start_hiding(C1);
}

void do_eat_command(Model &model)
{
	int id_1, id_2;
	cin >> id_1 >> id_2;
	Fish *F1 = model.get_Fish_ptr(id_1);
	
	CoralReef* creef = model.get_CoralReef_ptr(id_2);
	F1->start_eating(creef);
}

void handle_new_command(Model* model)
{
	char type;
	int id, id_home;
	double x, y;

	cin >> type;
		//{
			//throw InvalidInput("Invalid Type ID");
		//}

	switch (type)
	{
		case 'R':
		{
			// ask for specific inputs here
			// pass inputs to new funciton in model
			// create an object then pass it to the add new object function

			cin >> id >> x >> y;
			//{
				//throw InvalidInput("Invalid input");
			//}
			//else
			//{
				
			 	model -> add_new_Object(model -> get_reef_input(id, x, y));
  			//}
		}
		case 'C':
		{
			cin >> id >> x >> y;
			//{
				//throw InvalidInput("Invalid input");
			//}
			//else
			//{
				model -> add_new_Object(model -> get_cave_input(id, x, y));
				
			//}
		}
		case 'T':
		{
			cin >> id >> id_home;
			//{
				//throw InvalidInput("Invalid input");
			//}
			//else
			//{
			 	model-> add_new_Object(model -> get_tuna_input(id, id_home));
			//}
		}
		case 'S':
		{
			cin >> id;
			//{
				//throw InvalidInput("Invalid input");
			//}
			//else
			//{
  				 model -> add_new_Object(model-> get_shark_input(id));
			//}
				
		}
	}
}
