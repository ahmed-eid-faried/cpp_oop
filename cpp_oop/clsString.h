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
	static 	string InvertAllStringLettersCase(string text) {
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
	//static	int CountLetterInString(string text, char Ch1) {
	//	int Conter = 0;
	//	for (int i = 0; i < text.length(); i++)
	//	{
	//		if (text[i] == Ch1)Conter++;
	//	}
	//	return Conter;
	//}
	static 	int CountLetterInString(string text, char Ch1, bool IsMatchCase = true) {
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
	static vector<string> SplitString(string S1, string delim = " ") {

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
	static void PrintVectorString(vector<string> listWords) {
		for (int i = 0; i < listWords.size(); i++)
		{
			cout << listWords[i] << endl;
		}
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
	static string ReverseWordsString(string S1, string delim = " ") {
		return ReverseJoinString(SplitString(S1, delim), delim);
	}
	static void PrintReverseVectorString(vector<string> listWords) {
		cout << " ===>>> ";
		for (int i = listWords.size() - 1; i >= 0; i--)
		{
			cout << listWords[i] << " ";
		}
		cout << endl;

	}
	static string ReplaceWordInStringUsingBuiltInFunction(string S1, string  StringToReplace, string ReplaceTo) {
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
	static string ReplaceWordInStringUsingSplit(string S1, string  StringToReplace, string ReplaceTo) {
		vector<string>vString = SplitString(S1, StringToReplace);
		S1 = JoinString(vString, ReplaceTo);
		return S1;
	}
	static string ReplaceWordInStringUsingSplit(string S1, string  StringToReplace, string ReplaceTo, bool IsMatchedCase) {
		vector<string>vString = SplitString(S1, " ");
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
	static 	string  RemovePunctuationsFromString(string S1) {
		string str = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
				str += S1[i];
		}
		return str;
	}


	//Objected Functions:-
	void PrintFirstLetterOfEachWord() {
		return PrintFirstLetterOfEachWord(_Value);
	}
	string UpperFirstLetterOfEachWord() {
		return UpperFirstLetterOfEachWord(_Value);
	}
	string LowerFirstLetterOfEachWord() {
		return LowerFirstLetterOfEachWord(_Value);
	}
	string LowerAllString() {
		return LowerAllString(_Value);
	}
	string UpperAllString() {
		return UpperAllString(_Value);
	}
	//char InvertLetterCase() 
	string InvertAllStringLettersCase(string text) {
		return InvertAllStringLettersCase(_Value);
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
	//int CountLetterInString(char Ch1) 
	int CountLetterInString(char Ch1, bool IsMatchCase = true) {
		return  CountLetterInString(_Value, Ch1, IsMatchCase);
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
	vector<string> SplitString(string delim = " ") {
		return   SplitString(_Value, delim);
	}
	void PrintVectorString(vector<string> listWords) {
		return PrintVectorString(listWords);
	}
	string TrimLeft() {
		return    TrimLeft(_Value);
	}
	string TrimRight() {
		return    TrimRight(_Value);
	}
	string Trim() {
		return    Trim(_Value);
	}
	//string  JoinString(vector<string> listWords, string delim = " ")  
	//string  JoinString(string  listWords[100], short length, string delim = " ")  
	void PrintVectorString(vector<string> listWords) {
		return   PrintVectorString(listWords);
	}
	void PrintVectorString(string  listWords[100], short length) {
		return    PrintVectorString(listWords, length);
	}
	//string  ReverseJoinString(vector<string> listWords, string delim = " ") 
	string ReverseWordsString(string delim = " ") {
		return   ReverseWordsString(_Value, delim);
	}
	void PrintReverseVectorString(vector<string> listWords) {
		return   PrintReverseVectorString(listWords);
	}
	string ReplaceWordInStringUsingBuiltInFunction(string  StringToReplace, string ReplaceTo)
	{
		return   ReplaceWordInStringUsingBuiltInFunction(_Value, StringToReplace, ReplaceTo);
	}
	string ReplaceString(int position, int  length, string ReplaceTo) {
		return  ReplaceString(_Value, position, length, ReplaceTo);
	}
	string ReplaceWordInStringUsingSplit(string  StringToReplace, string ReplaceTo) {
		return ReplaceWordInStringUsingSplit(_Value, StringToReplace, ReplaceTo);
	}
	string ReplaceWordInStringUsingSplit(string  StringToReplace, string ReplaceTo, bool IsMatchedCase) {
		return   ReplaceWordInStringUsingSplit(_Value, StringToReplace, ReplaceTo, IsMatchedCase);
	}
	string  RemovePunctuationsFromString(string S1) {
		return   RemovePunctuationsFromString(_Value);
	}

};

