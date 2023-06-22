#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>
#include <iomanip>
#include <cassert>

class OverCoat
{
	std::string _name;
	enum type { Coat, Fur };
	int _size;	
public:
	// Constructors // Initialisation // Destructors // Memory Clean -------
	OverCoat(long long coins = 0, long long roubles = 0);
	//OverCoat() {}
	~OverCoat()
	{
		//std::cout << "Vector reallocates memory";
		//_getch();
	}
	static void Initialisation(int random_number)
	{
		for (int i = 0; i < random_number; i++)
			new OverCoat();
	}
	static void Memory_Clean();

	// Setters // Getters --------------------------------------------------
	OverCoat& Set_roubles(long long rubles);
	OverCoat& Set_coins(long long coins);
	long long Get_roubles() { return _roubles; }
	int Get_coins() { return _coins; }

	// Shows ---------------------------------------------------------------
	void ShowValues() { std::cout << *this; }
	//void ShowValues() { std::cout << this; }
	static void ShowMethods();
	static void ShowAvailableMoneyObjects();

	// Inputs handle -------------------------------------------------------	
		
	// getch модификация - удобный интерфейс ввода без нажатия Enter и с обработкой Esc, пока только для списков 0..9 (надо придумать как принимать одно- и двух-циферные значения в одном интерфейсе через _getch
	// getline модификация - c вводом произвольных чисел и конторолем ввода через функцию Get_Int_Positive(), ввод необходимо подтверждать Enter

	//for (;;)
	//{
	//	cout << "You are playing for:" << playtime << "seconds." << endl;
	//	cout << "You have " << bytes << " bytes." << endl;
	//	cout << "You are compiling " << bps << " bytes per second." << endl;
	//	cout << "Press a to buy assembler monkey (produces 1 byte per second)/(cost 10 bytes)" << endl;
	//	if (kbhit()) {  //is true when a key was pressed
	//		char c = getch();   //capture the key code and insert into c

	//		switch (c)
	//		{
	//		case 'a': bytes = bytes - 10; bps++; break;
	//		}
	//	}
	//	bytes = bytes + bps;
	//	playtime++;
	//	Sleep(1000);
	//	system("cls");
	//}

	static int UserChoiceHandle_getch();
	static int UserChoiceHandle_getline();

	static OverCoat* Get_Operand_getch(int Operand_number);
	static OverCoat& Get_Operand_getline(int Operand_number);
	static OverCoat& New_money_holder_input();

	static int Check_method_input_getch();
	static int Check_action_input_getline();

	static void Operation_module(int action, OverCoat& Operand_1, OverCoat& Operand_2);
	static void Operation_module(int action, OverCoat& Operand_1, double Operand_2);

	//Overload operators - reference returned -----------------------------------------

	//OverCoat* operator+(OverCoat & another_Money);
	OverCoat& operator+(const OverCoat& another_Money) const;
	OverCoat& operator-(const OverCoat& another_Money) const;
	OverCoat& operator*(const OverCoat& another_Money) const;
	OverCoat& operator*(double multiplier) const;
	OverCoat& operator/(double divider) const;
	double operator/(const OverCoat& another_Money) const;
	bool operator>(const OverCoat& another_Money) const;
	bool operator<(const OverCoat& another_Money) const;
	bool operator==(const OverCoat& another_Money) const;

	friend std::ostream& operator << (std::ostream& out, OverCoat* just_a_Money);
	friend std::ostream& operator << (std::ostream& out, OverCoat& Money_holder);
};