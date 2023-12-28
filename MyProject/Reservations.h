#pragma once
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

class Reservations {
	string guestName;
	string eventName;
	int* seatsReserved;
	int noSeatsReserved;

public:
	Reservations() {
		this->guestName = " ";
		this->eventName = " ";
		this->seatsReserved = nullptr;
		this->noSeatsReserved = 0;

	}

	Reservations(string guestName, string eventName, int* seatsReserved, int noSeatsReserved) :guestName(guestName), eventName(eventName), noSeatsReserved(noSeatsReserved) {

		this->seatsReserved = new int[noSeatsReserved];
		for (int i = 0; i < noSeatsReserved; i++) {
			this->seatsReserved[i] = seatsReserved[i];
		}

	}

	//writing to a text file
	void writeToTextFile() const {
		ofstream inputFile("Reservations.txt");
		if (inputFile.is_open()) {
			inputFile << endl << this->guestName;
			inputFile << endl << this->eventName;
			inputFile << endl << this->noSeatsReserved;
			for (int i = 0; i < this->noSeatsReserved; i++) {
				inputFile << endl << this->seatsReserved[i];
			}
			inputFile.close();
		}
		else {
			cout << endl << "Error: The file hasn't been opened yet.";
		}
	}

	//reading from a text file
	void readTextFile() {
		ifstream file("readReservations.txt", ios::in);
		if (file.is_open()) {
			file >> guestName;
			file >> eventName;
			file >> noSeatsReserved;
			if (this->noSeatsReserved != 0) {
				this->seatsReserved = new int[this->noSeatsReserved];
				for (int i = 0; i < this->noSeatsReserved; i++) {
					file >> this->seatsReserved[i];
				}
			}
		}
		file.close();
	}
	friend ostream& operator<<(ostream& out, Reservations& r);
};

ostream& operator<<(ostream& out, Reservations& r) {
	out << endl << "Reservation made by: " << r.guestName;
	out << endl << "Reservation made for: " << r.eventName;
	out << endl << "Number of seats reserved: " << r.noSeatsReserved;
	for (int i = 0; i < r.noSeatsReserved; i++) {
		out << endl << "Seats reserved: " << r.seatsReserved[i];
	}
	return out;

}