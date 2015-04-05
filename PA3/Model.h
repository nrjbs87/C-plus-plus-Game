#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include "View.h"
#include "Tuna.h"
#include "Shark.h"
#include <list>
#include <stdio.h>
#include <typeinfo>
using namespace std;

class Fish;
class Cave;
class Tuna;
class CoralReef;
class View;
class Shark;

class Model
{

public:
     Model(); 
    ~Model(); 
    Fish* get_Fish_ptr(int id_num); 
    CoralReef* get_CoralReef_ptr(int id_num); 
    Cave* get_Cave_ptr(int id_num); 
    bool update(); 
    void display(View& view);
    void show_status();
    Tuna* find_a_mate_for(Tuna*); //HAVE PROBLEMS WITH TUNA* RETURN TYPE
    void make_baby_tuna(Tuna*);
    int find_next_available_id();


    //new object pointer
    void add_new_Object(GameObject*);

    //Time Getters
    int get_time();

    //List_getters
    list<GameObject*> getobject_ptrs();
    list<GameObject*> getactive_ptrs();
    list<Fish*> getfish_ptrs(); 
    list<Cave*> getcave_ptrs(); 
    list<CoralReef*> getreef_ptrs();

    //input getters to set new objects
  CoralReef* get_reef_input(int, double, double);
  Cave* get_cave_input(int, double, double);
  Tuna* get_tuna_input(int, int);
  Shark* get_shark_input(int);

	// save and reload funcitons
	void save(ofstream&);
	void restore(ifstream&, Model*);


private: 
    int time;
    list<Fish*> fish_ptrs;
    list<GameObject*> object_ptrs;
    list<GameObject*> active_ptrs;
    list<Cave*> cave_ptrs;
    list<CoralReef*> reef_ptrs;
};

#endif
