#ifndef SHARK_H
#define SHARK_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Fish.h"
#include "Model.h"
using namespace std;

class Model;
class Fish;


class Shark: public Fish
{

public:
Shark(Model*);
Shark(int, Model*);
double get_speed();
void start_attack(Fish* target);
bool update();
void show_status();

private:
int attack_strength;
double range;
Fish* target;
double distance_to_fish;

};

#endif
