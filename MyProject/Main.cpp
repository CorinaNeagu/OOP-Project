#include <iostream>
#include <string.h>
#include "Event.h"
#include "Location.h"
using namespace std;

int main() {
	//creating objects 
	Event e1("Concert", 30);
	cout << e1;

	Event e2("Play", 90);
	cout << e2;

	//calling the copy constructor
	Event e3 = e1;
	cout << e3;

	int seats[4] = { 10, 20, 30, 40 };

	Event e4("Concert", 90, seats, 4, false);
	cout << e4;

	//calling operator=
	Event e5;
	e5 = e4;
	cout << e5;

	//operator+ inside the class
	cout << endl;
	cout << e3.getDuration(); //30
	cout << endl << e5.getDuration(); //90
	e5 = e3 + 2; //e5 = 90+2
	cout << endl << e5.getDuration(); //92

	//operator+ outside the class
	cout << endl;
	cout <<endl <<  e3.getDuration(); //30
	cout << endl << e5.getDuration(); //32
	e5 = 2 + e3; //e5=2+30
	cout << endl << e5.getDuration(); //32
	cout << endl << e3.getDuration(); //30



	return 0;
}