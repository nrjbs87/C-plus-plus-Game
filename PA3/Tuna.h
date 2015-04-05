#ifndef TUNA_H
#define TUNA_H

#include <iostream>
#include "Fish.h"
#include "Model.h"
using namespace std;

class Model;

class Tuna: public Fish
{
public:
	Tuna(Model* model);
	Tuna(int, Cave*, Model* model);
	double get_speed();
	void start_mating(Tuna*);
	bool update();
	void show_status();
	Tuna* mate;
	int mateTime;
	bool checkflag;

};
#endif

