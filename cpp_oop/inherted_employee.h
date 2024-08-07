#pragma once
#pragma once
#include <iostream>
#include "person.h"
using namespace std;
class clsInhertedEmployee : public clsPerson {
private:
	string _Title;
	double _Salary;
	string _Department;
public:
	clsInhertedEmployee(int Id, string FristName, string LastName, string Email, string Phone,
		string Title, double Salary, string Department)
		:clsPerson(Id, FristName, LastName, Email, Phone)
	{
		_Title = Title;
		_Salary = Salary;
		_Department = Department;
	}

	void Print() {
		cout << "Info: " << endl;
		cout << "--------------------------------------------" << endl;
		cout << " ID         : " << clsPerson::Id << endl;
		cout << " FristName  : " << clsPerson::FristName << endl;
		cout << " LastName   : " << clsPerson::LastName << endl;
		cout << " FullName   : " << clsPerson::FullName << endl;
		cout << " Email      : " << clsPerson::Email << endl;
		cout << " Phone      : " << clsPerson::Phone << endl;
		cout << " Title      : " << _Title << endl;
		cout << " Salary     : " << _Salary << endl;
		cout << " Department : " << _Department << endl;
		cout << "--------------------------------------------" << endl;
	}

	//properties ==>> setters and getters:- 
	//Title
	string GetTitle() { return _Title; }
	void SetTitle(string Title) { _Title = Title; }
	__declspec(property(get = GetTitle, put = SetTitle))string Title;
	//Salary
	double GetSalary() { return _Salary; }
	void SetSalary(double Salary) { _Salary = Salary; }
	__declspec(property(get = GetSalary, put = SetSalary))double Salary;
	//Department
	string GetDepartment() { return _Department; }
	void SetDepartment(string Department) { _Department = Department; }
	__declspec(property(get = GetDepartment, put = SetDepartment))string Department;

};
void InhertedEmployeeExample()
{
	clsInhertedEmployee clsEmployee(1, "Ahmed", "Mady", "test@gmail.com", "0121321424", "Doctor", 8000, "Software");
	clsEmployee.Print();

	clsEmployee.SendEmail("Hi, Ahmed", "How are you?");

	clsEmployee.SendSMS("Hi, Ahmed");

	//clsEmployee.Id = 1;
	cout << clsEmployee.Id << endl;

	clsEmployee.FristName = "AAAAAAA";
	cout << clsEmployee.FristName << endl;

	clsEmployee.LastName = "MMMMMM";
	cout << clsEmployee.LastName << endl;

	clsEmployee.FullName = "AAAAAAA EEEEEE FFFFFF MMMMMM";
	cout << clsEmployee.FullName << endl;

	clsEmployee.Email = "a@gmail.com";
	cout << clsEmployee.Email << endl;

	clsEmployee.Phone = "01555544555";
	cout << clsEmployee.Phone << endl;

	clsEmployee.Title = "Developer";
	cout << clsEmployee.Title << endl;

	clsEmployee.Salary = 12000;
	cout << clsEmployee.Salary << endl;

	clsEmployee.Department = ".NET";
	cout << clsEmployee.Department << endl;

	cout << endl;
	clsEmployee.Print();

}