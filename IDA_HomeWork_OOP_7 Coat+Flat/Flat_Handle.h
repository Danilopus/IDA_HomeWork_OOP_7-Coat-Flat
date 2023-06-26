#pragma once
#include <iostream>
#include "Flat_Container.h"
#include "Flat.h"
#include "Flat_UnitTest.h"


class Flat_Handle
{
	static std::map <int, std::string> keycodes;
	static std::string console_clear;
	static std::string big_space;
	static std::map <int, int> codes_of_digits;		
public:
	static std::map <int, std::string> codes_of_operation;

	// Shows ---------------------------------------------------------------	
	static void ShowClassInformation(std::string class_name)
	{
		std::cout << "\n\n***\t" << class_name << " class info:\n";
		std::cout << Flat::Open_Interface_Info();
		ShowAvailableOperations();
	}	
	static void ShowAvailableOperations()
	{
		std::vector <int>& methods = Flat::Get_Operation_Info();

		std::cout << "\n\nOverloaded operations:";
		for (int i = 0; i < methods.size(); i++)
			std::cout << "\n" << i + 1 << ") " << codes_of_operation[methods[i]];
		delete& methods;
	}

	// Inputs handle -------------------------------------------------------	

	static int Mode_Input_Handle()
	{
		std::cout << "\nChoose mode :";
		std::cout << "\n1. Class info";
		std::cout << "\n2. SELF test mode";
		std::cout << "\n3. Interactive mode\n";

		switch (_getch_to_int(1, 3))
		{
		case -1: return -1;
		case 1: ShowClassInformation("Flat"); break;
		case 2: std::cout << Flat_UnitTest::main_test("Flat"); break;
		//case 3: UserChoiceHandle_getch; break;
		case 3: under_constraction(); break;
		}
		return 0;
	}
	static int _getch_to_int(int minimum = 0, int maximum = 9);
	static void under_constraction()
	{
		std::cout << "\n\n***\tUnder construction/Not enough time\t***\n\n";
	}

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

	static Flat* Get_Operand_getch(int Operand_number);
	static Flat& Get_Operand_getline(int Operand_number);
	static Flat& New_money_holder_input();

	static int Check_method_input_getch();
	static int Check_action_input_getline();

	static void Operation_module(int action, Flat& Operand_1, Flat& Operand_2);
	static void Operation_module(int action, Flat& Operand_1, double Operand_2);
};

