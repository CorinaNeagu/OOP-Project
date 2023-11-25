#pragma once
#include<string.h>
#include<iostream>
using namespace std;


class Ticket {
	const int idTicket;
	char* nameShow;
	string text;
	int price;
	bool isVIP;
public:
	static int NO_TICKETS;
	//default constructor
	Ticket():idTicket(++NO_TICKETS) {
		this->nameShow = nullptr;
		this->price = 0;
		this->isVIP = false;
		this->text = " ";
	}

	//constructors with parameters
	Ticket(const char* name, string text, int price, bool isVIP) :idTicket(++NO_TICKETS) {
		if (name == nullptr) {
			throw exception("Invalid");
		}
		else {
			this->nameShow = new char[strlen(name) + 1];
			strcpy_s(this->nameShow, strlen(name) + 1, name);
		}
		this->text = text;
		this->price = price;
		this->isVIP = isVIP;
	}

	Ticket(const char* name, int price, bool isVIP) :idTicket(++NO_TICKETS) {
		if (name == nullptr) {
			throw exception("Invalid");
		}
		else {
			this->nameShow = new char[strlen(name) + 1];
			strcpy_s(this->nameShow, strlen(name) + 1, name);
		}
		this->price = price;
		this->isVIP = isVIP;
		this->text = " ";
	}
	
	//setters and getters 
	char* getNameShow() const {
		if (this->nameShow != nullptr) {
			char* copyShow = new char[strlen(this->nameShow) + 1];
			strcpy_s(copyShow, strlen(this->nameShow) + 1, nameShow);
			return copyShow;
		}
		else {
			return nullptr;
		}
	}

	void setNameShow(const char* name) {
		if (nameShow == nullptr) {
			throw exception("Invalid");
		}
		else {
			if (this->nameShow != nullptr) {
				delete[] this->nameShow;
				this->nameShow = nullptr;
			}
			this->nameShow = new char[strlen(name) + 1];
			strcpy_s(this->nameShow, strlen(name) + 1, name);
		}
	}

	string getText() {
		return this->text;
	}

	void setText(string description) {
		if (description.size() < 5) {
			throw exception("Too little information.");
		}
		else {
			this->text = description;
		}

	}

	int getPrice() const {
		return this->price;
	}

	void setPrice(int price) {
		if (price < 50) {
			throw exception("Price too low for such events.");
		}
		else {
			this->price = price;
		}
	}

	bool getIsVIP() const {
		return this->isVIP;
	}

	bool setIsVIP(bool VIP) {
		this->isVIP = VIP;
	}


	//copy constructor
	Ticket(const Ticket& ticket):idTicket(++NO_TICKETS) {
		
		this->nameShow = new char[strlen(ticket.nameShow) + 1];
		strcpy_s(this->nameShow, strlen(ticket.nameShow) + 1, ticket.nameShow);
		
		this->price = ticket.price;
		this->text = ticket.text;
		this->isVIP = ticket.isVIP;
	}

	//destructor
	~Ticket() {
		//cout << endl << "Calling the destructor";
		if (this->nameShow != nullptr) {
			delete[] this->nameShow;
			this->nameShow = nullptr;
		}
	}
	
	//operator=
	Ticket& operator=(const Ticket& ticket) {
		if (ticket.nameShow != nullptr) {
			if (this->nameShow != nullptr) {
				delete[] this->nameShow;
				this->nameShow = nullptr;
			}
			this->nameShow = new char[strlen(ticket.nameShow) + 1];
			strcpy_s(this->nameShow, strlen(ticket.nameShow) + 1, ticket.nameShow);
		}
		else {
			this->nameShow = nullptr;
		}
		this->isVIP = ticket.isVIP;
		this->price = ticket.price;
		this->text = ticket.text;
		return *this;
	}

	friend ostream& operator<<(ostream& console, const Ticket& ticket);
	friend istream& operator>>(istream& in, Ticket& ticket);
};

//<< operator
ostream& operator<<(ostream& console, const Ticket& ticket) {
	console << endl << "----------------------------";
	console << endl << "The ticket for " << ticket.nameShow << " costs " << ticket.price << ".";
	console << endl << "Some information about this show: " << ticket.text;
	console << endl << "The number of this ticket is: " << ticket.idTicket;
	console << endl << "This ticket is a VIP one: " << ticket.isVIP;
	return console;
}

//>> operator
istream& operator>>(istream& in, Ticket& ticket) {
	cout << endl << "This ticket is for: ";
	char buffer[100];
	in.getline(buffer, 100);
	in.clear();
	ticket.setNameShow(buffer);

	cout << "The price of this ticket is: ";
	in >> ticket.price;

	cout << "Some information about this event: ";
	in >> ticket.text;

	cout << "Is this a VIP ticket? ";
	in >> ticket.isVIP;

	return in;
}
int Ticket::NO_TICKETS = 0;