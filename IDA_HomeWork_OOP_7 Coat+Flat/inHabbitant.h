#pragma once
#include <string>
#include <iostream>
#include "Service functions.h"


class inHabbitant
{
	std::string _FIO;
	int _birth_year;
	//enum sex {male=1, female=2};
	//sex sex_1;
	char _sex = 1; //1 male 2 female
public:
	//inHabbitant (std::string FIO, int birth_year, sex { male, female })
	inHabbitant(std::string FIO, int birth_year, char sex);
	inHabbitant();
	inHabbitant(char random_flag);
	inHabbitant(inHabbitant* inHabbitant_obj);
	void ShowInfo();
};