#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>
#include <iomanip>
#include <cassert>
#include "OverCoat.h"
#include "UnitTest.h"


class Contain_and_Handle
{
	static std::vector <OverCoat*> _objects_list;
	static std::map <int, std::string> codes_of_operation;
public:
	
	static void Memory_Clean()
	{
		for (int i = 0; i < _objects_list.size(); i++)
			delete _objects_list[i];
		_objects_list.clear();

	}
	
	static void OverCoat_Initialisation(int random_number)
	{

		for (int i = 0; i < random_number; i++)
		{
			OverCoat* new_item = new OverCoat('rand');	
			_objects_list.push_back(new_item);
		}

	}

	// Shows ---------------------------------------------------------------	
	
	static void ShowAvailableObjects();
	static void OverCoat_ShowClassInformation(std::string class_name)
	{
		std::cout << "\n\n***\t" << class_name << " class info:\n";
		std::cout << OverCoat::Open_Interface_Info();
		ShowAvailableOperations();
	}
	static void ShowAvailableOperations()
	{		
		std::vector <int>& methods = OverCoat::Get_methods();

		std::cout << "\n\nOverloaded operations:";
		for (int i = 0; i < methods.size(); i++)
			std::cout <<"\n"<<i+1<<") " << codes_of_operation[methods[i]];
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
		case 1: OverCoat_ShowClassInformation("OverCoat"); break;
		case 2: std::cout << UnitTest::OverCoat_test(); break;
		case 3: under_constraction(); break;
		}
		//_getch();
		return 0;
		//return _getch_to_int(1,2);
	}
	static int _getch_to_int(int minimum = 0, int maximum = 9);
	static void under_constraction()
	{
		std::cout << "\n\n***\tUnder construction/Not enough time\t***\n\n";
	}
};



