
#include "GameObject.h"
#include "Model.h"


GameObject::GameObject(char in_code, int in_id)
{
	display_code=in_code;
	id_num=in_id;
	location = CartPoint(0,0);
	cout << "GameObject default constructed"<<endl;

}

GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
	display_code = in_code;
	id_num = in_id;
	location.x=in_loc.x;
	location.y = in_loc.y;
	cout << "GameObject constructed"<<endl;
}
GameObject::~GameObject()
{
	cout << "GameObject destructed" << endl;
}

CartPoint GameObject::get_location()
{
	return location;
}

int GameObject::get_id()
{
	return id_num;
}


void GameObject::show_status()
{
	cout << display_code << " with ID " << id_num << " at location " << get_location()<<" "; 

}

void GameObject::drawself(char* grid)
{
	grid[0] = display_code;
	grid[1] = (id_num+48);
}

char GameObject::get_state()
{
	return state;
}


/*void GameObject::save(ofstream& file)
{
 	file << display_code << endl;
	file << id_num << endl;
	file << state << endl;
}*/	

//void GameObject::restore(ifstream& file, Model* model)
//{
//}

