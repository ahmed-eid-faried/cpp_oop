#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include  "clsDate.h"
using namespace std;

class clsInputValidate {
public:
	static bool IsNumberBetween(int Num, int From, int To) {
		return (Num >= From && Num <= To);
	}
	static bool IsNumberBetween(double Num, double From, double To) {
		return (Num >= From && Num <= To);
	}
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		return (Date.IsDate1AfterDate2(From) || Date.IsDate1EqualDate2(From))
			&& (Date.IsDate1BeforeDate2(To) || Date.IsDate1EqualDate2(To));
	}
	static bool isInteger(const std::string& str) {
		std::istringstream iss(str);
		int num;
		char c;
		if (!(iss >> num) || (iss.get(c))) {
			return false; // Either no integer was read or there are extra characters.
		}
		return true;
	}
	static int ReadIntNumber(string Message = "Enter an integer:\n", string Error = "That's not an integer. Please try again: ") {
		int Num;
		cout << Message;
		while (true) {
			cin >> Num;
			if (cin.fail()) {
				cin.clear(); // clear the error flag
				cin.ignore(numeric_limits< streamsize>::max(), '\n'); // discard invalid input
				cout << Error;
			}
			else {
				break; // valid input
			}
		}
		return Num;
	}
	static double ReadDblNumber(string Message = "Enter an integer:\n", string Error = "That's not an integer. Please try again: ") {
		double Num;
		cout << Message;
		while (true) {
			cin >> Num;
			if (cin.fail()) {
				cin.clear(); // clear the error flag
				cin.ignore(numeric_limits< streamsize>::max(), '\n'); // discard invalid input
				cout << Error;
			}
			else {
				break; // valid input
			}
		}
		return Num;
	}
	static int ReadIntNumberBetween(int From, int To, string Message = "ENTER NUMBER") {
		int NUM;
		do {
			cout << Message << " FROM " << to_string(From) << " TO " << to_string(To) << ": ";
			cin >> NUM;
		} while (NUM < From || NUM > To);
		return NUM;
	}
	static double ReadDblNumberBetween(double From, double To, string Message = "ENTER NUMBER") {
		double NUM;
		do {
			cout << Message << " FROM " << to_string(From) << " TO " << to_string(To) << ": ";
			cin >> NUM;
		} while (NUM <= From || NUM >= To);
		return NUM;
	}
	static bool IsValideDate(clsDate Date) {
		return Date.IsValidDate();
	}
};

void InputValidateEX() {
	cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
	cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

	cout << clsInputValidate::IsDateBetween(clsDate(),
		clsDate(8, 12, 2022),
		clsDate(31, 12, 2022)) << endl;

	cout << clsInputValidate::IsDateBetween(clsDate(),
		clsDate(31, 12, 2022),
		clsDate(8, 12, 2022)) << endl;

	cout << "\nPlease Enter a Number:\n";
	int x = clsInputValidate::ReadIntNumber();
	cout << "x=" << x;

	cout << "\nPlease Enter a Number between 1 and 5:\n";
	int y = clsInputValidate::ReadIntNumberBetween(1, 5, "Number is not within range, enter again:\n");
	cout << "y=" << y;

	cout << "\nPlease Enter a Double Number:\n";
	double a = clsInputValidate::ReadDblNumber();
	cout << "a=" << a;

	cout << "\nPlease Enter a Double Number between 1 and 5:\n";
	double b = clsInputValidate::ReadDblNumberBetween(1, 5, "Number is not within range, enter again:\n");
	cout << "b=" << b;

	cout << endl << clsInputValidate::IsValideDate(clsDate(35, 12, 2022)) << endl;
}