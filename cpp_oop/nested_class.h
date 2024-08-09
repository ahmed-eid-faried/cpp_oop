#pragma once
#include <iostream>
using namespace std;

class clsA {

private:
	int _varSup1 = 10;
protected:
	int varSup2 = 20;
public:
	int varSup3 = 30;
	class clsB {
	private:
		int _var1 = 10;
	protected:
		int var2 = 20;
	public:
		int var3 = 30;
	};
};

class clsPerson2 {

	class clsAddress
	{
		string _AddressLine1;
		string _AddressLine2;
		string _City;
		string _Country;
	public:

		clsAddress() {};
		clsAddress(string AddressLine1, string AddressLine2, string City, string Country) {
			_AddressLine1 = AddressLine1;
			_AddressLine2 = AddressLine2;
			_City = City;
			_Country = Country;
		};
		void Print()
		{
			cout << "\nAddress:\n";
			cout << _AddressLine1 << endl;
			cout << _AddressLine2 << endl;
			cout << _City << endl;
			cout << _Country << endl;
		}

		//AddressLine1
		string GetAddressLine1() { return _AddressLine1; }
		void SetAddressLine1(string AddressLine1) { _AddressLine1 = AddressLine1; }
		__declspec(property(get = GetAddressLine1, put = SetAddressLine1))string AddressLine1;

		//AddressLine2
		string GetAddressLine2() { return _AddressLine2; }
		void SetAddressLine2(string AddressLine2) { _AddressLine2 = AddressLine2; }
		__declspec(property(get = GetAddressLine2, put = SetAddressLine2))string AddressLine2;

		//City
		string GetCity() { return _City; }
		void SetCity(string City) { _City = City; }
		__declspec(property(get = GetCity, put = SetCity))string City;

		//Country
		string GetCountry() { return _Country; }
		void SetCountry(string Country) { _Country = Country; }
		__declspec(property(get = GetCountry, put = SetCountry))string Country;
	};

public:
	string FullName;
	clsAddress Address;
	clsPerson2() {
		FullName = "Mohammed Abu-Hadhoud";
		Address = clsAddress("Building 10", "Queen Rania Street", "Amman", "Jordan");
	};

};
void NestedClassesExample() {
	clsA A;
	cout << A.varSup3 << endl;
	clsA::clsB B;
	cout << B.var3 << endl;
	cout << "===========================" << endl;
	clsPerson2 Person1;
	Person1.Address.Print();
}