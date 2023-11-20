#pragma once

#include<iostream>
#include<string.h>
using namespace std;


class Event {
	const int eventCounter;
	char* nameEvent; //dynamic array of
	int duration;
	int seats; //static array of numbers
	int* noSeatsAvailable;
	bool isSoldOut;

	static int NO_EVENTS;
	static int MAX_NO_SEATS;

public:
	//default constructor
	Event() :eventCounter(++NO_EVENTS) {
		this->nameEvent = nullptr;
		this->duration = 0;
		this->seats = 0;
		this->noSeatsAvailable = nullptr;
		this->isSoldOut = false;

	}

	//2 constructors with parameters
	Event(const char* name, int duration) : eventCounter(++NO_EVENTS) {

		this->nameEvent = new char[strlen(name) + 1];
		strcpy_s(this->nameEvent, strlen(name) + 1, name);

		this->duration = duration; //not shadowing
		this->seats = 100;
		this->noSeatsAvailable = nullptr;
		this->isSoldOut = false;


	}

	Event(const char* name, int duration, int* noSeatsAvailable, int seats, bool isSoldOut) : eventCounter(++NO_EVENTS) {

		this->nameEvent = new char[strlen(name) + 1];
		strcpy_s(this->nameEvent, strlen(name) + 1, name);


		this->duration = duration; //not shadowing
		this->seats = seats;
		this->isSoldOut = isSoldOut;

		if (noSeatsAvailable != nullptr) {
			this->noSeatsAvailable = new int[seats];
			for (int i = 0; i < seats; i++) {
				this->noSeatsAvailable[i] = noSeatsAvailable[i];
			}
		}
		else {
			this->noSeatsAvailable = nullptr;
		}
	}

	char* getNameEvent() {
		char* copyName = new char[strlen(this->nameEvent) + 1];
		strcpy(copyName, this->nameEvent);
		return copyName;
	}

	void setNameEvent(const char* nameEvent) {
		if (this->nameEvent != nullptr) {
			delete[] this->nameEvent;
			this->nameEvent = nullptr;
		}
		this->nameEvent = new char[strlen(nameEvent) + 1];
		strcpy_s(this->nameEvent, strlen(nameEvent) + 1, nameEvent);
	}

	int* getNoOfSeatsAvailable() {
		int* copySeats;
		if (this->noSeatsAvailable != nullptr) {
			copySeats = new int[this->seats];
			for (int i = 0; i < this->seats; i++) {
				copySeats[i] = this->noSeatsAvailable[i];
			}
		}
		else {
			copySeats = nullptr;
		}
		return copySeats;
	}

	void setNoOfSeatsAvailable(int* seatsAvailable) {
		if (this->noSeatsAvailable != nullptr) {
			delete[] this->noSeatsAvailable;
			this->noSeatsAvailable = nullptr;
		}
		if (seatsAvailable != nullptr) {
			this->noSeatsAvailable = new int[this->seats];
			for (int i = 0; i < this->seats; i++) {
				this->noSeatsAvailable[i] = seatsAvailable[i];
			}
		}
		else
		{
			this->noSeatsAvailable = nullptr;
		}
	}


	int getDuration() {
		return this->duration;
	}

	void setDuration(int duration) {
		if (duration < 5) {
			throw exception("Duration too short for such event.");
		}
		else {
			this->duration = duration;
		}
	}

	int getSeats() {
		return this->seats;
	}

	void setSeats(int noSeats) {
		if (noSeats < Event::MAX_NO_SEATS) {
			this->seats = noSeats;
		}
		else {
			throw exception("No more seats available.");
		}
	}

	bool getIsSoldOut() {
		return this->isSoldOut;
	}

	void setIsSoldOut(bool sold) {
		this->isSoldOut = sold;
	}


	//copy constructor 
	Event(const Event& e) : eventCounter(++NO_EVENTS) {

		cout << endl << "Calling the copy constructor.";

		this->duration = e.duration;
		this->seats = e.seats;
		this->isSoldOut = e.isSoldOut;


		this->nameEvent = new char[strlen(e.nameEvent) + 1];
		strcpy_s(this->nameEvent, strlen(e.nameEvent) + 1, e.nameEvent);

		this->noSeatsAvailable = new int[this->seats];
		for (int i = 0; i < this->seats; i++) {
			this->noSeatsAvailable[i] = e.noSeatsAvailable[i];
		}

	}

	//destructor 
	~Event() {
		cout << endl << "Calling the destructor";
		if (this->nameEvent != nullptr) {
			delete[] this->nameEvent;
			this->nameEvent = nullptr;
		}

		if (this->noSeatsAvailable != nullptr) {
			delete[] this->noSeatsAvailable;
			this->noSeatsAvailable = nullptr;
		}
	}


	Event& operator=(const Event& event) {
		if (event.nameEvent != nullptr) {
			if (this->nameEvent != nullptr) {
				delete[] this->nameEvent;
				this->nameEvent = nullptr;
			}
			this->nameEvent = new char[strlen(event.nameEvent) + 1];
			strcpy_s(this->nameEvent, strlen(event.nameEvent) + 1, event.nameEvent);
		}
		else {
			this->nameEvent = nullptr;
		}


		this->isSoldOut = event.isSoldOut;
		this->duration = event.duration;
		this->seats = event.seats;
		this->noSeatsAvailable = event.noSeatsAvailable;
		return *this;
	}


	friend ostream& operator<<(ostream& console, const Event& event);

};


ostream& operator<<(ostream& console, const Event& event) {
	console << endl << "------------------------";
	console << endl << "Event " << event.nameEvent << " will last for " <<
		event.duration << " minutes.";
	console << endl << "The tickets are sold out. " << event.isSoldOut;
	return console;
}

int Event::NO_EVENTS = 0;
int Event::MAX_NO_SEATS = 100;