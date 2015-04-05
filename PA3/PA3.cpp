#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
#include "Cave.h"
#include "CoralReef.h"
#include "Fish.h"
#include "GameObject.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"

int main()
{
cout<<endl;
cout<<endl;
cout << "EC327: Introduction to Software Engineering" << endl;
cout << "Fall 2014" << endl;
cout << "Programming Assignment 3" << endl;
char command;
Model* mod = new Model;
View* check = new View;
mod -> show_status();

do
{
//mod -> show_status();
mod -> display(*check);
cout << "Enter command: ";
cin >> command;
switch(command)
{
case 's':
{
do_swim_command(*mod);
break;
}

case 'e':
{
do_eat_command(*mod);
break;
}

case 'f':
{
do_float_command(*mod);
break;
}

case 'z':
{
do_zoom_command(*mod);
break;
}

case 'g':
{
do_go_command(*mod);
mod -> show_status();
break;
}

case 'r':
{
do_run_command(*mod);
mod -> show_status();
break;
}

case 'q':
{
return 0;
}
}

}
while (command != 'q');
return 0;
}
