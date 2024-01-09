#include <iostream>
#include <string.h>
#include <fstream>
#include "Event.h"
#include "Location.h"
#include "Ticket.h"
#include "Reservations.h"
using namespace std;

int main() {
	
	while (true) {
		cout << " TICKETING APP: " << endl;
		cout << "1. Information about the event." << endl;
		cout << "2. Information about the location." << endl;
		cout << "3. Information about the tickets." << endl;
		cout << "4. Information about reservations." << endl;
		cout << "5.Exit" << endl;

		int option;
		cout << "Enter an option: ";
		cin >> option;

		if (option == 1) {

			cout << endl << "---------------------------";
			cout << "FIRST CLASS: EVENT ---------------------------";
			cout << endl;
			//testing the first class - Event

			////creating objects 
			Event e1("Concert", 30);
			cout << e1;

			Event e2("Play", 90);
			cout << e2;

			////calling the copy constructor
			Event e3 = e1;
			cout << e3;

			int seats[4] = { 10, 20, 30, 40 };

			Event e4("Concert", 90, seats, 4, false);
			cout << e4;

			////calling operator=
			Event e5;
			e5 = e4;
			cout << e5;

			////operator+ inside the class 
			cout << endl;
			cout << endl << "Operator + inside the class" << endl;
			cout << e3.getDuration(); //30
			cout << endl << e5.getDuration(); //90
			e5 = e3 + 2; //e5 = 90+2
			cout << endl << e5.getDuration(); //92
			cout << endl;

			////operator+ outside the class
			cout << endl << "Operator + outside the class";
			cout << endl << e3.getDuration(); //30
			cout << endl << e5.getDuration(); //32
			e5 = 2 + e3; //e5=2+30
			cout << endl << e5.getDuration(); //32
			cout << endl << e3.getDuration(); //30
			cout << endl;

			////calling operator++ inside the class
			////POST INCREMENTATION
			cout << endl << "Operator ++ inside the class";
			cout << endl << e3.getDuration(); //30
			cout << endl << e2.getDuration(); //90
			e3 = e2++; //e3 takes the duration of e2, then e2 duration increments by 1
			cout << endl << e3.getDuration(); //30
			cout << endl << e2.getDuration(); //91
			cout << endl;

			////calling operator++ outside the class
			////PRE INCREMENTATION - doesn't work
			//cout << endl;
			//cout << endl << e3.getDuration();
			//cout << endl << e2.getDuration();
			//e3 = ++e2; //first increment the duration of s2 by 1, then give e3 this duration
			//cout << endl << e3.getDuration();
			//cout << endl << e2.getDuration();

			cout << endl;
			cout << endl;
			cout << "Index operator";
			try {
				cout << endl << e2[2] << endl; //play 0123 - a
			}
			catch (exception ex) {
				cout << ex.what();
			}

			cout << endl;

			////calling the ! operator
			cout << endl << "Operator !"<<endl;
			cout << e4.getIsSoldOut(); //0
			cout << endl;
			cout << !e4; //1

			////1-true; 0-false

			cout << endl;
			cout << endl;

			////calling the < operator
			cout << endl <<  "Operator <";
			if (e3 < 90) {
				cout << endl << "Event 3 is shorter than 90 minutes.";
			}
			else {
				cout << endl << "Event 3 is longer than 90 minutes.";
			}

			cout << endl;
			////calling the == operator
			cout << endl<< "Operator ==";
			if (e1 == e2) { //not equal
				cout << endl << "They are equal.";
			}
			else {
				cout << endl << "They are not equal.";
			}

			while (true) {
				cout << endl;
				cout << endl << "Do you want to add an event? 1. Yes  2. No" << endl << "Press 2 to exit this option.";
				cout << endl << "Your option: ";
				int eventOption;
				cin >> eventOption;

				if (eventOption == 1) {
					cin >> e2;
					cout << e2;
				}
				else 
					if (eventOption == 2) {
						break;
					}
					else {
						cout << endl << "Invalid option. Press 1 or 2" << endl;;
					}
			 }
			

			cout << endl;
			cout << endl << "Testing the inheritance of a new class.";
			Event event1("Concert", 25);
			Event event2("Theater", 23);
			EventHour event3(12, 35);
			EventHour event4(14, 45);
			EventDate event5(15, "January", 2023);
			EventDate event6(16, "February", 2023);

			Event* events[2]; //array of pointers to EVENT
			events[0] = &event1;
			events[1] = &event2;

			cout << endl << "-----------------Upcasting------------";
			for (int i = 0; i < 2; i++) {
				events[i]->printInfo();
				cout << endl;
			}

			EventHour* hour[2];
			hour[0] = &event3;
			hour[1] = &event4;

			cout << endl << "-----------------Upcasting for EventHour------------";
			for (int i = 0; i < 2; i++) {
				hour[i]->printInfo();
				cout << endl;
			}

			EventDate* date[2];
			date[0] = &event5;
			date[1] = &event6;

			cout << endl << "-----------------------Upcasting for EventDate----------";
			for (int i = 0; i < 2; i++) {
				date[i]->printInfo();
				cout << endl;
			}


			cout << endl;

		}
		else if (option == 2) {
			cout << endl;
			cout << endl;
			cout << endl << "---------------------------";
			cout << "SECOND CLASS: LOCATION---------------------------";
			cout << endl;


			//testing for 2nd class - Location

				////creating objects
			Location l1("Baneasa", "Alexandru Tanase", VIP);
			cout << l1;

			int places[] = { 10,20,30,40,50,60,70,80,90,100 };
			Location l2("Aviatorilor", "Ion Daniel", 10, places, 10);
			cout << l2;

			Location l3("Parcul Tei", "Alexandru Popescu", 20, places, 40);
			cin >> l3;
			cout << l3;

			Location l4("Arena Nationala", "Maria Comanescu", NORMAL);
			cout << l4;

			Location l7("Timisoara", "Cristina Alexandrescu", 50, places, 60);
			Location l8("Unirii", "Saint Elmo", 80, places, 60);

			////calling the copy constructor
			Location l5 = l2;
			cout << l2;

			////calling operator=
			Location l6;
			l6 = l4;
			cout << l6;

			////operator+ inside the class
			cout << endl << "Operator + inside the class" << endl;
			cout << endl << l2.getNoRows(); //10
			cout << endl << l3.getNoRows(); //20
			l2 = l3 + 4; //l2 = 20 + 4 = 24
			cout << endl << l2.getNoRows(); //24
			cout << endl << l3.getNoRows(); //20
			cout << endl;

			//operator++ inside the class POST
			cout << endl << "Operator ++ inside the class" << endl;
			cout << endl << l2.getNoRows(); //24
			cout << endl << l3.getNoRows(); //20
			l3 = l2++; //first l3 takes the value of l2, then l2 increases by 1
			cout << endl << l2.getNoRows(); //25
			cout << endl << l3.getNoRows(); //24 - gives 20;
			cout << endl;

			//operator- outside the class
			cout << endl << "Operator - outside the class" << endl;
			cout << endl << l7.getNoRows(); //50
			cout << endl << l8.getNoRows(); //80
			l8 = 3 + l7;
			cout << endl << l7.getNoRows(); //50
			cout << endl << l8.getNoRows(); //80(?) //53
			cout << endl;

			//operator++ outisde the class PRE - doesn't work
			//cout << endl << l2.getNoRows(); //20
			//cout << endl << l7.getNoRows(); //50
			//l7 = ++l2;
			//cout << endl << l2.getNoRows(); //20
			//cout << endl << l7.getNoRows(); //50

			cout << endl;
			//////calling the index operator
			cout << "Index operator";
			try {
				cout << endl << l1[2] << endl; // alexandru 012345678 //e
			}
			catch (exception ex) {
				cout << ex.what();
			}

			cout << endl;
			////calling the ! operator
			cout << "Operator !";
			if (!l2) { //l2 has 10 rows
				cout << endl << "Location 2 has more than 15 rows";
			}
			else {
				cout << endl<< "Location 2 does not have 15 or more rows. It has only 10.";
			}

			cout << endl;
			cout << endl;
			cout << "Operator !";
			if (!l3) { //l3 has 20 rows
				cout << endl << "Location 3 has more than 15 rows. ";
			}
			else {
				cout << endl << "Location 2 does not have 15 or more rows. It has only 10.";
			}

			cout << endl;
			cout << endl;
			////calling the == operator
			cout << "Operator ==";
			if (l2 == l3) { //not equal
				cout << endl << "They are equal.";
			}
			else {
				cout << endl << "They are not equal.";
			}

			cout << endl;
			cout << endl;
			////calling the > operator
			cout << "Operator >";
			if (l2 > 5) {
				cout << endl << "Location 2 has more rows than just 5.";
			}
			else {
				cout << endl << "Location 2 has less than 5 rows.";
			}

			while (true) {
				cout << endl;
				cout << endl << "Do you want to add a location? 1. Yes  2. No" << endl << "Press 2 to exit this option.";
				cout << endl << "Your option: ";
				int locationOption;
				cin >> locationOption;

				if (locationOption == 1) {
					cin >> l3;
					cout << l3;
				} 
				else
					if (locationOption == 2) {
						break;
					}
					else {
						cout << endl << "Invalid option. Press 1 or 2" << endl;;
					}
			}

			cout << endl << "Testing the inheritance of a new class.";
			Location loc1("Herastrau", 200);
			Address a1("Aviatorilor", 23);
			Address a2("Unirii", 14);
			GeographicPosition g1("Bucharest", "Romania", Continent::EUROPA);
			//GeographicPosition g2("Beijing", "China", Continent::ASIA);
			
			Location* location[3]; //array of pointers to Location
			location[0] = &loc1;
			location[1] = &a1;
			location[2] = &a2;

			cout << endl << "-----------------Upcasting for Location------------";
			for (int i = 0; i < 3; i++) {
				location[i]->printInfo();
				cout << endl;
			}

			GeographicPosition* position[1];
			position[0] = &g1;
			//position[2]=&g2;

			cout << endl << "---------------Upcasting for Geographic Position";
			for (int i = 0; i < 1; i++) {
				position[i]->printInfo();
				cout << endl;
			}
			

		}
		else  if (option == 3) {

			cout << endl;
			cout << endl;
			cout << endl << "---------------------------";
			cout << "THIRD CLASS: TICKET ----------------------------------";
			cout << endl;

			//testing the third class - Ticket

			//creating objects
			Ticket t1("Swan Lake", 80, false); //0 = false; 1= true;
			cout << t1;
			cout << endl;
			cin >> t1;

			cout << endl;
			Ticket t2("Nutcracker", "Held at National Opera House", 100, true);
			cout << t2;
			cout << endl;

			////calling the operator=
			Ticket t3;
			t3 = t2;
			cout << t3;

			////calling the copy constructor
			Ticket t4 = t2;
			cout << t4;
			cout << endl;

			Ticket t5("Hamlet", "Held on Lipscani", 200, false);
			t5.printInfo();
			

			//////operator+ inside the class 
			cout << endl << "Operator + inside the class" << endl;
			cout << endl << t3.getPrice(); //100
			cout << endl << t2.getPrice(); //100
			t3 = t2 + 60; // t3=160
			cout << endl << t3.getPrice(); //160
			cout << endl << t2.getPrice(); //100
			cout << endl;

			////operator+ outside the class
			cout << endl << "Operator + outside the class" << endl;
			cout << endl << t3.getPrice(); //100
			cout << endl << t2.getPrice(); //100
			t3 = 60 + t2; // t3=160
			cout << endl << t3.getPrice(); //160
			cout << endl << t2.getPrice(); //100
			cout << endl;

			//////operator ++ inside the class POST INCREMENTATION
			cout << endl << "Operator ++ inside the class" << endl;
			cout << endl << t2.getPrice(); //100
			cout << endl << t3.getPrice(); //160
			t2 = t3++; //t2 takes the price of t3, then t3 increments by 1
			cout << endl << t2.getPrice(); //160
			cout << endl << t3.getPrice(); //161
			cout << endl;


			//////operator ++ outside the class PRE INCREMENTATION
			cout << endl << "Operator + outside the class" << endl;
			cout << endl << t2.getPrice(); //160
			cout << endl << t3.getPrice(); //161
			t3 = ++t2; //increment t2 by 1, then give this price to t3
			cout << endl << t2.getPrice(); //161
			cout << endl << t3.getPrice(); //161
			cout << endl;


			cout << endl;
			cout << endl;
			//////calling the index operator
			cout << "Index operator";
			try {
				cout << endl << t2[2] << endl; //nutcracker 0123456789
			}
			catch (exception ex) {
				cout << ex.what();
			}
			
			cout << endl;
			cout << endl;
			//////calling the negation operator
			cout << "Operator !";
			cout << endl<< t2.getIsVIP();
			cout << endl;
			cout << !t2;

			cout << endl;
			cout << endl;
			//calling the > operator
			cout << "Operator >";
			if (t2 > 50) {
				cout << endl << "Ticket 2 costs more than 50 lei.";
			}
			else {
				cout << endl << "Ticket 2 costs less than 50 lei";
			}


			cout << endl;
			cout << endl;
			//////calling the == operator
			cout << "Operator ==";
			if (t2 == t5) { //not equal
				cout << endl << "They are equal.";
			}
			else {
				cout << endl << "They are not equal.";
			}

			while (true) {
				cout << endl;
				cout << endl << "Do you want to add a ticket? 1. Yes  2. No" << endl << "Press 2 to exit this option.";
				cout << endl << "Your option: ";
				int ticketOption;
				cin >> ticketOption;

				if (ticketOption == 1) {
					cin >> t1;
					cout << t1;
				}
				else
					if (ticketOption == 2) {
						break;
					}
					else {
						cout << endl << "Invalid option. Press 1 or 2" << endl;;
					}
			}

			cout << endl;
			cout << endl << "Testing the inheritance of a new class.";
			Ticket ticket1("Concert", 25, false);
			Ticket ticket2("Theater", "Held online", 65, false);
			Ticket ticket3("Cinema", 25, false);
			SpectatorTicket spectator1(TicketType::ADULT, 25);
			SpectatorTicket spectator2(TicketType::STUDENT, 10);
			SpectatorTicket spectator3(TicketType::CHILD, 5);
			PaidTicket paid1(true, "25.12.2023");
			PaidTicket paid2(false, " ");
			
			Ticket* tickets[3]; //array of pointers to Ticket
			tickets[0] = &ticket1;
			tickets[1] = &ticket2;
			tickets[2] = &ticket3;

			SpectatorTicket* spectators[3];
			spectators[0] = &spectator1;
			spectators[1] = &spectator2;
			spectators[2] = &spectator3;

			PaidTicket* paid[2];
			paid[0] = &paid1;
			paid[1] = &paid2;

			cout << endl;
			cout << endl << "-----------------Upcasting------------" << endl;
			for (int i = 0; i < 3; i++) {
				tickets[i]->printInfo();
				cout << endl;
			}

			cout << endl;
			cout << endl << "-------------------Upcasting for SpectatorTicket";
			for (int i = 0; i < 3; i++) {
				spectators[i]->printInfo();
				cout << endl;
			}

			cout << endl;
			cout << endl << "--------------Upcasting for PaidTicket";
			for (int i = 0; i < 2; i++) {
				paid[i]->printInfo();
				cout << endl;
			}
		}

		else if (option == 4) {
			//testing the fourth class for text files - reservations
		cout << endl << "--------------------------------";
		cout << endl << "FOURTH CLASS: RESERVATIONS (TEXT FILES)";
		cout << endl << "-------------------------------------";

		int seatsReserved[] = { 20,21,22 };
		int noSeatsReserved = 3;

		Reservations r1("Ana", "Concert", seatsReserved, noSeatsReserved, false);
		Reservations r2("Andrei", "Theater", seatsReserved, noSeatsReserved, true);
		r1.writeToTextFile();
		//cout << r1;

		r2.readTextFile();
		//cout << r2;

		r1.writeIntoABinaryFile();
		r2.writeIntoABinaryFile();

		r2.readingFromABinaryFile();
		//cout << endl << "Data from binary file: ";
		//cout << r2;
		}
		else if (option == 5)
		{
			break;
		}
		else
		{
			cout << endl << "Invalid option. Please enter a valid option.";
		}

		return 0;
	}
}