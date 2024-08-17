#pragma once
#include <iostream>
#include <string>
using namespace std;
enum enDigit { SmallLetter = 1, CapitalLetter = 2, Digit = 3, SpecialCharacter = 4, MixChars = 5 };
class clsUtil {
public:
	static void Srand() {
		srand((unsigned)time(NULL));
	}
	static  int RandomNumber(int From, int To) {
		return (rand() % (To - From + 1)) + From;
	}
	static int  ReadPositiveNumber(string Message) {
		int Num;
		do {
			cout << Message;
			cin >> Num;
		} while (Num < 0);
		return  Num;
	}
	static enDigit SelectTypeCharacter() {
		cout << "Select Type Character TO Get Random: " << endl;
		cout << "(1) SmallLetter" << endl;
		cout << "(2) CapitalLetter" << endl;
		cout << "(3) Digit" << endl;
		cout << "(4) SpecialCharacter" << endl;
		cout << "(5) Mix Character" << endl;
		cout << "########################################################\n";
		return	(enDigit)ReadPositiveNumber("ENTER SELECTION: ");
	}
	static int GetRandomCharacter(enDigit Selection) {
		switch (Selection)
		{
		case enDigit::MixChars:
			return RandomNumber(33, 122);
		case enDigit::SmallLetter:
			return RandomNumber(97, 122);
		case enDigit::CapitalLetter:
			return RandomNumber(65, 90);
		case enDigit::Digit:
			return RandomNumber(48, 57);
		case enDigit::SpecialCharacter:
			return RandomNumber(33, 47);
		default:
			return RandomNumber(58, 64);
		}
	}
	static	string GenerateWord(enDigit Selection, short Num) {
		string Key = "";
		for (short i = 1; i <= Num; i++)
		{
			short Char = GetRandomCharacter(Selection);
			Key += char(Char);
		}
		return Key;
	}
	static	string GenerateKey(short Num = 16, enDigit Selection = enDigit::MixChars) {
		string Key = "";
		for (short i = 1; i <= Num; i++)
		{
			short Char = GetRandomCharacter(Selection);
			Key += char(Char);
			if (i % 4 == 0 && i != Num)		Key += '-';
		}
		return Key;
	}
	static void GenerateKeys(short Num, enDigit Selection) {
		for (short i = 0; i < Num; i++)
		{
			cout << "Key [" << i + 1 << "]: \t" << GenerateKey() << endl;
		}
	}
	static bool GuessPassword(string CorrectPassword) {
		string word = "";
		int Trials = 0;
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					word += char(i);
					word += char(j);
					word += char(k);
					Trials++;
					cout << "Trial [" << Trials << "]: " << word << endl;

					if ((CorrectPassword == word)) {
						cout << "-----------------------------------------------" << endl;
						cout << "-----------------------------------------------" << endl;
						cout << "PASSWORD IS " << word << endl;
						cout << "FOUND AFTER  " << Trials << " Trial(s)" << endl;
						return true;
					}
					word = "";
				}

			}

		}
	}
	static void Swap(int& Num1, int& Num2) {
		int Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}
	static void Swap(double& Num1, double& Num2) {
		double Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}
	static void Swap(string& str1, string& str2) {
		string Temp = str1;
		str1 = str2;
		str2 = Temp;
	}
	static void Swap(clsDate& Num1, clsDate& Num2) {
		clsDate Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}
	static void PrintArray(int Array[100], short Num, string Message = "Original Array") {
		cout << Message << ": \t";
		if (Num > 100)Num = 100;
		for (int i = 0; i < Num; i++)
		{
			cout << Array[i] << " ";
		}
		cout << endl;
	}
	static void FillArrayWithRandomNumbers(int Array[100], short  Length, int From, int To) {
		if (Length > 100)Length = 100;
		for (short i = 0; i < Length; i++)
		{
			Array[i] = RandomNumber(From, To);
		}
	}
	static void FillArrayWithRandomWords(string Array[100], short  Length, enDigit Selection, short Num) {
		if (Length > 100)Length = 100;
		for (short i = 0; i < Length; i++)
		{
			Array[i] = GenerateWord(Selection, Num);
		}
	}
	static void FillArrayWithRandomKeys(string Array[100], short  Length, enDigit Selection = enDigit::MixChars) {
		if (Length > 100)Length = 100;
		for (short i = 0; i < Length; i++)
		{
			Array[i] = GenerateKey(Selection);
		}
	}

 	static void ShuffleArray(int  Array[100], short ArrLength) {
		if (ArrLength > 100)ArrLength = 100;
		for (short i = 0; i < ArrLength; i++)
		{
			Swap(Array[RandomNumber(1, ArrLength) - 1], Array[RandomNumber(1, ArrLength) - 1]);
		}
	}
	static void ShuffleArray(string Array[], short ArrLength) {
		if (ArrLength > 100) ArrLength = 100;
		for (short i = 0; i < ArrLength; i++) {
			int index1 = RandomNumber(1, ArrLength) - 1;
			int index2 = RandomNumber(1, ArrLength) - 1;
			Swap(Array[index1], Array[index2]);
		}
	}


	static string EncryptText(string InputText, short EncryptionKey) {
		string word = "";
		for (int i = 0; i < InputText.length(); i++)
		{
			word += InputText[i] + char(i + EncryptionKey);
			//word += char((int)InputText[i] + EncryptionKey);

		}
		return  word;
	}
	static string DecryptText(string EncryptedText, short EncryptionKey) {
		string word = "";
		for (int i = 0; i < EncryptedText.length(); i++)
		{
			word += EncryptedText[i] - char(i + EncryptionKey);
			//word += char((int)EncryptedText[i] - EncryptionKey);

		}
		return  word;
	}
	static string Tabs(int num) {
		string tabs = "";
		for (int i = 0; i < num; i++)
		{
			tabs += '\t';
		}
		return tabs;
	}
};

