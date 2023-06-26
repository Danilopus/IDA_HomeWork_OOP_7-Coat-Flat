#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>
#include <iomanip>
#include "Flat.h"
#include "Flat_Handle.h";


class Flat_Container
{
		static std::vector <Flat*> _objects_list;
		static std::map <int, std::string> codes_of_operation2;
	public:


		// Constructors // Initialisation // Destructors // Memory Clean -------
		static void Initialisation(int random_number)
		{

			for (int i = 0; i < random_number; i++)
			{
				Flat* new_item = new Flat(7);
				_objects_list.push_back(new_item);
			}
		}
		static void Memory_Clean()
		{
			for (int i = 0; i < _objects_list.size(); i++)
				delete _objects_list[i];
			_objects_list.clear();

		}

		// Shows ---------------------------------------------------------------	
		static void ShowAvailableObjects();
		static void ShowClassInformation(std::string class_name)
		{
			std::cout << "\n\n***\t" << class_name << " class info:\n";
			std::cout << Flat::Open_Interface_Info();
			//ShowAvailableOperations();
		}

		/*static void ShowAvailableOperations()
		{
			std::vector <int>& methods = Flat::Get_Operation_Info();

			std::cout << "\n\nOverloaded operations:";
			for (int i = 0; i < methods.size(); i++)
				std::cout << "\n" << i + 1 << ") " << Flat_Handle::codes_of_operation[methods[i]];
			delete& methods;
		}*/



};

