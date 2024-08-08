#pragma once
#include <iostream>
#include  "inherted_employee.h"
using namespace std;
class clsDeveloper : public clsInhertedEmployee {

private:
	string _MainProgrammingLanguage;

public:
	clsDeveloper(int Id, string FristName, string LastName, string Email, string Phone, string Title, double Salary, string Department,
		string  MainProgrammingLanguage)
		:clsInhertedEmployee(Id, FristName, LastName, Email, Phone, Title, Salary, Department)
	{
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}

	//Overriding
	void Print() {
		clsInhertedEmployee::Print();
		cout << " Prog. Language : " << _MainProgrammingLanguage << endl;
		cout << "--------------------------------------------" << endl;
	}

	//properties ==>> setters and getters:- 
	//MainProgrammingLanguage
	string GetMainProgrammingLanguage() { return _MainProgrammingLanguage; }
	void SetMainProgrammingLanguage(string MainProgrammingLanguage) { _MainProgrammingLanguage = MainProgrammingLanguage; }
	__declspec(property(get = GetMainProgrammingLanguage, put = SetMainProgrammingLanguage))string MainProgrammingLanguage;


};

void DeveloperExample() {
	clsDeveloper clsDeveloper(1, "Ahmed", "Mady", "test@gmail.com", "0121321424", "Doctor", 8000, "Software", "C++");
	clsDeveloper.Print();

	clsDeveloper.SendEmail("Hi, Ahmed", "How are you?");

	clsDeveloper.SendSMS("Hi, Ahmed");

	//clsDeveloper.Id = 1;
	cout << clsDeveloper.Id << endl;

	clsDeveloper.FristName = "AAAAAAA";
	cout << clsDeveloper.FristName << endl;

	clsDeveloper.LastName = "MMMMMM";
	cout << clsDeveloper.LastName << endl;

	clsDeveloper.FullName = "AAAAAAA EEEEEE FFFFFF MMMMMM";
	cout << clsDeveloper.FullName << endl;

	clsDeveloper.Email = "a@gmail.com";
	cout << clsDeveloper.Email << endl;

	clsDeveloper.Phone = "01555544555";
	cout << clsDeveloper.Phone << endl;

	clsDeveloper.Title = "Developer";
	cout << clsDeveloper.Title << endl;

	clsDeveloper.Salary = 12000;
	cout << clsDeveloper.Salary << endl;

	clsDeveloper.Department = ".NET";
	cout << clsDeveloper.Department << endl;

	clsDeveloper.MainProgrammingLanguage = "C#";
	cout << clsDeveloper.MainProgrammingLanguage << endl;

	cout << endl;
	clsDeveloper.Print();
}