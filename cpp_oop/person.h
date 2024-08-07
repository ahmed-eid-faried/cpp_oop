#pragma once
#include <iostream>
using namespace std;
class clsPerson {
private:
	int _Id;
	string _FristName;
	string _LastName;
	string _FullName;
	string _Email;
	string _Phone;

public:

	clsPerson(int Id, string FristName, string LastName, string Email, string Phone)
	{
		_Id = Id;
		_FristName = FristName;
		_LastName = LastName;
		_FullName = FristName + " " + LastName;
		_Email = Email;
		_Phone = Phone;
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
		cout << "ID         : \t" << _Id << endl;
		cout << "FristName  : \t" << _FristName << endl;
		cout << "LastName   : \t" << _LastName << endl;
		cout << "FullName   : \t" << _FullName << endl;
		cout << "Email      : \t" << _Email << endl;
		cout << "Phone      : \t" << _Phone << endl;
		cout << "--------------------------------------------" << endl;
	}
	~clsPerson() {
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
	__declspec(property(get = GetFullName))string FullName;
	//Email
	string GetEmail() { return _Email; }
	void SetEmail(string Email) { _Email = Email; }
	__declspec(property(get = GetEmail, put = SetEmail))string Email;
	//Phone
	string GetPhone() { return _Phone; }
	void SetPhone(string Phone) { _Phone = Phone; }
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;

};
void PersonExample()
{
	clsPerson clsPerson(1, "Ahmed", "Mady", "test@gmail.com", "0121321424");
	clsPerson.Print();

	clsPerson.SendEmail("Hi, Ahmed", "How are you?");

	clsPerson.SendSMS("Hi, Ahmed");

	//clsPerson.Id = 1;
	cout << clsPerson.Id << endl;

	clsPerson.FristName = "AAAAAAA";
	cout << clsPerson.FristName << endl;

	clsPerson.LastName = "MMMMMM";
	cout << clsPerson.LastName << endl;

	//clsPerson.FullName = "AAAAAAA MMMMMM";
	cout << clsPerson.FullName << endl;

	clsPerson.Email = "a@gmail.com";
	cout << clsPerson.Email << endl;

	clsPerson.Phone = "01555544555";
	cout << clsPerson.Phone << endl;

	cout << endl;
	clsPerson.Print();

}