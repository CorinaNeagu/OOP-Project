#pragma once
#include <iostream>
#include<string.h>
using namespace std;


enum ZoneType { VIP, NORMAL };

class Location {
	string locationName;
	char* locationOwner;
	ZoneType type = NORMAL;
	int noRows;
	int* seatsPerRow;
	int noSeatsPerRow;

	static int MAX_SEATS_NUMBER;
public:
	//default constructor
	Location() {
		this->locationName = " ";
		this->locationOwner = nullptr;
		//ZoneType type = NORMAL;
		this->noRows = 10;
		this->seatsPerRow = nullptr;
		this->noSeatsPerRow = 10;

	}

	//setters & getters
	string getLocatioName() {
		return this->locationName;
	}

	void setLocationName(string locationName) {
		if (locationName.length() < 2) {
			throw exception("Wrong name. Too short.");
		}
		this->locationName = locationName;

	}

	char* getLocationOwner() const {
		char* copyOwner = new char[strlen(this->locationOwner) + 1];
		strcpy(copyOwner, this->locationOwner);
		return copyOwner;
	}

	void setLocationOwner(const char* nameOwner) {
		if (this->locationOwner != nullptr) {
			delete[] this->locationOwner;
			this->locationOwner = nullptr;
		}
		this->locationOwner = new char[strlen(nameOwner) + 1];
		strcpy_s(this->locationOwner, strlen(nameOwner) + 1, nameOwner);
	}

	int getNoRows() const {
		return this->noRows;
	}

	void setNoRows(int rows) {
		if (rows < 1 && rows> 10) {
			cout << endl << "There are only 10 rows available.";
		}
		else {
			this->noRows = rows;
		}
	}

	int getNoSeats() const {
		int noSeats = noRows * noSeatsPerRow;
		return noSeats;
	}




	//2 constructors with parameters
	Location(string locationName, int noRows, int* seatsPerRow, int noSeats) {
		this->locationName = locationName;
		this->noRows = noRows;
		if (seatsPerRow != nullptr && noSeatsPerRow > 0) {
			this->seatsPerRow = new int[noSeatsPerRow];
			for (int i = 0; i < noSeatsPerRow; i++) {
				this->seatsPerRow[i] = seatsPerRow[i];
			}
			this->noSeatsPerRow = noSeatsPerRow;
		}
		else {
			this->seatsPerRow = nullptr;
			this->noSeatsPerRow = 0;
		}

		this->type = NORMAL;
		this->locationOwner = nullptr;
	}

	Location(string locationName, const char* owner, ZoneType type) {
		this->locationName = locationName;
		this->type = type;

		this->locationOwner = new char[strlen(owner) + 1];
		strcpy_s(this->locationOwner, strlen(owner) + 1, owner);

		this->locationName = locationName;
		this->noRows = 10;
		this->seatsPerRow = nullptr;
		this->noSeatsPerRow = 10;
	}

	//copy constructor
	Location(const Location& loc) {
		this->locationName = loc.locationName;
		this->type = loc.type;
		this->noRows = loc.noRows;

		this->locationOwner = new char[strlen(loc.locationOwner) + 1];
		strcpy_s(this->locationOwner, strlen(loc.locationOwner) + 1, loc.locationOwner);

		if (loc.seatsPerRow != nullptr && loc.noSeatsPerRow > 0) {
			this->seatsPerRow = new int[loc.noSeatsPerRow];
			for (int i = 0; i < loc.noSeatsPerRow; i++) {
				this->seatsPerRow[i] = loc.seatsPerRow[i];
			}
			this->noSeatsPerRow = loc.noSeatsPerRow;
		}
		else {
			this->seatsPerRow = nullptr;
			this->noSeatsPerRow = 0;
		}
	}

	//destructor
	~Location() {
		cout << endl << "Calling the destructor";
		if (this->locationOwner != nullptr) {
			delete[] this->locationOwner;
			this->locationOwner = nullptr;
		}

		if (this->seatsPerRow != nullptr) {
			delete[] this->seatsPerRow;
			this->seatsPerRow = nullptr;
		}
	}

	//operator=
	Location& operator=(const Location& loc) {
		if (loc.locationOwner != nullptr) {
			if (this->locationOwner != nullptr) {
				delete[] this->locationOwner;
				this->locationOwner = nullptr;
			}
		}

		this->locationName = loc.locationName;
		this->noRows = loc.noRows;
		if (loc.seatsPerRow != nullptr && loc.noSeatsPerRow > 0) {
			this->seatsPerRow = new int[loc.noSeatsPerRow];
			for (int i = 0; i < loc.noSeatsPerRow; i++) {
				this->seatsPerRow[i] = loc.seatsPerRow[i];
			}
			this->noSeatsPerRow = loc.noSeatsPerRow;
		}
		else {
			this->seatsPerRow = nullptr;
			this->noSeatsPerRow = 0;
		}
		return *this;
	}

};

int MAX_SEATS_NUMBER = 100;