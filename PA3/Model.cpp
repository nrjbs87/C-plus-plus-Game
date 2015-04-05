#include "Model.h"

Model::Model()
{
  time = 0;

	reef_ptrs.push_back(new CoralReef(1,CartPoint(1, 20)));
	reef_ptrs.push_back(new CoralReef(2,CartPoint(20, 1)));
	reef_ptrs.push_back(new CoralReef(3,CartPoint(20, 20)));

	cave_ptrs.push_back(new Cave(1, CartPoint(5, 1)));
	cave_ptrs.push_back(new Cave(2, CartPoint(6, 2)));

	list<Cave*>::iterator a = cave_ptrs.begin();
		fish_ptrs.push_back(new Tuna(1, *a, this));
		a++;
		fish_ptrs.push_back(new Tuna(2, *a, this));
		fish_ptrs.push_back(new Tuna(3, *a, this));
		fish_ptrs.push_back(new Shark(4, this));
		fish_ptrs.push_back(new Shark(5, this));

	for (a = cave_ptrs.begin(); a != cave_ptrs.end(); a++)
	{
		object_ptrs.push_back(*a);
		active_ptrs.push_back(*a);
	}

	list<Fish*>::iterator b = fish_ptrs.begin();

	for (; b != fish_ptrs.end(); b++)
	{
		object_ptrs.push_back(*b);
		active_ptrs.push_back(*b);
	}

	list<CoralReef*>::iterator k = reef_ptrs.begin();
    
   	for (; k != reef_ptrs.end(); k++) 
 	{
      		object_ptrs.push_back(*k);
       	 	active_ptrs.push_back(*k);
    	}
  cout << "Model default constructed." << endl;
}

Model::~Model()
{
 list<GameObject*>::iterator i = object_ptrs.begin();
 for (; i != object_ptrs.end(); i++)
	{
		delete (*i);
	}		
  cout << "Model destructed." << endl;
}

Fish* Model::get_Fish_ptr(int id_num)
{
	list<Fish*>::iterator i = fish_ptrs.begin();

	for (; i != fish_ptrs.end(); i++)
	{
		if(((*i)-> get_id()) == id_num)
		{			
			return *i;
		}	
	}
	return NULL;
}

CoralReef* Model::get_CoralReef_ptr(int id_num)
{
	list<CoralReef*>::iterator i = reef_ptrs.begin();

	for (; i != reef_ptrs.end(); i++)
	{
		if ((*i) -> get_id() == id_num)
		{
			return *i;
		}
	}
	return NULL;
}


Cave* Model::get_Cave_ptr(int id_num)
{
	 list<Cave*>::iterator i = cave_ptrs.begin();

	for (; i != cave_ptrs.end(); i++)
	{
		if ((*i) -> get_id() == id_num)
		{
			return *i;
		}
	}
	return NULL;
}


bool Model::update()
{
	time=time+1;
	bool state_change = false;
	list<GameObject*>::iterator i = active_ptrs.begin();
	for (; i != active_ptrs.end(); i++)
	{
		if ((*i) -> update())
		{
			state_change = true;
		}
	}
	return state_change;
}

void Model::display(View& view)
{
	
	cout << "Time: " << time << endl;
	view.clear();
	list<GameObject*>::iterator i = active_ptrs.begin();
	for (; i != active_ptrs.end() ; i++)
	{
		view.plot(*i);
	}
	view.draw();
}

void Model::show_status()
{
	list<GameObject*>::iterator i = active_ptrs.begin();
	for (; i != active_ptrs.end(); i++)
	{
		(*i) -> GameObject::show_status();
		cout << endl;
	}
}

int Model::get_time()
{
	return time;
}
Tuna* Model::find_a_mate_for(Tuna* sandwhich)
{
	CartPoint sandwhich_home = (sandwhich -> get_fish_home_loc());
	double id_me = (sandwhich -> GameObject::get_id());
	double my_size = (sandwhich -> Fish::get_size());
	double cave_space= (sandwhich -> get_fish_home() -> get_space());

	list<Fish*>::iterator i = fish_ptrs.begin();

	for (; i != fish_ptrs.end(); i++)
	{
		Tuna* mate = dynamic_cast<Tuna*>(*i);
		if (mate != NULL)
		{
			if ((sandwhich_home.x==(mate->get_fish_home_loc()).x) && (cave_space >=10) && ((my_size>=40) && (my_size <=60)) && (((mate->get_size()) >= 40) && ((mate->get_size()) <= 60)) && (id_me !=(mate -> get_id())) && (cave_space == (100-my_size-(mate->get_size()))))
			{
				cout<<id_me<<": I found my mate!"<<endl;
				cout<<mate->get_id() << ": I found my mate!"<<endl;
				return mate;
			}

			else
			return NULL;
		}
		else 
		return NULL;
	}
}

