#pragma once
#include <iostream>
#include<string.h>
using namespace std;

enum ZoneType { VIP, NORMAL };

class Location {
	string locationName; //static field
	char* locationOwner; //dynamically allocated field
	ZoneType type;
	int noRows;
	int* seats; //dynamically allocated field
	int seatsPerRow; //static field, counter for int*
public:
	//default constructor
	Location() {
		this->locationName = " ";
		this->locationOwner = nullptr;
	    this->type = NORMAL;
		this->noRows = 0;
		this->seats = nullptr;
		this->seatsPerRow = 0;
		

	}

	//2 constructors with parameters
	Location(string locationName, const char* name, int noRows, int* seats, int noSeats) {
		this->locationName = locationName;
		this->noRows = noRows;
		this->seatsPerRow = noSeats;

		if (seats != nullptr) {
			this->seats = new int[noSeats];
			for (int i = 0; i < seatsPerRow; i++) {
				this->seats[i] = seats[i];
			}
		}
		else {
			this->seats = nullptr;
		}

		if (name == nullptr) {
			throw exception("Invalid");
		}
		else {
			this->locationOwner = new char[strlen(name) + 1];
			strcpy_s(this->locationOwner, strlen(name) + 1, name);

		}

		this->type = NORMAL;
		
	}

	Location(string locationName, const char* owner, ZoneType type) {
		this->locationName = locationName;
		this->type = type;
		

		if (owner == nullptr) {
			throw exception("There is no such owner.");
		}
		else {
			this->locationOwner = new char[strlen(owner) + 1];
			strcpy_s(this->locationOwner, strlen(owner) + 1, owner);
		}

		this->noRows = 0;
		this->seatsPerRow = 0;
		this->seats = nullptr;
	}


	//setters & getters
	string getLocatioName() {
		return this->locationName;
	}

	void setLocationName(string locationName) {
		if (locationName.size() < 2) {
			throw exception("Name too short.");
		}
		this->locationName = locationName;

	}

	char* getLocationOwner() const {
		if (this->locationOwner != nullptr) {
			char* copyOwner = new char[strlen(this->locationOwner) + 1];
			strcpy_s(copyOwner,strlen(this->locationOwner)+1, locationOwner);
			return copyOwner;
		}
		else {
			return nullptr;
		}
	}

	void setLocationOwner(const char* nameOwner) {
		if (strlen(locationOwner) < 2) {
			throw exception("Invalid");
		}
		else {
			if (nameOwner == nullptr) {
				throw exception("No input.");
			}
			else {
				if (this->locationOwner != nullptr) {
					delete[] this->locationOwner;
					this->locationOwner = nullptr;
				}
				this->locationOwner = new char[strlen(nameOwner) + 1];
				strcpy_s(this->locationOwner, strlen(nameOwner) + 1, nameOwner);
			}
		}
	}

	

