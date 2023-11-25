#include <iostream>
#include <string.h>
#include "Event.h"
#include "Location.h"
#include "Ticket.h"
using namespace std;

int main() {
	//testing the first class - Event
	
	////creating objects 
	//Event e1("Concert", 30);
	//cout << e1;

	//Event e2("Play", 90);
	//cout << e2;

	////calling the copy constructor
	//Event e3 = e1;
	//cout << e3;

	//int seats[4] = { 10, 20, 30, 40 };

	//Event e4("Concert", 90, seats, 4, false);
	//cout << e4;

	////calling operator=
	//Event e5;
	//e5 = e4;
	//cout << e5;

	////operator+ inside the class
	//cout << endl;
	//cout << e3.getDuration(); //30
	//cout << endl << e5.getDuration(); //90
	//e5 = e3 + 2; //e5 = 90+2
	//cout << endl << e5.getDuration(); //92

	////operator+ outside the class
	//cout << endl;
	//cout <<endl <<  e3.getDuration(); //30
	//cout << endl << e5.getDuration(); //32
	//e5 = 2 + e3; //e5=2+30
	//cout << endl << e5.getDuration(); //32
	//cout << endl << e3.getDuration(); //30
	//cout << endl;

	////calling operator++ inside the class
	////POST INCREMENTATION
	//cout << endl;
	//cout << endl << e3.getDuration(); //30
	//cout << endl << e2.getDuration(); //90
	//e3 = e2++; //e3 takes the duration of e2, then e2 duration increments by 1
	//cout << endl << e3.getDuration(); //30
	//cout << endl << e2.getDuration(); //91

	////calling operator++ outside the class
	////PRE INCREMENTATION
	////cout << endl;
	////cout << endl << e3.getDuration();
	////cout << endl << e2.getDuration();
	////e3 = ++e2; //first increment the duration of s2 by 1, then give e3 this duration
	////cout << endl << e3.getDuration();
	////cout << endl << e2.getDuration();

	//cout << endl;
	////calling the index operator
	//try {
	//	cout << endl << e2[2] << endl; //play 0123
	//}
	//catch (exception ex) {
	//	cout << ex.what();
	//}

	//cout << endl;
	////calling the cast operator 
	//cout << "CAST";
	//Event e7("Movie", 120);
	//int duration = e7;
	//int t = e4;

	//cout << endl;

	////calling the ! operator
	//cout << e4.getIsSoldOut();
	//cout << endl;
	//cout << !e4;

	////1-true; 0-false

	////calling the <= operator

	////calling the == operator
	//if (e1 == e2) { //not equal
	//	cout << endl << "They are equal.";
	//}
	//else {
	//	cout << endl << "They are not equal.";
	//}

	//cin >> e2;;

	//testing the third class - Ticket

	//creating objects
	Ticket t1("Swan Lake", 80, false); //0 = false; 1= true;
	cout << t1;
	cout << endl;
	//cin >> t1;

	cout << endl;
	Ticket t2("Nutcracker", "Held at National Opera House", 100, true);
	cout << t2;
	cout << endl;
	//cin >> t2;

	//calling the operator=
	Ticket t3;
	t3 = t2;
	cout << t3;

	//calling the copy constructor
	Ticket t4 = t2;
	cout << t4;
	cout << endl;

	Ticket t5("Hamlet", "Held on Lipscani", 200, false);
	t5.printInfo();
	
	
	////operator+ inside the class
	//cout << endl << t3.getPrice(); //100
	//cout << endl << t2.getPrice(); //100
	//t3 = t2 + 60; // t3=160
	//cout << endl << t3.getPrice(); //160
	//cout << endl << t2.getPrice(); //100
	

	//operator+ outside the class
	cout << endl << t3.getPrice(); //100
	cout << endl << t2.getPrice(); //100
	t3 = 60 + t2; // t3=160
	cout << endl << t3.getPrice(); //160
	cout << endl << t2.getPrice(); //100
	cout << endl;

	////operator ++ inside the class POST INCREMENTATION - error
	//cout << endl << t2.getPrice(); //100
	//cout << endl << t3.getPrice(); //160
	//t2 = t3++; //t2 takes the price of t3, then t3 increments by 1
	//cout << endl << t2.getPrice(); //160
	//cout << endl << t3.getPrice(); //161


	////operator ++ outside the class PRE INCREMENTATION
	cout << endl << t2.getPrice(); //100
	cout << endl << t3.getPrice(); //160
	t3 = ++t2; //increment t2 by 1, then give this price to t3
	cout << endl << t2.getPrice(); //101
	cout << endl << t3.getPrice(); //101
	cout << endl;


	//
	////calling the index operator
	try {
		cout << endl << t2[2] << endl; //nutcracker 0123456789
	}
	catch (exception ex) {
		cout << ex.what();
	}
	cout << endl;

	////calling the negation operator
	cout << t2.getIsVIP();
	cout << endl;
	cout << !t2;

	////calling the == operator
	if (t2 == t5) { //not equal
		cout << endl << "They are equal.";
	}
	else {
		cout << endl << "They are not equal.";
	}


	return 0;
}