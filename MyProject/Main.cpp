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
	cout << endl;

	//calling operator++ inside the class
	//POST INCREMENTATION
	cout << endl;
	cout << endl << e3.getDuration(); //30
	cout << endl << e2.getDuration(); //90
	e3 = e2++; //e3 takes the duration of e2, then e2 duration increments by 1
	cout << endl << e3.getDuration(); //30
	cout << endl << e2.getDuration(); //91

	//calling operator++ outside the class
	//PRE INCREMENTATION
	//cout << endl;
	//cout << endl << e3.getDuration();
	//cout << endl << e2.getDuration();
	//e3 = ++e2; //first increment the duration of s2 by 1, then give e3 this duration
	//cout << endl << e3.getDuration();
	//cout << endl << e2.getDuration();

	cout << endl;
	//calling the index operator
	try {
		cout << endl << e2[2] << endl; //play 0123
	}
	catch (exception ex) {
		cout << ex.what();
	}

	cout << endl;
	//calling the cast operator 
	cout << "CAST";
	Event e7("Movie", 120);
	int duration = e7;

	cout << endl;

	//calling the ! operator
	cout << e4.getIsSoldOut();
	cout << endl;
	cout << !e4;

	//1-true; 0-false

	//calling the <= operator

	//calling the == operator
	if (e1 == e2) { //not equal
		cout << endl << "They are equal.";
	}
	else {
		cout << endl << "They are not equal.";
	}

	
	return 0;
}