void Model::make_baby_tuna(Tuna* tuna)
{
	int next_id = find_next_available_id();
	fish_ptrs.push_back(new Tuna(next_id, (tuna -> get_fish_home()), this));
	//cout << "Hello, World" << endl;
}

int Model::find_next_available_id()
{
	fish_ptrs.sort();
	list<Fish*>::iterator i = fish_ptrs.begin();

	if ((*i) -> get_id() != 1)
	{
		return 1;
	}
	else
	{
		for(; i != fish_ptrs.end(); i++)
		{
			if (i == --fish_ptrs.end())
			{
				return ((*(--i)) -> get_id() + 1);
			}
			else if ((*i) -> get_id() + 1 != (*(++i)) -> get_id())
			{
				return (*(--i)) ->get_id() +1;
				break;
			}

			i--;
		}
	}
	return 0;
}

//list getters
list<GameObject*> Model::getobject_ptrs()
{
	return object_ptrs;
}

list<GameObject*> Model::getactive_ptrs()
{
	return active_ptrs;
}

list<Fish*> Model::getfish_ptrs()
{
	return fish_ptrs;
}


list<Cave*> Model::getcave_ptrs()
{
	return cave_ptrs;
} 
 
list<CoralReef*> Model::getreef_ptrs()
{
	return reef_ptrs;
}

//place new object
void Model::add_new_Object(GameObject* result)
{
	object_ptrs.push_back(result);
	active_ptrs.push_back(result);
	if ((typeid(result) == typeid(Tuna*)))
	{
		Tuna* added = dynamic_cast<Tuna*>(result);
		fish_ptrs.push_back(added);
	}
	else if (typeid(result) == typeid(Shark*))
	{
		Shark* added = dynamic_cast<Shark*>(result);
		fish_ptrs.push_back(added);
	}
	else if (typeid(result) == typeid(Cave*))
	{
		Cave* added = dynamic_cast<Cave*>(result);
		cave_ptrs.push_back(added);
	}
	else if (typeid(result) == typeid(CoralReef*))
	{
		CoralReef* added = dynamic_cast<CoralReef*>(result);
		reef_ptrs.push_back(added);
	}
	
}

//input getters
CoralReef* Model::get_reef_input(int id, double x, double y)
{
	list<CoralReef*>::iterator i = reef_ptrs.begin();
	for (; i != reef_ptrs.end(); i++)
	{
		if ((id != (*i)-> get_id()) && (id <= 9))
		{
			CoralReef* result = new CoralReef(id,CartPoint(x, y));
			return result;
		}
	}
}

Cave* Model::get_cave_input(int id, double x, double y)
{
	list<Cave*>::iterator i = cave_ptrs.begin();
	for(; i!= cave_ptrs.end(); i++)
	{
		if ((id != (*i)-> get_id()) && (id <= 9))
		{
			Cave* result = new Cave(id, CartPoint(x, y));
			return result;
		}
	}
}

Tuna* Model::get_tuna_input(int id, int id_home)
{
	list<Fish*>::iterator i = fish_ptrs.begin();
	list<Cave*>::iterator j = cave_ptrs.begin();
	for(; i!= fish_ptrs.end(); i++)
	{
		if ((id != (*i)-> get_id()) && (id <= 9))
		{
			for (; j != cave_ptrs.end(); j++)
			{
				if (id_home == ((*j) -> get_id())) 
				{
					Tuna* result = new Tuna(id, *j , this);
					return result;
				}		
			}
		}
	}
}

Shark* Model::get_shark_input(int id)
{
	list<Fish*>::iterator i = fish_ptrs.begin();
	for(; i != fish_ptrs.end(); i++)
	{
		if ((id != (*i)-> get_id()) && (id <= 9))
		{
			Shark* result = new Shark(id, this);
			cout << "I think I made a shark" << endl;
			return result;
		}
	}
}

/*//save and load
void Model::save(ofstream& file)
{

}

void Model::restore(ifstream& file, Model* model)
{

}
*/