	int* getSeats() {
		if (this->seats != nullptr) {
			int* copySeats = new int[this->seatsPerRow];
			for (int i = 0; i < this->seatsPerRow; i++) {
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
			this->seats = new int[this->seatsPerRow];
			for (int i = 0; i < this->seatsPerRow; i++) {
				this->seats[i] = seats[i];
			}
		}
		else {
			this->seats = nullptr;
		}
	}

	int getNoRows() const {
		return this->noRows;
	}

	void setNoRows(int rows) {
		if (rows < 1 && rows> 20) {
			cout << endl << "There are only 20 rows available.";
		}
		else {
			this->noRows = rows;
		}
	}

	int getSeatsPerRow() const {
		return this->seatsPerRow;
	}
	
	void setSeatsPerRow(int seatsPerRow) {
		if (seatsPerRow > 1 && seatsPerRow < 40) {
			this->seatsPerRow = seatsPerRow;
		}
		else {
			throw exception("Invalid input regarding the number of seats per row.");
		}

	}

	//copy constructor
	Location(const Location& loc) {
		//cout << endl << "Calling the copy constructor."
		this->locationName = loc.locationName;
		this->type = loc.type;
		this->noRows = loc.noRows;

		if (loc.locationOwner != nullptr) {
			this->locationOwner = new char[strlen(loc.locationOwner) + 1];
			strcpy_s(this->locationOwner, strlen(loc.locationOwner) + 1, loc.locationOwner);
		}
		else {
			this->locationOwner = nullptr;
		}

		this->seats = new int[this->seatsPerRow];
		for(int i=0;i<this->seatsPerRow;i++) {
			this->seats[i] = loc.seats[i];
		} 
		this->seatsPerRow = loc.seatsPerRow;
	}

	//destructor
	~Location() {
		//cout << endl << "Calling the destructor";
		if (this->locationOwner != nullptr) {
			delete[] this->locationOwner;
			this->locationOwner = nullptr;
		}

		if (this->seats != nullptr) {
			delete[] this->seats;
			this->seats = nullptr;
		}
	}

	//operator=
	Location& operator=(const Location& loc) {
		if (loc.locationOwner != nullptr) {
			if (this->locationOwner != nullptr) {
				delete[] this->locationOwner;
				this->locationOwner = nullptr;
			}
			this->locationOwner = new char[strlen(loc.locationOwner) + 1];
			strcpy_s(this->locationOwner, strlen(loc.locationOwner) + 1, loc.locationOwner);
		}
		else {
			this->locationOwner = nullptr;
		}

		if (this->seatsPerRow == loc.seatsPerRow) {
			for (int i = 0; i < this->seatsPerRow; i++) {
				this->seats[i] = loc.seats[i];
			}
			return *this;
		}
		else {
			if (this->seats != nullptr) {
				delete[] this->seats;
				this->seats = nullptr;
			}
			this->seatsPerRow = loc.seatsPerRow;
			this->seats = new int[this->seatsPerRow];
			for (int i = 0; i < this->seatsPerRow; i++) {
				this->seats[i] = loc.seats[i];
			}
		}
			this->noRows = loc.noRows;
			this->locationName = loc.locationName;
			this->type = loc.type;
			return *this;
	}

	//operator+ inside the class
	Location operator+(int addRoomNumber) {
		Location copyLocation = *this;
		copyLocation.noRows += addRoomNumber;
		return copyLocation;
	}

	//operator++ inside the class - POST INCREMENTATION
	Location operator++(int) {
		Location copy = *this;
		this->noRows++;
		return copy;
	}

	//indexing operator
	char operator[](int index) {
		if (index >= 0 && index < strlen(this->locationOwner)) {
			return this->locationOwner[index];
		}
		else {
			throw exception("Index out of range.");
		}
	}

	//the negation operator !
	bool operator!() {
		return this->noRows >= 15;
	}

	//equality operator ==
	bool operator==(const Location& loc) {
		if (this->noRows == loc.noRows && strcmp(this->locationOwner, locationOwner) == 0 && this->seatsPerRow == loc.seatsPerRow &&
			this->type == loc.type && this->locationName == loc.locationName) {
			return true;
		}
		else {
			return false;
		}
	}

	//conditional operator >
	bool operator>(int value) {
		if (this->noRows > value) {
			return true;
		}
		else {
			return false;
		}
	}


	//friend zone
	friend ostream& operator<<(ostream& console, const Location& loc);
	friend istream& operator>>(istream& in, Location& loc);
	friend Location operator+(int addRow, const Location& loc);
	friend Location operator++(Location& loc);

};

//operator- outside the class using a friend method
Location operator+(int addRow, const Location& loc) {
	Location copy = loc;
	copy.seatsPerRow += addRow;
	return copy;
	
}

//operator++ outside the class using a friend method PRE INCREMENTATION
Location operator++(Location& loc) {
	loc.seatsPerRow++;
	return loc;
}


//operator <<
ostream& operator<<(ostream& console, const Location& loc) {
	console << endl << "---------------------------";
	console << endl << "The event takes place here: " << loc.locationName;
	console << endl << "The owner of this location is: " << loc.locationOwner;
	console << endl << "The number of rows is: " << loc.noRows;
	console << endl << "There are " << loc.seatsPerRow << " seats per row.";
	console << endl << "Total number of seats per row is: " << loc.noRows * loc.seatsPerRow << endl;
	//console << endl << "What type of zone does this place have? " << loc.type;
	return console;
}

istream& operator>>(istream& in, Location& loc) {
	cout << endl << "The name of the owner is: ";
	char buffer[100];
	in.getline(buffer, 100); //for reading with spaces
	in.clear();
	loc.setLocationOwner(buffer);
		
	cout << endl << "The name of this location is: ";
	in >> loc.locationName;
	cout << endl << "The number of rows available is: ";
	in >> loc.noRows;
	cout << endl<< "The number of available seats per each row is: ";
	in >> loc.seatsPerRow;
	
	return in;

}

