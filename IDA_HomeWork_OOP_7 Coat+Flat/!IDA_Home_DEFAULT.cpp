﻿// HomeWork template project v 5.0 // 22.06.2023 //

/*

Задание 1.
Создать класс Overcoat (верхняя одежда).
Реализовать перегруженные операторы:
1. Проверка на равенство типов одежды (операция = =).
2. Операцию присваивания одного объекта в другой
(операция =).
3. Сравнение по цене двух пальто одного типа (операция>)

Задание 2.
Создать класс Flat (квартира).
Реализовать перегруженные операторы:
1. Проверка на равенство площадей квартир (операция
==).
2. Операцию присваивания одного объекта в другой
(операция =).
3. Сравнение двух квартир по цене (операция>).

*/

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//My own headers
#include "Service functions.h"
#include "MainMenu.h"
#include "OverCoat.h"
#include "Contain_and_Handle.h"
#include "Flat_Handle.h"



// Homework OOP 07 ----------------------------------------------------	


//Task 1 Overcoat class demo with overloaded operators: = | == | < | > 
void Task_1(std::string name_of_task)
{
	Contain_and_Handle::OverCoat_Initialisation(Get_Random(5,10));

	do
	{		
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";					
	
		if (Contain_and_Handle::Mode_Input_Handle()) break;

		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
	Contain_and_Handle::Memory_Clean();
}

//Task 2
void Task_2(std::string name_of_task)
{
	do
	{
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";

		if (Flat_Handle::Mode_Input_Handle()) break;

		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
	Flat_Container::Memory_Clean();
}

//Task 3 
void Task_3() {}

//Task 4
void Task_4() {}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	srand(time(NULL));
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=60 lines=40"); 
	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 07: ");	// Homework name
	MainMenu.AddElement("Overcoat class demo with overloaded operators: = | == | < | > ");
	MainMenu.AddElement("Flat class demo with overloaded operators: = | == | < | > ");

	//MainMenu.AddElement("XXX");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

