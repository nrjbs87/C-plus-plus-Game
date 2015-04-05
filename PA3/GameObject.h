#include <iostream>
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "CartPoint.h"
//#include "Model.h"

class Model;

using namespace std;

class GameObject
{
private:
	int id_num;

protected:
	CartPoint location;
	char display_code;
	char state;

public:
	GameObject(char in_code, int in_id);
	GameObject(char in_code, int in_id, CartPoint in_loc);
	CartPoint get_location();
	int get_id();
	virtual void show_status();
	virtual bool update() = 0;
	virtual ~GameObject();
	void drawself(char*);
	char get_state();

	//saving functions
	//virtual void save(ofstream&);
	//virtual void restore(ifstream&, Model*);
};


//ostream& operator<< (ostream&, const CartVector&);

#endif

