#include <iostream>
#include <string.h>
#include "Event.h"
#include "Location.h"
using namespace std;

int main() {
	//creating objects 
	Event e1("Concert", 30);
	cout << e1;

	/*Event e2("Play", 90, 85, 100, true);
	cout << e2;*/

	//calling the copy constructor
	/*Event e3 = e1;
	cout << e3;*/

	return 0;
}