#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
enum enDaysOfWeek {
	Sunday = 0,
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};
enum enComparing {
	Before = -1,
	Equal = 0,
	After = 1
};
class clsDate {
	short _Day;
	short _Month;
	short _Year;
public:
	//setter and getter:-
	short GetDay() { return _Day; };
	void SetDay(short Day) { _Day = Day; };
	__declspec(property(get = GetDay, put = SetDay))short Day;
	//setter and getter:-
	short GetMonth() { return _Month; };
	void SetMonth(short Month) { _Month = Month; };
	__declspec(property(get = GetMonth, put = SetMonth))short Month;
	//setter and getter:-
	short GetYear() { return _Year; };
	void SetYear(short Year) { _Year = Year; };
	__declspec(property(get = GetYear, put = SetYear))short Year;

	static int ReadNumberInRange(int From, int To, string Message = "ENTER NUMBER") {
		int NUM;
		do {
			cout << Message << " FROM " << to_string(From) << " TO " << to_string(To) << ": ";
			cin >> NUM;
		} while (NUM < From || NUM > To);
		return NUM;
	}
	static int ReadNumber(string Message)
	{
		int Number;
		bool IsFinsh = false;
		while (!IsFinsh)
		{
			cout << Message;
			cin >> Number;
			if (Number > 0)IsFinsh = true;
		}
		return Number;


	}
	static short ReadNumber(string Message, bool shortNum)
	{
		short Num;
		cout << Message;
		cin >> Num;
		return Num;
	}
	static clsDate& ReadDate() {
		bool IsFinshed = false;
		clsDate Date;
		while (!IsFinshed)
		{
			Date.Day = ReadNumber("Please Enter a Day? ");
			Date.Month = ReadNumber("Please Enter a Month? ");
			Date.Year = ReadNumber("Please Enter a Year? ");
			if (IsValidDate(Date))
				IsFinshed = true;
			else
				cout << "\nNo, Date is a NOT valide date\n";
		}

		return Date;
	}
	static vector<string> Split(string S1, string delim) {
		int position = 0;
		string subWord = "";
		int counter = 0;
		vector<string> listWords;
		while ((position = S1.find(delim)) != string::npos)
		{
			subWord = S1.substr(0, position);
			if (subWord != "") listWords.push_back(subWord);
			S1.erase(0, position + delim.length());
		}
		//last word in string
		if (S1 != "")listWords.push_back(S1);
		return listWords;
	}
	static	short NumOfDaysInMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)return 0;
		int Days[12] = { 31, 28,  31,  30,  31,  30, 31,  31,  30,  31,  30,  31 };

		return	(Month == 2) ? (isLeapYear(Year) ? 29 : 28) : Days[Month - 1];
	}
	short NumOfDaysInMonth() {
		return  NumOfDaysInMonth(_Month, _Year);
	}
	static	bool IsValidDate(clsDate& Date) {
		if (NumOfDaysInMonth(Date.Month, Date.Year) < Date.Day || Date.Day < 1)return false;
		if (Date.Month > 12 || Date.Month < 1)return false;
		return true;
	}
	bool IsValidDate() {
		return IsValidDate(*this);
	}
	static	clsDate& StringToDate(string str, string delim = "/") {
		clsDate Date;
		vector<string> list = Split(str, delim);
		Date.Day = (short)stoi(list[0]);
		Date.Month = (short)stoi(list[1]);
		Date.Year = (short)stoi(list[2]);
		return Date;
	}
	static	string DateToString(clsDate& Date, string delim = "/") {
		return to_string(Date.Day) + delim + to_string(Date.Month) + delim + to_string(Date.Year);
	}
	static void Print(clsDate Date) {
		cout << DateToString(Date) << endl;
	}
	void Print() {
		Print(*this);
	}
	string DateToString(string delim = "/") {
		return   DateToString(*this, delim);
	}
	static	string ReadStringDate() {
		string str;
		cout << "\nPlease Enter Date dd/mm/yyyy? \n" << endl;
		getline(cin >> ws, str);
		return str;
	}
	static  string ReplaceWord(string S1, string  StringToReplace, string ReplaceTo) {
		int position = S1.find(StringToReplace);
		int counter = 0;
		while (position != string::npos)
		{
			S1 = S1.replace(position, StringToReplace.length(), ReplaceTo);
			position = S1.find(StringToReplace);
		}
		return S1;
	}
	static	string FormateDate(clsDate& Date, string Formate = "dd/mm/yyyy") {
		Formate = ReplaceWord(Formate, "yyyy", to_string(Date.Year));
		Formate = ReplaceWord(Formate, "mm", to_string(Date.Month));
		Formate = ReplaceWord(Formate, "dd", to_string(Date.Day));
		return Formate;
	}
	string FormateDate(string Formate = "dd/mm/yyyy") {
		return   FormateDate(*this, Formate);
	}
	static	bool isLeapYear(short Year) {
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}
	bool isLeapYear() {
		return   isLeapYear(_Year);
	}
	static	short NumOfDaysInYear(short Year) {
		return isLeapYear(Year) ? 366 : 365;
	}
	short NumOfDaysInYear() { return   NumOfDaysInYear(_Year); }
	static	short NumOfDaysInMonth2(short Month, short Year)
	{
		if (Month < 1 || Month>12)return 0;
		return	(Month == 2) ? (isLeapYear(Year) ? 29 : 28) : ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);
	}
	short NumOfDaysInMonth2() {
		return   NumOfDaysInMonth2(_Month, _Year);
	}
	static	short NumOfHoursInMonth(short Month, short Year) {
		return  NumOfDaysInMonth(Month, Year) * 24;
	}
	short NumOfHoursInMonth() {
		return   NumOfHoursInMonth(_Month, _Year);
	}
	static	int NumOfMinutesInMonth(short Month, short Year) {
		return NumOfHoursInMonth(Month, Year) * 60;
	}
	int NumOfMinutesInMonth() {
		return   NumOfMinutesInMonth(_Month, _Year);
	}
	static	int NumOfSecondsInMonth(short Month, short Year) {
		return NumOfMinutesInMonth(Month, Year) * 60;
	}
	int NumOfSecondsInMonth() {
		return   NumOfSecondsInMonth(_Month, _Year);
	}
	static	short DayOfWeekOrderByGergorianCalender(short Day, short Month, short Year) {
		int a = (14 - Month) / 12;
		int y = Year - a;
		int m = Month + 12 * a - 2;
		int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		return d;
	}
	static	short DayOfWeekOrderByGergorianCalender(clsDate& Date) {
		return DayOfWeekOrderByGergorianCalender(Date.Day, Date.Month, Date.Year);
	}
	short DayOfWeekOrderByGergorianCalender() {
		return DayOfWeekOrderByGergorianCalender(*this);
	}
	static	string DayShortName(enDaysOfWeek day) {
		switch (day)
		{
		case enDaysOfWeek::Sunday:
			return "Sunday";
		case enDaysOfWeek::Monday:
			return "Monday";
		case enDaysOfWeek::Tuesday:
			return "Tuesday";
		case enDaysOfWeek::Wednesday:
			return "Wednesday";
		case enDaysOfWeek::Thursday:
			return "Thursday";
		case enDaysOfWeek::Friday:
			return "Friday";
		case enDaysOfWeek::Saturday:
			return "Saturday";
		default:
			return "Sunday";
		}
	}
	static  const  string  GetDaysOfWeek(short Num) {
		const  string DaysOfWeek[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return DaysOfWeek[Num];
	}
	static	string DayShortName(short Num) {
		return GetDaysOfWeek(Num);
	}
	static	string MonthsShortName(short Month) {
		string MonthsOfYear[12] = { "Jan" ,"Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return MonthsOfYear[Month - 1];
	}
	string MonthsShortName() {
		return   MonthsShortName(_Month);
	}
	static	void BodyMonthCalender(short Month, short Year) {

		short NumOfDaysInAMonth = NumOfDaysInMonth(Month, Year);
		short OrderOfFristDay = DayOfWeekOrderByGergorianCalender(1, Month, Year);
		int CurrentDay = 1;
		for (int i = 0; i < NumOfDaysInAMonth + OrderOfFristDay; i++)
		{

			if (i >= OrderOfFristDay) {
				cout << right << setw(3) << CurrentDay;
				CurrentDay++;
				cout << " ";
				if ((i + 1) % 7 == 0)cout << endl;
			}
			else {
				cout << right << setw(3) << " ";
				cout << " ";
			}


		}
		cout << endl;
	}
	void BodyMonthCalender() {
		return   BodyMonthCalender(_Month, _Year);
	}
	static	void PrintMonthCalender(short Month, short Year) {
		cout << "------------" << MonthsShortName(Month) << "------------" << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << GetDaysOfWeek(i);
			cout << " ";

		}
		cout << endl;

		BodyMonthCalender(Month, Year);
		cout << "---------------------------" << endl;
	}
	void PrintMonthCalender() {
		return   PrintMonthCalender(_Month, _Year);
	}
	static	void PrintMonthYearCalender(short Year) {
		cout << "---------------------------" << endl;

		cout << "     Calender " << Year << "      " << endl;
		cout << "---------------------------" << endl << endl;

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalender(i, Year);
			cout << endl;
		}
		cout << "---------------------------" << endl;

	}
	void PrintMonthYearCalender() {
		return   PrintMonthYearCalender(_Year);
	}
	static	short NumOfDaysFromBeginingOfYear(short Day, short Month, short Year) {
		short NumOfDays = Day;
		for (short i = 1; i < Month; i++)
		{
			NumOfDays += NumOfDaysInMonth(i, Year);
		}
		return NumOfDays;
	}
	static	short NumOfDaysFromBeginingOfYear(clsDate& Date) {
		return  NumOfDaysFromBeginingOfYear(Date.Day, Date.Month, Date.Year);
	}
	short NumOfDaysFromBeginingOfYear() {
		return   NumOfDaysFromBeginingOfYear(*this);
	}
	static	clsDate& GetDateByNumOfDaysInYear(short NumOfDays, short Year) {
		clsDate Date;
		for (short i = 1; i <= 12; i++)
		{
			short NumOfDaysInAMonth = NumOfDaysInMonth(i, Year);
			if (NumOfDays > NumOfDaysInAMonth) {
				NumOfDays -= NumOfDaysInMonth(i, Year);
				Date.Month = i + 1;
			}
			else { break; }
		}
		Date.Day = NumOfDays;
		Date.Year = Year;
		return Date;
	}
	clsDate& GetDateByNumOfDaysInYear() {
		return  GetDateByNumOfDaysInYear(NumOfDaysFromBeginingOfYear(), _Year);
	}
	static	clsDate& AddingDaysToDate(short AddDays, clsDate& Date) {
		short NumOfDaysAfterAddingDays = AddDays + NumOfDaysFromBeginingOfYear(Date.Day, Date.Month, Date.Year);
		short RemainOfDays = NumOfDaysAfterAddingDays;
		while (true) {
			short NumOfDaysInAYear = NumOfDaysInYear(Date.Year);
			if (NumOfDaysAfterAddingDays > NumOfDaysInAYear) {
				RemainOfDays -= NumOfDaysInAYear;
				Date.Year++;
			}
			else { break; }
		}
		Date = GetDateByNumOfDaysInYear(RemainOfDays, Date.Year);
		return Date;
	}
	clsDate& AddingDaysToDate(short AddDays) {
		return   AddingDaysToDate(AddDays, *this);
	}
	static	enComparing ReturnComparingDateValue(bool state) {
		return state ? enComparing::After : enComparing::Before;
	}
	static	bool IsDate1EqualToDate2(clsDate& Date1, clsDate& Date2) {
		return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
	}
	bool IsDate1EqualToDate2(clsDate& Date2) {
		return   IsDate1EqualToDate2(*this, Date2);
	}
	static	enComparing ComparingTwoDate(clsDate Date1, clsDate Date2) {
		return (Date1.Year != Date2.Year) ? ReturnComparingDateValue(Date1.Year > Date2.Year) :
			(Date1.Month != Date2.Month) ? ReturnComparingDateValue(Date1.Month > Date2.Month) :
			(Date1.Day != Date2.Day) ? ReturnComparingDateValue(Date1.Day > Date2.Day) : enComparing::Equal;
	}
	enComparing ComparingTwoDate(clsDate  Date2) {
		return   ComparingTwoDate(*this, Date2);
	}
	static	bool IsDate1BeforeDate2(clsDate  Date1, clsDate  Date2) {
		return ComparingTwoDate(Date1, Date2) == enComparing::Before;
	}
	bool IsDate1BeforeDate2(clsDate  Date2) {
		return   IsDate1BeforeDate2(*this, Date2);
	}
	static	bool IsDate1AfterDate2(clsDate  Date1, clsDate  Date2) {
		return ComparingTwoDate(Date1, Date2) == enComparing::After;
	}
	bool IsDate1AfterDate2(clsDate  Date2) {
		return   IsDate1AfterDate2(*this, Date2);
	}
	static	bool IsDate1EqualDate2(clsDate  Date1, clsDate  Date2) {
		return ComparingTwoDate(Date1, Date2) == enComparing::Equal;
	}
	bool IsDate1EqualDate2(clsDate  Date2) {
		return   IsDate1EqualDate2(*this, Date2);
	}
	static	string ResultOfComparing(enComparing Comparing, string Title) {
		switch (Comparing)
		{
		case enComparing::After:
			return Title + "1 is " + "After " + Title + "2\n";
		case enComparing::Before:
			return Title + "1 is " + "before " + Title + "2\n";
		case enComparing::Equal:
			return Title + "1 is " + "Equal to " + Title + "2\n";
		default:
			return Title + "1 is " + "After " + Title + "2\n";
		}
	}
	static	bool IsLastDay(clsDate& Date) {
		return Date.Day == NumOfDaysInMonth(Date.Month, Date.Year);

	}
	bool IsLastDay() {
		return   IsLastDay(*this);
	}
	static	bool IsLastMonth(clsDate& Date) {
		return Date.Month == 12;
	}
	bool IsLastMonth() {
		return   IsLastMonth(*this);
	}
	static	clsDate& IncreaseDateByOneDay(clsDate& Date) {
		if (!IsLastDay(Date)) { Date.Day += 1; }
		else if (!IsLastMonth(Date)) {
			Date.Day = 1;
			Date.Month += 1;
		}
		else {
			Date.Day = 1;
			Date.Month = 1;
			Date.Year += 1;

		}
		return Date;
	}
	clsDate& IncreaseDateByOneDay() {
		return  IncreaseDateByOneDay(*this);
	}
	static	int Differance2Date(clsDate& Date1, clsDate& Date2, bool IncludingEndDay = false) {
		int Year = 0;
		for (int i = Date2.Year; i < Date1.Year; i++) { Year += NumOfDaysInYear(i); }
		int NumOfDays1 = NumOfDaysFromBeginingOfYear(Date1.Day, Date1.Month, Date1.Year);
		int NumOfDays2 = NumOfDaysFromBeginingOfYear(Date2.Day, Date2.Month, Date2.Year);
		int del = Year + NumOfDays1 - NumOfDays2;


		return IncludingEndDay ? ++del : del;
	}
	int Differance2Date(clsDate& Date2, bool IncludingEndDay = false) {
		return   Differance2Date(*this, Date2, IncludingEndDay);
	}
	//int GetDifferance2Date(clsDate& Date1, clsDate& Date2, bool IncludingEndDay = false) {
	//	int Days = 0;
	//	enComparing result = ComparingTwoDate(Date1, Date2);
	//	int swapflap = 1;
	//	((bool)result) ? swapflap = -1 : swapflap = 1;
	//	while (ComparingTwoDate(Date1, Date2) != enComparing::Equal)
	//	{
	//		Days++;
	//		result ?
	//			Date2 = IncreaseDateByOneDay(Date2) :
	//			Date1 = IncreaseDateByOneDay(Date1);
	//	}
	//	return IncludingEndDay ? (++Days * swapflap) : (Days * swapflap);
	//}
	static	int GetDifferance2Date(clsDate  Date1, clsDate  Date2, bool IncludingEndDay = false) {
		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludingEndDay ? ++Days : Days;
	}
	int GetDifferance2Date(clsDate  Date2, bool IncludingEndDay) {
		return   GetDifferance2Date(*this, Date2, IncludingEndDay);
	}
	static	tm* GetNowDate() {
		// current date/time based on current system
		time_t now = time(0);
		// Create a tm structure to hold the result
		static tm localTime;
		// Use localtime_s to safely convert the time
		localtime_s(&localTime, &now);
		return &localTime;
	}
	static  clsDate& GetSystemDate() {
		clsDate Date(
			GetNowDate()->tm_mday,
			GetNowDate()->tm_mon + 1,
			GetNowDate()->tm_year + 1900
		);
		return Date;
	}
	static	int CalculateYourAgeInDay(clsDate& Date) {
		clsDate& DateNow = GetSystemDate();
		int NumOfDays = GetDifferance2Date(DateNow, Date);
		return NumOfDays;
	}
	int CalculateYourAgeInDay() {
		return   CalculateYourAgeInDay(*this);
	}
	static	clsDate& IncreaseDateByXDays(int x, clsDate& Date) {
		for (int i = 0; i < x; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate& IncreaseDateByXDays(int x) {
		return IncreaseDateByXDays(x, *this);
	}
	static	clsDate& IncreaseDateByOneWeek(clsDate& Date) { return IncreaseDateByXDays(7, Date); }
	clsDate& IncreaseDateByOneWeek() {
		return IncreaseDateByOneWeek(*this);
	}
	static	clsDate& IncreaseDateByXWeeks(int x, clsDate& Date) {
		for (int i = 0; i < x; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	clsDate& IncreaseDateByXWeeks(int x) {
		return IncreaseDateByXWeeks(x, *this);
	}
	static	clsDate& IncreaseDateByOneMonth(clsDate& Date) {
		short NumOfDaysInAMonth = NumOfDaysInMonth(Date.Month, Date.Year);
		return IncreaseDateByXDays(NumOfDaysInAMonth, Date);
		//if (Date.Month == 12) {
		//	Date.Month = 1;
		//	Date.Year++;
		//}
		//else { Date.Month++; }
		//short NumOfDaysInAMonth = NumOfDaysInMonth(Date.Month, Date.Year);

		//if (Date.Day > NumOfDaysInAMonth) {
		//	Date.Day = NumOfDaysInAMonth;
		//}
		//return Date;
	}
	clsDate& IncreaseDateByOneMonth() {
		return IncreaseDateByOneMonth(*this);
	}
	static	clsDate& IncreaseDateByXMonths(int x, clsDate& Date) {
		for (int i = 0; i < x; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	clsDate& IncreaseDateByXMonths(int x) {
		return IncreaseDateByXMonths(x, *this);
	}
	static	clsDate& IncreaseDateByOneYear(clsDate& Date) {
		//return IncreaseDateByXMonths(12,Date);
		Date.Year++;
		if (!isLeapYear(Date.Year))
		{
			if (Date.Month == 2 && Date.Day == 29)Date.Day == 28;
		}
		return Date;
	}
	clsDate& IncreaseDateByOneYear() {
		return IncreaseDateByOneYear(*this);
	}
	static	clsDate& IncreaseDateByXYears(int x, clsDate& Date) {
		for (int i = 0; i < x; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	clsDate& IncreaseDateByXYears(int x) {
		return IncreaseDateByXYears(x, *this);
	}
	static	clsDate& IncreaseDateByXYearsFaster(int x, clsDate& Date) {
		Date.Year += x;
		if (!isLeapYear(Date.Year))
		{
			if (Date.Month == 2 && Date.Day == 29)Date.Day == 28;
		}
		return Date;
	}
	clsDate& IncreaseDateByXYearsFaster(int x) {
		return IncreaseDateByXYearsFaster(x, *this);
	}
	static	clsDate& IncreaseDateByOneDecade(clsDate& Date) { return IncreaseDateByXYearsFaster(10, Date); }
	clsDate& IncreaseDateByOneDecade() {
		return IncreaseDateByOneDecade(*this);
	}
	static	clsDate& IncreaseDateByXDecades(int x, clsDate& Date) {
		for (int i = 0; i < x; i++)
		{
			Date = IncreaseDateByOneDecade(Date);

		}
		return Date;
	}
	clsDate& IncreaseDateByXDecades(int x) {
		return IncreaseDateByXDecades(x, *this);
	}
	static	clsDate& IncreaseDateByXDecadesFaster(int x, clsDate& Date) { return IncreaseDateByXYearsFaster(x * 10, Date); }
	clsDate& IncreaseDateByXDecadesFaster(int x) {
		return IncreaseDateByXDecadesFaster(x, *this);
	}
	static	clsDate& IncreaseDateByOneCentury(clsDate& Date) { return IncreaseDateByXYearsFaster(100, Date); }
	clsDate& IncreaseDateByOneCentury() {
		return IncreaseDateByOneCentury(*this);
	}
	static	clsDate& IncreaseDateByOneMillennium(clsDate& Date) { return IncreaseDateByXYearsFaster(1000, Date); }
	clsDate& IncreaseDateByOneMillennium() {
		return IncreaseDateByOneMillennium(*this);
	}
	static	bool IsFristDay(clsDate& Date) {
		return Date.Day == 1;

	}
	bool IsFristDay() {
		return   IsFristDay(*this);
	}
	static	bool IsFristMonth(clsDate& Date) {
		return Date.Month == 1;
	}
	bool IsFristMonth() {
		return   IsFristMonth(*this);
	}
	static	clsDate& DecreaseDateByOneDay(clsDate& Date) {
		if (!IsFristDay(Date)) { Date.Day -= 1; }
		else if (!IsFristMonth(Date)) {
			Date.Month -= 1;
			Date.Day = NumOfDaysInMonth(Date.Month, Date.Year);

		}
		else {
			Date.Year -= 1;
			Date.Month = 12;
			Date.Day = 31;
			//Date.Day = NumOfDaysInMonth(Date.Month, Date.Year);
		}
		return Date;
	}
	clsDate& DecreaseDateByOneDay() {
		return DecreaseDateByOneDay(*this);
	}
	static	clsDate& DecreaseDateByXDays(int x, clsDate& Date) {
		for (int i = 0; i < x; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate& DecreaseDateByXDays(int x) {
		return DecreaseDateByXDays(x, *this);
	}
	static	clsDate& DecreaseDateByOneWeek(clsDate& Date) { return DecreaseDateByXDays(7, Date); }
	clsDate& DecreaseDateByOneWeek() {
		return DecreaseDateByOneWeek(*this);
	}
	static	clsDate& DecreaseDateByXWeeks(int x, clsDate& Date) {
		for (int i = 0; i < x; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	clsDate& DecreaseDateByXWeeks(int x) {
		return DecreaseDateByXWeeks(x, *this);
	}
	static	clsDate& DecreaseDateByOneMonth(clsDate& Date) {
		short NumOfDaysInAMonth = NumOfDaysInMonth(Date.Month, Date.Year);
		return DecreaseDateByXDays(NumOfDaysInAMonth, Date);
		//if (Date.Month == 1) {
		//	Date.Month = 12;
		//	Date.Year--;
		//}
		//else { Date.Month--; }
		//short NumOfDaysInAMonth = NumOfDaysInMonth(Date.Month, Date.Year);
		//if (Date.Day > NumOfDaysInAMonth) { Date.Day = NumOfDaysInAMonth; }
		//return Date;
	}
	clsDate& DecreaseDateByOneMonth() {
		return DecreaseDateByOneMonth(*this);
	}
	static	clsDate& DecreaseDateByXMonths(int x, clsDate& Date) {
		for (int i = 0; i < x; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	clsDate& DecreaseDateByXMonths(int x) {
		return DecreaseDateByXMonths(x, *this);
	}
	static	clsDate& DecreaseDateByOneYear(clsDate& Date) {
		//return DecreaseDateByXMonths(12,Date);
		Date.Year--;
		if (!isLeapYear(Date.Year))
		{
			if (Date.Month == 2 && Date.Day == 29)Date.Day == 28;
		}
		return Date;
	}
	clsDate& DecreaseDateByOneYear() {
		return DecreaseDateByOneYear(*this);
	}
	static	clsDate& DecreaseDateByXYears(int x, clsDate& Date) {
		for (int i = 0; i < x; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	clsDate& DecreaseDateByXYears(int x) {
		return DecreaseDateByXYears(x, *this);
	}
	static	clsDate& DecreaseDateByXYearsFaster(int x, clsDate& Date) {
		Date.Year -= x;
		if (!isLeapYear(Date.Year))
		{
			if (Date.Month == 2 && Date.Day == 29)Date.Day == 28;
		}
		return Date;
	}
	clsDate& DecreaseDateByXYearsFaster(int x) {
		return DecreaseDateByXYearsFaster(x, *this);
	}
	static	clsDate& DecreaseDateByOneDecade(clsDate& Date) { return DecreaseDateByXYearsFaster(10, Date); }
	clsDate& DecreaseDateByOneDecade() {
		return DecreaseDateByOneDecade(*this);
	}
	static	clsDate& DecreaseDateByXDecades(int x, clsDate& Date) {
		for (int i = 0; i < x; i++)
		{
			Date = DecreaseDateByOneDecade(Date);

		}
		return Date;
	}
	clsDate& DecreaseDateByXDecades(int x) {
		return DecreaseDateByXDecades(x, *this);
	}
	static	clsDate& DecreaseDateByXDecadesFaster(int x, clsDate& Date) {
		return DecreaseDateByXYearsFaster(x * 10, Date);
	}
	clsDate& DecreaseDateByXDecadesFaster(int x) {
		return DecreaseDateByXDecadesFaster(x, *this);
	}
	static	clsDate& DecreaseDateByOneCentury(clsDate& Date) { return DecreaseDateByXYearsFaster(100, Date); }
	clsDate& DecreaseDateByOneCentury() {
		return DecreaseDateByOneCentury(*this);
	}
	static	clsDate& DecreaseDateByOneMillennium(clsDate& Date) { return DecreaseDateByXYearsFaster(1000, Date); }
	clsDate& DecreaseDateByOneMillennium() {
		return DecreaseDateByOneMillennium(*this);
	}
	static	bool IsEndOfWeek(clsDate& Date) {
		//6=>saturday and 0=>sunday
		return DayOfWeekOrderByGergorianCalender(Date) == 6;
	}
	bool IsEndOfWeek() {
		return IsEndOfWeek(*this);
	}
	static	bool IsWeekEnd(clsDate& Date) {
		//6=>saturday , 5=>friday and 0=>sunday
		short DayIndex = DayOfWeekOrderByGergorianCalender(Date);
		return DayIndex == 6 || DayIndex == 5;
	}
	bool IsWeekEnd() {
		return IsWeekEnd(*this);
	}
	static	bool IsBusinessDay(clsDate& Date) {
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	}
	static	short DaysUntilTheEndOfWeek(clsDate& Date) {
		return 6 - DayOfWeekOrderByGergorianCalender(Date);
	}
	short DaysUntilTheEndOfWeek() {
		return DaysUntilTheEndOfWeek(*this);
	}
	static	short DaysUntilTheEndOfMonth(clsDate& Date) {
		return  NumOfDaysInMonth(Date.Month, Date.Year) - Date.Day;
	}
	short DaysUntilTheEndOfMonth() {
		return DaysUntilTheEndOfMonth(*this);
	}
	static	short DaysUntilTheEndOfYear(clsDate& Date) {
		return  NumOfDaysInYear(Date.Year) - NumOfDaysFromBeginingOfYear(Date);
	}
	short DaysUntilTheEndOfYear() {
		return DaysUntilTheEndOfYear(*this);
	}
	static	short CalculateVacationDays(clsDate& FromDate, clsDate& ToDate) {
		short VacationDays = 0;
		if (ComparingTwoDate(FromDate, ToDate) == enComparing::After)return 0;
		while (ComparingTwoDate(FromDate, ToDate) != enComparing::Equal)
		{
			if (IsBusinessDay(FromDate)) 				VacationDays++;
			FromDate = IncreaseDateByOneDay(FromDate);

		}
		return VacationDays;
	}
	short CalculateVacationDays(clsDate& ToDate) {
		return CalculateVacationDays(*this, ToDate);
	}
	static	clsDate& CalculateVacationReturnDate(clsDate& DateFrom, short VacationDays) {
		int counter = 0;
		while (VacationDays >= counter)
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
			if (IsBusinessDay(DateFrom)) {
				counter++;
			}

		}
		return DateFrom;
	}
	clsDate& CalculateVacationReturnDate(short VacationDays) {
		return CalculateVacationReturnDate(*this, VacationDays);
	}
	static	clsDate& CalculateVacationReturnDate2(clsDate& DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		//in case the data  is weekend keep adding one day util you reach business day
		//we get rid of all weekends before the first business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}
	clsDate& CalculateVacationReturnDate2(short VacationDays) {
		return CalculateVacationReturnDate2(*this, VacationDays);
	}



	clsDate() {
		clsDate Date = GetSystemDate();
		_Day = Date.Day;
		_Month = Date.Month;
		_Year = Date.Year;
	}
	clsDate(short Day, short Month, short Year) {
		_Day = Day;
		_Month = Month;
		_Year = Year;
	};
	clsDate(short NumOfDays, short Year) {
		clsDate Date = GetDateByNumOfDaysInYear(NumOfDays, Year);
		_Day = Date.Day;
		_Month = Date.Month;
		_Year = Date.Year;
	};
	clsDate(string strDate) {
		clsDate Date = StringToDate(strDate);
		_Day = Date.Day;
		_Month = Date.Month;
		_Year = Date.Year;
	}
};


class stPeriod {
	clsDate _From;
	clsDate _To;
public:
	static stPeriod ReadPeriod() {
		stPeriod P;
		cout << "\n Start Date: " << endl;
		P.From = clsDate::ReadDate();
		cout << "\n End Date: " << endl;
		P.To = clsDate::ReadDate();
		return P;
	};
	static bool IsOverlapPeriods(stPeriod P1, stPeriod P2) {
		enComparing ComparingP1FromWithP2From = P1.From.ComparingTwoDate(P2.From);
		enComparing ComparingP1ToWithP2To = P1.To.ComparingTwoDate(P2.To);
		enComparing ComparingP1FromWithP2To = P1.From.ComparingTwoDate(P2.To);
		enComparing ComparingP1ToWithP2From = P1.To.ComparingTwoDate(P2.From);
		//short
	/*	if (ComparingP1ToWithP2From == enComparing::Before || ComparingP1FromWithP2To == enComparing::After) { return true; }
		else { return false; }*/
		if (ComparingP1FromWithP2From == enComparing::Before
			&& ComparingP1ToWithP2To == enComparing::Before
			&& ComparingP1FromWithP2To == enComparing::Before
			&& ComparingP1ToWithP2From == enComparing::Before) {
			return false;
		}
		else if (
			ComparingP1FromWithP2From == enComparing::After
			&& ComparingP1ToWithP2To == enComparing::After
			&& ComparingP1FromWithP2To == enComparing::After
			&& ComparingP1ToWithP2From == enComparing::After) {
			return false;
		}
		else {
			return true;
		}
	}
	bool IsOverlapPeriods(stPeriod P2) {
		return   IsOverlapPeriods(*this, P2);
	}
	static int PeriodLengthInDays(stPeriod P1, bool IncludingEndDate = false) {
		return P1.From.GetDifferance2Date(P1.To, IncludingEndDate);
	}
	int PeriodLengthInDays(bool IncludingEndDate = false) {
		return PeriodLengthInDays(*this, IncludingEndDate);
	}
	static bool IsDateInPeriod(clsDate& Date, stPeriod P) {
		return ((P.From.IsDate1BeforeDate2(Date) || P.From.IsDate1EqualDate2(Date))
			&& (P.To.IsDate1EqualDate2(Date) || P.To.IsDate1AfterDate2(Date)));
	}
	bool IsDateInPeriod(clsDate& Date) {
		return   IsDateInPeriod(Date, *this);
	}
	static int CountOverlapDays(stPeriod P1, stPeriod P2) {
		int OverlapDays = 0;
		//IsDate1AfterDate2
		clsDate StartDateLoop = P1.From.IsDate1AfterDate2(P2.From) ? P1.From : P2.From;
		clsDate EndDateLoop = P1.To.IsDate1BeforeDate2(P2.To) ? P1.To : P2.To;
		if (IsOverlapPeriods(P1, P2)) {
			while (!clsDate::IsDate1AfterDate2(StartDateLoop, EndDateLoop)) {
				if (IsDateInPeriod(StartDateLoop, P2)) { OverlapDays++; }
				StartDateLoop = clsDate::IncreaseDateByOneDay(StartDateLoop);
			}
		}
		return OverlapDays;
	}
	int CountOverlapDays(stPeriod P2) {
		return    CountOverlapDays(*this, P2);
	}

	stPeriod(clsDate From, clsDate To) {
		_From = From;
		_To = To;
	}
	stPeriod() {
		stPeriod P = ReadPeriod();
		_From = P.From;
		_To = P.To;
	}


	//setter and getter:-
	clsDate GetFrom() { return _From; };
	void SetFrom(clsDate From) { _From = From; };
	__declspec(property(get = GetFrom, put = SetFrom))clsDate From;
	//setter and getter:-
	clsDate GetTo() { return _To; };
	void SetTo(clsDate To) { _To = To; };
	__declspec(property(get = GetTo, put = SetTo))clsDate To;

};

void DateEx() {
	clsDate Date1("17/8/2024");
	Date1.Print();

	clsDate Date2(17, 8, 2024);
	Date2.Print();

	clsDate Date3(230, 2024);
	Date3.Print();

	clsDate Date4;
	Date4.Print();

	Date4.PrintMonthCalender();
	Date4.PrintMonthYearCalender(); 

}
