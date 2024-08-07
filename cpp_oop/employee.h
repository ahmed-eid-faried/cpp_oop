#pragma once
#pragma once
#include <iostream>
using namespace std;
class clsEmployee {
private:
	int _Id;
	string _FristName;
	string _LastName;
	string _FullName;
	string _Email;
	string _Phone;
	string _Title;
	double _Salary;
	string _Department;


public:
	clsEmployee(int Id, string FristName, string LastName, string Email, string Phone,
		string Title, double Salary, string Department)
	{
		_Id = Id;
		_FristName = FristName;
		_LastName = LastName;
		_FullName = FristName + " " + LastName;
		_Email = Email;
		_Phone = Phone;
		_Title = Title;
		_Salary = Salary;
		_Department = Department;
	}
	void SendEmail(string Subject, string Body) {
		cout << endl;
		cout << "The following message sent to email: " << _Email << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Body: " << Body << endl;
		cout << endl;
	}
	void SendSMS(string SMS) {
		cout << endl;
		cout << "The following SMS sent to Phone: " << _Phone << endl;
		cout << "SMS: " << SMS << endl;
		cout << endl;
	}
	void Print() {
		cout << "Info: " << endl;
		cout << "--------------------------------------------" << endl;
		cout << " ID         : " << _Id << endl;
		cout << " FristName  : " << _FristName << endl;
		cout << " LastName   : " << _LastName << endl;
		cout << " FullName   : " << _FullName << endl;
		cout << " Email      : " << _Email << endl;
		cout << " Phone      : " << _Phone << endl;
		cout << " Title      : " << _Title << endl;
		cout << " Salary     : " << _Salary << endl;
		cout << " Department : " << _Department << endl;
		cout << "--------------------------------------------" << endl;
	}
	~clsEmployee() {
		cout << "Hello World,I'm destrator.\n";
	}
	//properties ==>> setters and getters:-
	//Id
	int GetId() { return _Id; }
	__declspec(property(get = GetId))int Id;
	//FristName
	string GetFristName() { return _FristName; }
	void SetFristName(string FristName) { _FristName = FristName; }
	__declspec(property(get = GetFristName, put = SetFristName))string FristName;
	//LastName
	string GetLastName() { return _LastName; }
	void SetLastName(string LastName) { _LastName = LastName; }
	__declspec(property(get = GetLastName, put = SetLastName))string LastName;
	//FullName
	string GetFullName() { return _FullName; }
	void SetFullName(string FullName) { _FullName = FullName; }
	__declspec(property(get = GetFullName, put = SetFullName))string FullName;
	//Email
	string GetEmail() { return _Email; }
	void SetEmail(string Email) { _Email = Email; }
	__declspec(property(get = GetEmail, put = SetEmail))string Email;
	//Phone
	string GetPhone() { return _Phone; }
	void SetPhone(string Phone) { _Phone = Phone; }
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;
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
void EmployeeExample()
{
	clsEmployee clsEmployee(1, "Ahmed", "Mady", "test@gmail.com", "0121321424", "Doctor", 8000, "Software");
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