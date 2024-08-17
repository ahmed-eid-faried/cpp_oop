#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class clsString
{
	string _Value;


public:
	//constrators:-
	clsString() { _Value = ""; };
	clsString(string Value) { _Value = Value; };

	//setter and getter:-
	string GetValue() { return _Value; };
	void SetValue(string Value) { _Value = Value; };
	__declspec(property(get = GetValue, put = SetValue))string Value;

	//Static Functions:-
	static void PrintFirstLetterOfEachWord(string text) {
		bool IsAfterSpace = false;
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] == ' ') {
				IsAfterSpace = true;
			}
			else if ((text[i] != ' ' && IsAfterSpace) || (text[i] != ' ' && i == 0))
			{
				cout << text[i] << endl;
				IsAfterSpace = false;

			}
			else {
				IsAfterSpace = false;

			}

		}
		cout << endl;

	}
	static string UpperFirstLetterOfEachWord(string text) {
		bool IsAfterSpace = false;
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] == ' ') {
				IsAfterSpace = true;
			}
			else if ((text[i] != ' ' && IsAfterSpace) || (text[i] != ' ' && i == 0))
			{
				//cout << text[i] << endl;
				//text[i] = text[i] - char(32);
				text[i] = toupper(text[i]);
				IsAfterSpace = false;

			}
			else {
				IsAfterSpace = false;

			}

		}
		cout << endl;
		return text;

	}
	static 	string LowerFirstLetterOfEachWord(string text) {
		bool IsAfterSpace = true;
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ' && IsAfterSpace) {
				text[i] = tolower(text[i]);
			}
			IsAfterSpace = (text[i] == ' ');
		}
		cout << endl;
		return text;

	}
	static	string LowerAllString(string text) {
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = tolower(text[i]);

		}
		cout << endl;
		return text;

	}
	static string UpperAllString(string text) {
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = toupper(text[i]);

		}
		cout << endl;
		return text;

	}
	static 	char InvertLetterCase(char Char) {
		Char = islower(Char) ? toupper(Char) : tolower(Char);
		//Char = (Char > char(90)) ? toupper(Char) : tolower(Char);
		return Char;
	}
	static 	string InvertAllLettersCase(string text) {
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = InvertLetterCase(text[i]);
			//text[i] = islower(text[i]) ? toupper(text[i]) : tolower(text[i]);
			//text[i] = (text[i] > char(90)) ? toupper(text[i]) : tolower(text[i]);

		}
		return text;

	}
	static int CountCapitalLetters(string text) {
		int Conter = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (isupper(text[i]))Conter++;
		}
		return Conter;
	}
	static int CountSmallLetters(string text) {
		int Conter = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (islower(text[i]))Conter++;
		}
		return Conter;
	}
	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
	static int CountLetters(string text, enWhatToCount WhatToCount = enWhatToCount::All) {
		switch (WhatToCount)
		{
		case enWhatToCount::All:
			return text.length();
		case enWhatToCount::CapitalLetters:
			return CountCapitalLetters(text);
		case enWhatToCount::SmallLetters:
			return CountSmallLetters(text);

		default:
			return 0;
		}
	}
	//static	int CountSpecificLetter(string text, char Ch1) {
	//	int Conter = 0;
	//	for (int i = 0; i < text.length(); i++)
	//	{
	//		if (text[i] == Ch1)Conter++;
	//	}
	//	return Conter;
	//}
	static 	int CountSpecificLetter(string text, char Ch1, bool IsMatchCase = true) {
		int Conter = 0;
		char InvertLetter = InvertLetterCase(Ch1);
		for (int i = 0; i < text.length(); i++)
		{
			if (
				IsMatchCase ? (text[i] == Ch1) :
				(text[i] == Ch1 || text[i] == InvertLetter)
				)Conter++;

			/*	if (
					IsMatchCase ? (text[i] == Ch1) :
					(tolower(text[i]) == tolower(Ch1))
					)Conter++;*/
		}
		return Conter;
	}
	static bool IsVowel(char Ch1) {
		char VowelLetters[5] = { 'a','e','i','o','u' };

		for (int i = 0; i < 5; i++)
		{
			if (VowelLetters[i] == tolower(Ch1))return true;
		}
		return false;
	}
	static int CountVowels(string text) {
		int Conter = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (IsVowel(text[i]))Conter++;
		}
		return Conter;
	}
	static void PrintVowels(string text) {
		for (int i = 0; i < text.length(); i++)
		{
			if (IsVowel(text[i])) {
				cout << setw(3) << text[i];
			}
		}
	}
	static 	void PrintEachWordInString(string S1) {
		string delim = " ";
		int position = 0;
		string subWord = "";
		while ((position = S1.find(delim)) != string::npos)
		{
			subWord = S1.substr(0, position);
			if (subWord != "")cout << subWord << endl;
			S1.erase(0, position + delim.length());
		}
		//last word in string
		if (S1 != "")cout << S1 << endl;
	}
	static 	int CountWords(string S1) {
		string delim = " ";
		int position = 0;
		string subWord = "";
		int counter = 0;
		while ((position = S1.find(delim)) != string::npos)
		{
			subWord = S1.substr(0, position);
			if (subWord != "")counter++;
			S1.erase(0, position + delim.length());
		}
		//last word in string
		if (S1 != "")counter++;
		return counter;
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
 	static string TrimLeft(string S1) {
		char delim = ' ';
		vector<string> listWords;
		for (int i = 0; i < S1.length(); i++)
		{
			if (delim != S1[i]) {
				S1.erase(0, i);
				return S1;
			}
		}
	}
	static string TrimRight(string S1) {
		char delim = ' ';
		vector<string> listWords;
		for (int i = S1.length() - 1; i >= 0; i--)
		{
			if (delim != S1[i]) {
				S1.erase(i, S1.length());
				return S1;
			}
		}
	}
	static string Trim(string S1) {
		return TrimRight(TrimLeft(S1));
	}
	//static string  JoinString(vector<string> listWords, string delim = " ") {
	//	string S1 = "";
	//	for (int i = 0; i < listWords.size(); i++)
	//	{
	//		S1 += listWords[i];
	//		if (i < listWords.size() - 1)			S1 += delim;
	//	}
	//	return S1;
	//}
	static string  JoinString(vector<string> listWords, string delim = " ") {
		string S1 = "";
		for (string i : listWords)
		{
			S1 += i + delim;
		}
		return S1.substr(0, S1.length() - (delim.length()));
	}
	static string  JoinString(string  listWords[100], short length, string delim = " ") {
		string S1 = "";
		for (int i = 0; i < length; i++)
		{
			S1 += listWords[i];
			if (i < length - 1)			S1 += delim;
		}
		return S1;
	}
	static void PrintVectorString(vector<string> listWords) {
		cout << "listWords (vector) ==>> " << "[ ";
		for (int i = 0; i < listWords.size(); i++)
		{
			cout << listWords[i] << " ";
		}
		cout << ']' << endl;
	}
	static void PrintVectorString(string  listWords[100], short length) {
		cout << "listWords (vector) ==>> " << "[ ";
		for (int i = 0; i < length; i++)
		{
			cout << listWords[i] << " ";
		}
		cout << ']' << endl;
	}
	static string  ReverseJoinString(vector<string> listWords, string delim = " ") {
		string S1 = "";
		vector<string> ::iterator iter = listWords.end();
		while (iter != listWords.begin())
		{
			--iter;
			S1 += *iter + delim;
		}
		return S1.substr(0, S1.length() - (delim.length()));
	}
	static string ReverseWordsInString(string S1, string delim = " ") {
		return ReverseJoinString(Split(S1, delim), delim);
	}
	static void PrintReverseVectorString(vector<string> listWords) {
		cout << " ===>>> ";
		for (int i = listWords.size() - 1; i >= 0; i--)
		{
			cout << listWords[i] << " ";
		}
		cout << endl;

	}
	static string ReplaceWord(string S1, string  StringToReplace, string ReplaceTo) {
		int position = S1.find(StringToReplace);
		int counter = 0;
		while (position != string::npos)
		{
			S1 = S1.replace(position, StringToReplace.length(), ReplaceTo);
			position = S1.find(StringToReplace);
		}
		return S1;
	}
	static 	string ReplaceString(string S1, int position, int  length, string ReplaceTo) {
		int indexOfReplaceTo = 0;
		for (int i = position; i <= length + position; i++)
		{
			S1[i] = ReplaceTo[indexOfReplaceTo];
			indexOfReplaceTo++;
		}

		return S1;
	}
	static string ReplaceWordsUsingSplit(string S1, string  StringToReplace, string ReplaceTo) {
		vector<string>vString = Split(S1, StringToReplace);
		S1 = JoinString(vString, ReplaceTo);
		return S1;
	}
	static string ReplaceWordsUsingSplit(string S1, string  StringToReplace, string ReplaceTo, bool IsMatchedCase) {
		vector<string>vString = Split(S1, " ");
		for (string& S : vString)
		{
			if (IsMatchedCase) {
				if (S == StringToReplace)S = ReplaceTo;
			}
			else {
				if (LowerAllString(S) == LowerAllString(StringToReplace))S = ReplaceTo;

			}
		}
		S1 = JoinString(vString, " ");
		return S1;
	}
	static 	string  RemovePunctuations(string S1) {
		string str = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
				str += S1[i];
		}
		return str;
	}
	static int Length(string S1) {
		return S1.length();
	}

	//Objected Functions:-
	void PrintFirstLetterOfEachWord() {
		return PrintFirstLetterOfEachWord(_Value);
	}
	void UpperFirstLetterOfEachWord() {
		_Value = UpperFirstLetterOfEachWord(_Value);
	}
	void LowerFirstLetterOfEachWord() {
		_Value = LowerFirstLetterOfEachWord(_Value);
	}
	void LowerAllString() {
		_Value = LowerAllString(_Value);
	}
	void UpperAllString() {
		_Value = UpperAllString(_Value);
	}
	//char InvertLetterCase() 
	void InvertAllLettersCase() {
		_Value = InvertAllLettersCase(_Value);
	}
	int CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}
	int CountSmallLetters() {
		return CountSmallLetters(_Value);
	}
	int CountLetters(enWhatToCount WhatToCount = enWhatToCount::All) {
		return CountLetters(_Value, WhatToCount);
	}
	//int CountSpecificLetter(char Ch1) 
	int CountSpecificLetter(char Ch1, bool IsMatchCase = true) {
		return  CountSpecificLetter(_Value, Ch1, IsMatchCase);
	}
	// bool IsVowel(char Ch1)
	int CountVowels() {
		return   CountVowels(_Value);
	}
	void PrintVowels() {
		return   PrintVowels(_Value);
	}
	void PrintEachWordInString() {
		return   PrintEachWordInString(_Value);
	}
	int CountWords() {
		return 	  CountWords(_Value);
	}
	vector<string> Split(string delim = " ") {
		return   Split(_Value, delim);
	}
 
	void TrimLeft() {
		_Value = TrimLeft(_Value);
	}
	void TrimRight() {
		_Value = TrimRight(_Value);
	}
	void Trim() {
		_Value = Trim(_Value);
	}
 	void ReverseWordsInString(string delim = " ") {
		_Value = ReverseWordsInString(_Value, delim);
	}
 	void ReplaceWord(string  StringToReplace, string ReplaceTo)
	{
		_Value = ReplaceWord(_Value, StringToReplace, ReplaceTo);
	}
	void ReplaceString(int position, int  length, string ReplaceTo) {
		_Value = ReplaceString(_Value, position, length, ReplaceTo);
	}
	void ReplaceWordsUsingSplit(string  StringToReplace, string ReplaceTo) {
		_Value = ReplaceWordsUsingSplit(_Value, StringToReplace, ReplaceTo);
	}
	void ReplaceWordsUsingSplit(string  StringToReplace, string ReplaceTo, bool IsMatchedCase) {
		_Value = ReplaceWordsUsingSplit(_Value, StringToReplace, ReplaceTo, IsMatchedCase);
	}
	void  RemovePunctuations() {
		_Value = RemovePunctuations(_Value);
	}
	int Length() {
		return Length(_Value);
	}
};



