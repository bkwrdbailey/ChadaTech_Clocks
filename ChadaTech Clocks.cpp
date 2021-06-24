/*
 * Clocks.cpp
 *
 *  Created on: Jan 25, 2020
 *      Author: Bailey Barton
 */

#include <iostream>
#include <ctime> // This is included to gain access to the time libraries methods
using namespace std;

// This function displays the 12 hour format and 24 hour format side by side for the user
void DisplayClocks(tm *clock12HrFormat, tm *clock24HrFormat) {

	cout << "**************************      **************************" << endl;
	cout << "*     12-Hour Clock      *      *      24-Hour Clock     *" << endl << "*     ";

	// An if and elseif conditional is used to stop the 12 hour clock format from exceeding 12 hours or displaying a value of 0 hours
	if (clock12HrFormat->tm_hour > 12) {
		cout << clock12HrFormat->tm_hour - 12 << ":" << clock12HrFormat->tm_min << ":" << clock12HrFormat->tm_sec;
	}
	else if (clock12HrFormat->tm_hour < 1) {
		cout << clock12HrFormat->tm_hour + 1 << ":" << clock12HrFormat->tm_min << ":" << clock12HrFormat->tm_sec;
	}
	else {
		cout << clock12HrFormat->tm_hour << ":" << clock12HrFormat->tm_min << ":" << clock12HrFormat->tm_sec;
	}

	// A ternary operator is used here to decide if it is currently PM or AM based on the 24 hour clock format
	cout << ((clock12HrFormat->tm_hour >= 12 && clock12HrFormat->tm_min > 0) ? " P M" : " A M") <<"        *      *         ";
	cout << clock24HrFormat->tm_hour << ":" << clock24HrFormat->tm_min << ":" << clock24HrFormat->tm_sec << "        *" << endl;
	cout << "**************************      **************************" << endl << endl;
}

// This function displays the choices the user can select from to adjust the time or exit
void DisplayMenu() {

	cout << "              **************************" << endl;
	cout << "              * 1 - Add One Hour       *" << endl;
	cout << "              * 2 - Add One Minute     *" << endl;
	cout << "              * 3 - Add One Second     *" << endl;
	cout << "              * 4 - Exit Program       *" << endl;
	cout << "              **************************" << endl;
}

// This function adds one sec to both times
time_t AddSecond(time_t curr_time) {
	return curr_time + 1;
}

// This function adds one minute or 60 seconds to both times
time_t AddMinute(time_t curr_time) {
	return curr_time + 60;
}

// This function adds one hour or 3600 seconds to both times
time_t AddHour(time_t curr_time) {
	return curr_time + 3600;
}

// The main function will call upon the functions and output the results
int main() {

	// Declaring and initializing variables
	time_t curr_time;
	curr_time = time(NULL); // This gives curr_time the current time in seconds
	tm *clock12HrFormat = localtime(&curr_time); // This takes the total seconds of curr_time and turns it into a readable local time
	tm *clock24HrFormat = localtime(&curr_time);
	int choice = 0; // This is used to hold the user's inputted choice

	// This loop keeps going until the user enters '4' which then makes it exit
	while (choice != 4) {
		DisplayClocks(clock12HrFormat, clock24HrFormat);
		DisplayMenu();
		cout << "Choose an option:" << endl;
		cin >> choice;
		cout << endl;

		// This loop checks to make sure no invalid inputs are given like "a" for example
		while (cin.fail()) {
			cin.clear();
			cin.ignore(); // cin.clear() and cin.ignore() help to clean up cin so to avoid endless loops from occuring
			cout << "Invalid input" << endl << endl; // This lets the user know their input is not valid
			DisplayClocks(clock12HrFormat, clock24HrFormat);
			DisplayMenu();
			cout << "Choose an option:" << endl;
			cin >> choice;
			cout << endl;
		}
		// if/elseif conditionals check the user's choice to decide which function will be accessed
		if (choice == 1) {
			curr_time = AddHour(curr_time);
			tm *clock12HrFormat = localtime(&curr_time); // This sets the new adjusted seconds to the variable and is used for each if statement
			tm *clock24HrFormat = localtime(&curr_time);
		}
		else if (choice == 2) {
			curr_time = AddMinute(curr_time);
			tm *clock12HrFormat = localtime(&curr_time);
			tm *clock24HrFormat = localtime(&curr_time);
		}
		else if (choice == 3) {
			curr_time = AddSecond(curr_time);
			tm *clock12HrFormat = localtime(&curr_time);
			tm *clock24HrFormat = localtime(&curr_time);
		}
	}
	cout << "Exiting Program..."; // This lets the user know that the program has exited
}
