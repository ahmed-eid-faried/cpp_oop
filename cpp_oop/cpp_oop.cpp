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

	clsPerson(
		int Id,
		string FristName,
		string LastName,
		string Email,
		string Phone)
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
		cout << "ID: \t" << _Id << endl;
		cout << "FristName: \t" << _FristName << endl;
		cout << "LastName: \t" << _LastName << endl;
		cout << "FullName: \t" << _FullName << endl;
		cout << "Email: \t" << _Email << endl;
		cout << "Phone: \t" << _Phone << endl;
		cout << "--------------------------------------------" << endl;
	}
	~clsPerson() {
		cout << "Hello World,I'm destrator.\n";
	}
};
int main()
{
	clsPerson clsPerson(1, "Ahmed", "Mady", "test@gmail.com", "0121321424");
	clsPerson.Print();
	clsPerson.SendEmail("Hi, Ahmed", "How are you?");
	clsPerson.SendSMS("Hi, Ahmed");
}