void ClsStringExample() {
	clsString String1;


	clsString String2("Ahmed");

	String1.Value = "Faten Ahmed";

	cout << "String1 = " << String1.Value << endl;
	cout << "String2 = " << String2.Value << endl;

	cout << "Number of words: " << String1.CountWords() << endl;

	cout << "Number of words: " << String1.CountWords("Fadi ahmed rateb omer") << endl;

	cout << "Number of words: " <<
		clsString::CountWords("Ahmed Eid Abu-Hadhoud") << endl;

	//----------------
	clsString String3("hi how are you?");

	cout << "String 3 = " << String3.Value << endl;

	cout << "String Length = " << String3.Length() << endl;

	String3.UpperFirstLetterOfEachWord();
	cout << String3.Value << endl;

	//----------------

	String3.LowerFirstLetterOfEachWord();
	cout << String3.Value << endl;

	//----------------

	String3.UpperAllString();
	cout << String3.Value << endl;

	//----------------

	String3.LowerAllString();
	cout << String3.Value << endl;

	//----------------

	cout << "After inverting a : "
		<< clsString::InvertLetterCase('a') << endl;

	//----------------

	String3.Value = "AbCdEfg";

	String3.InvertAllLettersCase();
	cout << String3.Value << endl;

	String3.InvertAllLettersCase();
	cout << String3.Value << endl;

	//----------------

	cout << "Capital Letters count : "
		<< clsString::CountLetters("Ahmed Abu-Hadhoud", clsString::CapitalLetters)
		<< endl << endl;

	//----------------

	String3.Value = "Welcome to Jordan";
	cout << String3.Value << endl;

	cout << "Capital Letters count :" << String3.CountCapitalLetters() << endl;

	//----------------

	cout << "Small Letters count :" << String3.CountSmallLetters() << endl;

	//----------------

	cout << "vowels count :" << String3.CountVowels() << endl;

	//----------------

	cout << "letter E count :" << String3.CountSpecificLetter('E', false) << endl;

	//----------------

	cout << "is letter u vowel? " << clsString::IsVowel('a')
		<< endl;

	//----------------

	cout << "Words Count" << String3.CountWords()
		<< endl;

	//----------------


	vector<string> vString;
	vString = String3.Split();

	cout << "\nTokens = " << vString.size() << endl;

	for (string& s : vString)
	{
		cout << s << endl;
	}

	//----------------

	//Tirms
	String3.Value = "    Ahmed Mady     ";
	cout << "\nString     = " << String3.Value;

	String3.Value = "    Ahmed Mady     ";
	String3.TrimLeft();
	cout << "\n\nTrim Left  = " << String3.Value;

	//----------------

	String3.Value = "    Ahmed Mady     ";
	String3.TrimRight();
	cout << "\nTrim Right = " << String3.Value;

	//----------------

	String3.Value = "    Ahmed Mady     ";
	String3.Trim();
	cout << "\nTrim       = " << String3.Value;

	//----------------

	//Joins
	vector<string> vString1 = { "Ahmed","Faid","Faten","Maher" };

	cout << "\n\nJoin String From Vector: \n";
	cout << clsString::JoinString(vString1, " ");


	string arrString[] = { "Ahmed","Faid","Faten","Maher" };

	cout << "\n\nJoin String From array: \n";
	cout << clsString::JoinString(arrString, 4, " ");

	//----------------

	String3.Value = "Ahmed Eid Mady";
	cout << "\n\nString     = " << String3.Value;

	String3.ReverseWordsInString();
	cout << "\nReverse Words : " << String3.Value
		<< endl;

	//---------------

	String3.Value = "Ahmed Eid Mady";
	String3.ReplaceWord("Ahmed", "Sari");
	cout << "\nReplace : " << String3.Value << endl;

	//---------------

	String3.Value = "This is: a sample text, with punctuations.";
	cout << "\n\nString     = " << String3.Value;

	String3.RemovePunctuations();
	cout << "\nRemove Punctuations : " << String3.Value
		<< endl;


};
