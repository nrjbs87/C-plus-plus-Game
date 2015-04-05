
#ifndef CAVE_H 
#define CAVE_H
#include <iostream>
#include "GameObject.h"
#include "Fish.h"
using namespace std;

class GameObject;
class Fish;

class Cave : public GameObject
{
private:
	double space;
public: 
	char display_code;
	char state;
	Cave();
	Cave(int in_id, CartPoint in_loc);
	bool hide_fish(Fish* fish_to_hide);
	bool release_fish(Fish* fish_to_release);
	bool update();
	void show_status();
	//getter for space
	double get_space();
	~Cave();


};

#endif
