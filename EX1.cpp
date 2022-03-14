#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool validation(string date) {
	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6));

	if (year < 0 || year > 9999) {
		cerr << "Invalid year!" << endl;
		return false;
	}

	if (month > 0 && month < 8 && month % 2 == 0) {
		if (month == 2 && year % 4 != 0 && (day < 0 || day > 28)) {
			cerr << "Invalid date!" << endl;
			return false;
		}
		else if (month == 2 && year % 4 == 0 && (day < 0 || day > 29)) {
			cerr << "Invalid date!" << endl;
			return false;
		}
		else if (day < 0 || day > 30) {
			cerr << "Invalid date!" << endl;
			return false;
		}
	}
	else if (month > 0 && month < 8 && month % 2 != 0) {
		if (day < 0 || day > 31) {
			cerr << "Invalid date!" << endl;
			return false;
		}
	}
	else if (month >= 8 && month < 13 && month % 2 != 0) {
		if (day < 0 || day > 30) {
			cerr << "Invalid date!" << endl;
			return false;
		}
	}
	else if (month >= 8 && month < 13 && month % 2 == 0) {
		if (day < 0 || day > 31) {
			cerr << "Invalid date!" << endl;
			return false;
		}
	}
	return true;
}

int main() {
	string firstName;
	string secondName;
	int pay;
	string date;
	cout << "Enter data: ";
	cin >> firstName >> secondName >> date >> pay;

	if (date[1] == '.') {
		date = "0" + date;
	}
	if (date[4] == '.') {
		date = date.substr(0, 3) + '0' + date.substr(3);
	}

	if (!validation(date)) return main();

	ofstream statement;
	statement.open("D:\\RTY\\GITHUB\\Repositories\\homework-20\\EX1\\statement.txt", ios::app);
	statement << firstName << " " << secondName << " " << date << " " << pay << endl;
	statement.close();

	return main();
}