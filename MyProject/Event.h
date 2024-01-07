#pragma once

#include<iostream>
#include<string.h>
using namespace std;


class Event {
protected:
	const int eventCounter;
	char* nameEvent; //dynamic array of characters
	int duration;
	int* seats; //sits available for purchase
	int noSeats; //static array of numbers 
	bool isSoldOut;
public:
	static int NO_EVENTS;

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
		
		this->seats = nullptr;
		this->duration = duration; //not shadowing
		this->noSeats = 0;
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
		if (this->nameEvent != nullptr) {
			char* copyName = new char[strlen(this->nameEvent) + 1];
			strcpy_s(copyName, strlen(this->nameEvent) + 1, this->nameEvent);
			return copyName;
		}
		else {
			return nullptr; 
		}
	} 

	void setNameEvent(const char* nameEvent) {
		if (strlen(nameEvent) < 2) {
			throw exception("Invalid.");
		}
		else {
			if (nameEvent == nullptr) {
				throw exception("No input.");
			}
			else {
				if (this->nameEvent != nullptr) {
					delete[] this->nameEvent;
					this->nameEvent = nullptr;
				}
				this->nameEvent = new char[strlen(nameEvent) + 1];
				strcpy_s(this->nameEvent, strlen(nameEvent) + 1, nameEvent);
			}
		}
	}


	int* getSeats() {
		if (this->seats != nullptr) {
			int* copySeats = new int[this->noSeats];
			for (int i = 0; i < this->noSeats; i++) {
				copySeats[i] = this->seats[i];
			}
			return copySeats;
		}
		else {
			return nullptr;
		}
	}

	void setSeats(int* seats) {
		if (this->seats != nullptr) {
			delete[] this->seats;
			this->seats = nullptr;
		}
		if (seats != nullptr) {
			this->seats = new int[this->noSeats];
			for (int i = 0; i < this->noSeats; i++) {
				this->seats[i] = seats[i];
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

		//cout << endl << "Calling the copy constructor.";

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
		//cout << endl << "Calling the destructor";
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
	Event& operator=(const Event& event) { //for initialising an object with a value
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

		if (this->noSeats == event.noSeats) {
			for (int i = 0; i < this->noSeats; i++) { 
				this->seats[i] = event.seats[i];
			}
			return *this;
		}
		else { 
			if (this->seats != nullptr) {
				delete[] this->seats;
				this->seats = nullptr;
			}
			this->noSeats = event.noSeats;
			this->seats = new int[this->noSeats];
			for (int i = 0; i < this->noSeats; i++) {
				this->seats[i] = event.seats[i];
			}
		}

		this->isSoldOut = event.isSoldOut;
		this->duration = event.duration;
		return *this;
	}

	//virtual method
	virtual void printInfo() {
		cout << endl << "Event: " << this->nameEvent << " lasts for " << this->duration << " minutes.";

	}

	//operator+ inside the class
	Event& operator+(int addDuration) {
		Event copyEvent = *this;
		copyEvent.duration += addDuration; 
		return copyEvent;
	}

	//operator++ inside the class - POST INCREMENTATION
	Event& operator++(int) {
		Event copy = *this;
		this->duration++;
		return copy;
	}

	//generic method 
	void printNoSeats() const {
		if (this->seats == nullptr) {
			cout << endl << "No seats.";
		}
		else {
			cout << endl << "Available seats: ";
			for (int i = 0; i < this->noSeats; i++) {
				cout << this->seats[i] << " ";
			}
		}
	}
	
	//indexing operator
	char operator[](int index) {
		if (index >= 0 && index < strlen(this->nameEvent)) {
			return this->nameEvent[index];
		}
		else {
			throw exception("Index out of range.");
		}
	}

	
	//cast operator - explicit form 
	/*explicit operator int() {
		return this->duration;
	}*/


	//the negation operator !
	bool operator!() {
		bool copy = !this->isSoldOut;
		return copy;
	}

	//conditional operator
	bool operator<(int value) {
		if (this->duration < value) {
			return true;
		}
		else {
			return false;
		}
	}

	//equality operator ==
	bool operator==(const Event& e) {
		if (this->duration == e.duration && this->noSeats == e.noSeats && this->isSoldOut == e.isSoldOut && strcmp(this->nameEvent, e.nameEvent) == 0)
			return true;
		else
			return false;
	}


	//friend zone
	friend ostream& operator<<(ostream& console, const Event& event);
	friend istream& operator>>(istream& in, Event& event);
	friend Event operator+(int value, const Event& e);
	friend Event operator++(Event& e);
};

//operator+ outside the class using a friend method
Event operator+(int value, const Event& e) {
	Event copy = e;
	copy.duration += value;
	return copy;
}

//operator++ outside the class using a friend method PRE INCREMENTATION
Event operator++(Event& e) {
	e.duration++;
	return e;
}


ostream& operator<<(ostream& console, const Event& event) {
	console << endl << "------------------------";
	console << endl << "Event " << event.nameEvent << " will last for " <<
		event.duration << " minutes.";
	console << endl << "The tickets are sold out. " << event.isSoldOut;
	cout << endl << "There are " << event.noSeats << " available.";
	event.printNoSeats();
	return console;
}

istream& operator>>(istream& in, Event& event) {
	cout << endl << "The name of the event is: ";
	string buffer;
	in >> buffer;
	event.setNameEvent(buffer.c_str()); 
	//in.getline(buffer, 100); //reading with spaces
	//in.clear();
	//event.setNameEvent(buffer);

	cout << "The duration in minutes of the event is: ";
	in >> event.duration;

	cout << "The number of available seats is: ";
	in >> event.noSeats;

	return in;

}

int Event::NO_EVENTS = 0;

//inheritance
class EventHour : public Event {
	int eventHour = 00;
	int eventMinute = 00;

public:
	EventHour() {

	}

	EventHour(int eventHour, int eventMinute) :Event("Concert", 75) {
		this->eventHour = eventHour;
		this->eventMinute = eventMinute;
	}


	void printInfo() {
		this->Event::printInfo();
		cout << endl << "Event starts at: " << this->eventHour << ":" << this->eventMinute;
	}

	~EventHour() {

	}
};


class EventDate: public Event {
	int eventDay = 1;
	string eventMonth = " ";
	int eventYear = 2023;
public:
	EventDate() {

	}

	EventDate(int EventDay, string EventMonth, int EventYear) : Event("Concert", 75) {
		this->eventDay = EventDay;
		this->eventMonth = EventMonth;
		this->eventYear = EventYear;
	}

	void printInfo() {
		this->Event::printInfo();
		cout << endl << "Event takes place on the " << this->eventDay << " of " << this->eventMonth << ", " << this->eventYear;
	}

	~EventDate() {

	}

};