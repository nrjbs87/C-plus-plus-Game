#ifndef CORAL_REEF_H 
#define CORAL_REEF_H 
#include <iostream>
#include "GameObject.h"
#include "CartPoint.h"
using namespace std;

class CoralReef: public GameObject
{
private:
	double amount;
public:
	CoralReef();
	CoralReef(int in_id, CartPoint in_loc);
	bool is_empty();
	double provide_food(double amount_to_provide = 20.0);
	bool update();
	void show_status();
	~CoralReef();

	//getter
	double reef_amount();
};
#endif
