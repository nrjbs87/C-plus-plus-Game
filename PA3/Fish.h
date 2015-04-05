#ifndef FISH_H
#define FISH_H
#include <iostream>
#include "CoralReef.h"
#include "Cave.h"
using namespace std;

class Cave;
class Model;

class Fish : public GameObject
{
public:
	Fish(char,int, Model*);
	Fish(char,int,Cave*,int, Model*);
	Fish(char,int,CartPoint,int, Model*);
	double get_size();
	virtual double get_speed();//=0 COMEBACKTOTHIS
	double speed;
	void start_swimming(CartPoint dest);
	bool is_hidden();
	void start_hiding(Cave* destCave);
	void float_in_place();
	void show_status();
	virtual bool update();
	void start_eating(CoralReef* destReef);
	bool swim_loc() { update_location(); }
	~Fish();
	//New functions
	virtual void start_attack(Fish*);//Tuna can attack too
	virtual void start_mating(Fish*);
	void get_bitten(int attack_strength);
	//Getters
	CartPoint home_getter(Fish*);
	CartPoint get_fish_home_loc();
	Cave* get_fish_home();
	//Setters
	void set_fish_loc(CartPoint);
	
protected:
	double energy;
	double size;
	double prefeast_size;
	CartPoint destination;
	CartVector delta;
	CoralReef* reef;
	Cave* home;
	bool update_location();
	void setup_destination(CartPoint dest);
	Model* my_world;



};

#endif