void UtilEX() {
	clsUtil::Srand();
	cout << clsUtil::RandomNumber(1, 10) << endl;
	cout << clsUtil::GetRandomCharacter(enDigit::CapitalLetter) << endl;
	cout << clsUtil::GenerateWord(enDigit::MixChars, 8) << endl;
	cout << clsUtil::GenerateKey(enDigit::MixChars) << endl;
	clsUtil::GenerateKeys(10, enDigit::MixChars);

	cout << "\n";

	//Swap Int
	int x = 10, y = 20;
	cout << x << " " << y << endl;
	clsUtil::Swap(x, y);
	cout << x << " " << y << endl << endl;

	//Swap double
	double a = 10.5, b = 20.5;
	cout << a << " " << b << endl;
	clsUtil::Swap(a, b);
	cout << a << " " << b << endl << endl;

	//Swap String
	string s1 = "Ali", s2 = "Ahmed";
	cout << s1 << " " << s2 << endl;
	clsUtil::Swap(s1, s2);
	cout << s1 << " " << s2 << endl << endl;

	//Swap Dates
	clsDate d1(1, 10, 2022), d2(1, 1, 2022);
	cout << d1.DateToString() << " " << d2.DateToString() << endl;
	clsUtil::Swap(d1, d2);
	cout << d1.DateToString() << " " << d2.DateToString() << endl;

	//Shuffl Array

	//int array
	int Arr1[5] = { 1,2,3,4,5 };
	clsUtil::ShuffleArray(Arr1, 5);
	cout << "\nArray after shuffle:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << Arr1[i] << endl;
	}

	//string array
	string Arr2[5] = { "Ali","Fadi","Ahmed","Qasem","Khalid" };
	clsUtil::ShuffleArray(Arr2, 5);
	cout << "\nArray after shuffle:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << Arr2[i] << endl;
	}

	int Arr3[5];
	clsUtil::FillArrayWithRandomNumbers(Arr3, 5, 20, 50);
	cout << "\nArray after fill:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << Arr3[i] << endl;
	}


	string Arr4[5];
	clsUtil::FillArrayWithRandomWords(Arr4, 5, enDigit::MixChars, 8);
	cout << "\nArray after fill:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << Arr4[i] << endl;
	}


	string Arr5[5];
	clsUtil::FillArrayWithRandomKeys(Arr5, 5, enDigit::MixChars);
	cout << "\nArray after filling keys:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << Arr5[i] << endl;
	}

	cout << "\nText1 " << clsUtil::Tabs(5) << "Text2\n";

	const short EncryptionKey = 2; //this is the key.

	string TextAfterEncryption, TextAfterDecryption;
	string Text = "Mohammed Abu-Hadhoud";
	TextAfterEncryption = clsUtil::EncryptText(Text, EncryptionKey);
	TextAfterDecryption = clsUtil::DecryptText(TextAfterEncryption, EncryptionKey);

	cout << "\nText Before Encryption : ";
	cout << Text << endl;
	cout << "Text After Encryption  : ";
	cout << TextAfterEncryption << endl;
	cout << "Text After Decryption  : ";
	cout << TextAfterDecryption << endl;


}