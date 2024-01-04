#pragma once

#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class Reservations {
	string guestName;
	string eventName;
	int* seatsReserved;
	int noSeatsReserved;
	bool alreadyPayed;

public:
	Reservations() {
		this->guestName = " ";
		this->eventName = " ";
		this->seatsReserved = nullptr;
		this->noSeatsReserved = 0;
		this->alreadyPayed = false;

	}

	Reservations(string guestName, string eventName, int* seatsReserved, int noSeatsReserved, bool hasPayed) {
		this->guestName = guestName;
		this->eventName = eventName;
	
		this->seatsReserved = new int[noSeatsReserved];
		for (int i = 0; i < noSeatsReserved; i++) {
			this->seatsReserved[i] = seatsReserved[i];
			this->noSeatsReserved = noSeatsReserved;
		}

		this->alreadyPayed = hasPayed;

	}

	//writing to a text file
	void writeToTextFile() const {
		ofstream inputFile("Reservations.txt", ios::app); 
		//app will continue writing in this text file, the default (trunc) will replace what was before and write the new data
		if (inputFile.is_open()) {
			inputFile << endl << this->guestName;
			inputFile << endl << this->eventName;
			inputFile << endl << this->noSeatsReserved;
			for (int i = 0; i < this->noSeatsReserved; i++) {
				inputFile << endl << this->seatsReserved[i];
			}
			inputFile << endl << this->alreadyPayed;
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
			file >> alreadyPayed;
		}
		file.close();
	}

		void writeIntoABinaryFile() {
			ofstream BinaryFile("Reservations.dat", ios::binary);

			int sizeGuestName = this->guestName.size() + 1;
			BinaryFile.write((char*)&sizeGuestName, sizeof(int)); //number of characters + \0
			BinaryFile.write(this->guestName.c_str(), sizeGuestName * sizeof(char)); //guestName + \0

			int sizeEventName = this->eventName.size() + 1;
			BinaryFile.write((char*)&sizeEventName, sizeof(int));
			BinaryFile.write(this->eventName.c_str(), sizeEventName * sizeof(char));

			BinaryFile.write((char*)&this->noSeatsReserved, sizeof(int));

			//writing the values one by one
			for (int i = 0; i < this->noSeatsReserved; i++) {
				BinaryFile.write((char*)&this->seatsReserved[i], sizeof(int));
			}

			BinaryFile.write((char*)&this->alreadyPayed, sizeof(bool));

			BinaryFile.close();
		}

		void readingFromABinaryFile() {
			ifstream BinaryFile("Reservations.dat", ios::binary);

			int sizeGuestName;
			BinaryFile.read((char*)&sizeGuestName, sizeof(int)); //no of characters +\0
			char bufferGuestName[100];
			BinaryFile.read(bufferGuestName, sizeGuestName * sizeof(char)); //reading the guestName through a buffer
			this->guestName = string(bufferGuestName);

			int sizeEventName;
			BinaryFile.read((char*)&sizeEventName, sizeof(int)); //no of characters +\0
			char bufferEventName[100];
			BinaryFile.read(bufferEventName, sizeEventName * sizeof(char)); //reading the guestName through a buffer
			this->eventName = string(bufferEventName);

			BinaryFile.read((char*)&this->noSeatsReserved, sizeof(int));

			if (this->seatsReserved != nullptr) {
				delete[] this->seatsReserved;
				this->seatsReserved = new int[this->noSeatsReserved];

				for (int i = 0; i < this->noSeatsReserved; i++)
					BinaryFile.read((char*)&this->seatsReserved[i], sizeof(int));

			}

			BinaryFile.read((char*)&this->alreadyPayed, sizeof(bool));
		}

		//friend ostream& operator<<(ostream& console, Reservations& r);
	};
	
	//ostream& operator<<(ostream& console, Reservations& r) {
	//	console << endl << r.guestName << " has reserved " << r.noSeatsReserved << " for "
	//		<< r.eventName << " .";
	//	for (int i = 0; i < r.noSeatsReserved; i++) {
	//		console << endl << "The seats reserved are: " << r.seatsReserved[i];
	//	}
	//	console << endl << "The seats have been payed for: " << r.alreadyPayed;
	//	return console;
	//}
