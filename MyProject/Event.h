#pragma once

#include<iostream>
#include<string.h>
using namespace std;


class Event {
private:
	const int eventCounter;
	char* nameEvent; //dynamic array of characters
	int duration;
	int* seats; //sits available for purchase
	int noSeats; //static array of numbers 
	bool isSoldOut;
public:
	static int NO_EVENTS;
	//static int MAX_NO_SEATS;

public:
	//default constructor
	Event() :eventCounter(++NO_EVENTS) {
		this->nameEvent = nullptr;
		this->duration = 0;
		this->noSeats = 0;
		this->seats = nullptr;
		this->isSoldOut = false;

	}

	//2 constructors with parameters
	Event(const char* name, int duration) : eventCounter(++NO_EVENTS) {

		if (name == nullptr) {
			throw exception ("Invalid");
		}
		else {
			this->nameEvent = new char[strlen(name) + 1];
			strcpy_s(this->nameEvent, strlen(name) + 1, name);
		}

		this->duration = duration; //not shadowing
		this->noSeats = 100;
		this->seats = nullptr;
		this->isSoldOut = false;


	}

	Event(const char* name, int duration, int* seats, int noSeats, bool isSoldOut) : eventCounter(++NO_EVENTS) {
		if (name == nullptr) {
			throw exception("Invalid");
		}
		else {
			this->nameEvent = new char[strlen(name) + 1];
			strcpy_s(this->nameEvent, strlen(name) + 1, name);
		}


		this->duration = duration; //not shadowing
		this->noSeats = noSeats;
		this->isSoldOut = isSoldOut;

		if (seats != nullptr) {
			this->seats = new int[noSeats];
			for (int i = 0; i < noSeats; i++) {
				this->seats[i] = seats[i];
			}
		}
		else {
			this->seats = nullptr;
		}
	}

	char* getNameEvent() const {
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


	int* getSeats() {
		int* copySeats = new int[this->noSeats];
		for (int i = 0; i < this->noSeats; i++) {
			copySeats[i] = this->seats[i];
		}
		return copySeats;
	}

	void setSeats(int* seatsAvailable) {
		if (this->seats != nullptr) {
			delete[] this->seats;
			this->seats = nullptr;
		}
		if (seatsAvailable != nullptr) {
			this->seats = new int[this->noSeats];
			for (int i = 0; i < this->noSeats; i++) {
				this->seats[i] = seatsAvailable[i];
			}
		}
		else
		{
			this->seats = nullptr;
		}
	}


	int getDuration() const {
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

	int getNoOfSeats() const {
		return this->noSeats;
	}

	void setNoOfSeats(int noSeats) {
		if (noSeats > 1) {
			this->noSeats = noSeats; //not shadowing
		}
		else {
			throw exception("Invalid input regarding the number of seats.");
		}
	}

	bool getIsSoldOut() const {
		return this->isSoldOut;
	}

	void setIsSoldOut(bool sold) {
		this->isSoldOut = sold;
	}


	//copy constructor 
	Event(const Event& e) : eventCounter(++NO_EVENTS) {

		cout << endl << "Calling the copy constructor.";

		this->duration = e.duration;
		this->isSoldOut = e.isSoldOut;


		this->nameEvent = new char[strlen(e.nameEvent) + 1];
		strcpy_s(this->nameEvent, strlen(e.nameEvent) + 1, e.nameEvent);

		this->seats = new int[this->noSeats];
		for (int i = 0; i < this->noSeats; i++) {
			this->seats[i] = e.seats[i];
		}

		this->noSeats = e.noSeats;

	}

	//destructor 
	~Event() {
		cout << endl << "Calling the destructor";
		if (this->nameEvent != nullptr) {
			delete[] this->nameEvent;
			this->nameEvent = nullptr;
		}

		if (this->seats != nullptr) {
			delete[] this->seats;
			this->seats = nullptr;
		}
	}

	//to check later
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

		if (this->seats == event.seats) {
			return;
		}
		else {
			delete[] this->seats;
			this->seats = new int[this->noSeats];
			for (int i = 0; i < this->noSeats; i++) {
				this->seats[i] = event.seats[i];
			}
		}

		this->isSoldOut = event.isSoldOut;
		this->duration = event.duration;
		this->noSeats = event.noSeats;
		return *this;
	}

	Event& operator+(int addDuration) {
		Event copyEvent = *this;
		copyEvent.duration += addDuration; 
		return copyEvent;
	}

	//operator+ inside the class
	Event& operator+(int value) {
		Event copy = *this;
		copy.noSeats += value;
		return copy;
	}

	//operator++ inside the class POST INCREMENTATION
	Event& operator++(int) {
		Event copy = *this;
		this->noSeats++;
		return copy;
	}

	friend ostream& operator<<(ostream& console, const Event& event);
	friend istream& operator>>(istream& in, Event& event);
	friend Event operator+(int value, const Event& event);
	friend Event operator++(Event& event);
};

//operator+ outside the class using a friend method
Event operator+(int value, const Event& event) {
	Event copy = event;
	copy.noSeats += value;
	return copy;
}

//operator++ outside the class using a friend method PRE INCREMENTATION
Event operator++(Event& event) {
	event.noSeats++;
	return event;
}


ostream& operator<<(ostream& console, const Event& event) {
	console << endl << "------------------------";
	console << endl << "Event " << event.nameEvent << " will last for " <<
		event.duration << " minutes.";
	console << endl << "The tickets are sold out. " << event.isSoldOut;
	cout << endl << "There are " << event.noSeats << " available, out of which only " << event.seats << " are still available for purchase.";
	return console;
}

istream& operator>>(istream& in, Event& event) {
	cout << endl << "The name of the event is: ";
	char buffer[100];
	in.getline(buffer, 100);
	in.clear();
	event.setNameEvent(buffer);

	cout << "The duration in minutes of the event is: ";
	in >> event.duration;

	cout << "The number of available seats is: ";
	in >> event.noSeats;

	return in;

}