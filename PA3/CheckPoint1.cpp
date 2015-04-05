#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "CoralReef.h"
#include "Cave.h"
#include "math.h"
#include "Fish.h"
#include <iostream>
#include "Model.h"
using namespace std;

int main()
{
/*
	CartPoint CPCAVE = CartPoint(1, 2);
	Cave* Cave1 = new Cave(1, CPCAVE);
	Cave Cave2(1, CPCAVE);
	Fish* Bobby = new Fish(1, Cave1);
	Fish* Frank = new Fish(2, Cave1);


	CartPoint CORAL = CartPoint(50, 60);
	CoralReef* Sickestcoralreefever = new CoralReef(1, CORAL);

	Cave1->show_status();
	Bobby->show_status();
	Sickestcoralreefever->show_status();

	// LOOP NOT WORKING IN VISUAL STUDIO
/*
	{
	(*Bobby).update();
	(*Bobby).show_status();
	} while ((*Bobby).swim_loc() == false );
*/
	

	Bobby->start_eating(Sickestcoralreefever);//NEEDS TO BE MADE A LOOP
	Cave1->show_status();
	Bobby->show_status();
	Cave1->show_status();
	Bobby->update();
	Cave1->show_status();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();//im here
	Bobby->show_status();
	Bobby->update();//leaving
	Bobby->show_status();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->update();
	Bobby->show_status();
	Cave1->show_status();
	Sickestcoralreefever->show_status();
	//Model modeltest;
	// ~Model();

	
	

	

	
	


	
	
	
	

	return 0;
	

}

//CHECK POINT 1

/*CartPoint CP = CartPoint();
CartPoint CP1 = CartPoint(1, 2);
CartPoint CP2 = CartPoint(3, 4);
CartVector CV=CartVector();
CartVector CV1=CartVector(2, 3);
cout << CP;
cout << CP1;
cout << CP2;
CartPoint CP4 = CP2 + CV1;
cout << CP4;
CartVector CV2 = CP1 - CP2;
cout << CV2;
CartVector CV3 = CV1 * 4;
cout << CV3;
CartVector CV4 = CV1 / 4;
cout << CV4;

double distance= cart_distance(CP1, CP2);
cout << distance << endl;
*/

/*CartPoint horse(1, 2);
GameObject test('a', 5, horse);
test.show_status();
CoralReef coral(2, CartPoint());
coral.show_status();
Cave cave(1, CartPoint());
return 0;
*/
/*bool update_location(CartPoint destination, CartPoint location)
{
location = location + delta;
if ((abs(destination.x - location.x) >= delta.x) && (abs(destination.x - location.x) >= delta.x))
{
location.x = destination.x;
location.y = destination.y;
cout << "I'm here" << endl;
return true;
}

else
{
cout << "Just keep swimming" << endl;
return false;
}

}

int main()
{
CartPoint location = CartPoint(1, 2);
CartPoint destination = CartPoint(4, 4);
Cave cd = Cave(1, destination);
Cave *cd_ptr = &cd;
Fish f1 = Fish(1, cd_ptr);
update_location(destination, location);
return 0;
}
*/

/*CartPoint location = CartPoint(1, 2);
Fish f1 = Fish(1, location);*/

*/
