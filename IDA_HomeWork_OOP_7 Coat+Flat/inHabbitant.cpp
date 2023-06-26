#include "inHabbitant.h"



std::string _f_NAMES_[]{ "Olga", "Svetlana", "Oxana", "Irina", "Marina", "Alexandra", "Natalya" };
std::string _m_NAMES_[]{ "Petr", "Daniil", "Oleg", "Igor", "Nikita", "Artem", "Sergio" };
std::string _f_SURNAMES_[]{ "Platonova", "Makarova", "Popova", "Ivanova", "Starodubceva", "Yachmeneva", "Kalmykova" };
std::string _m_SURNAMES_[]{ "Platonov", "Makarov", "Popov", "Ivanov", "Starodubcev", "Yachmenev", "Kalmykov" };


//::::::::::::::::::inHabbitant::inHabbitant::inHabbitant::::::::::::::::::
inHabbitant::inHabbitant()
{
	std::cout << "\nNew inHabbitant credentials:\n\nEnter FIO: ";
	getline(std::cin, _FIO);
	std::cout << "Enter birth_year: ";
	_birth_year = Get_Int_Positive();
	std::cout << "Enter sex: Male[1] or Female[2]?";
	_sex = Get_Int_Positive();
	//Street.AddinHabbitant();
}
inHabbitant::inHabbitant(char random_flag)
{
	_sex = Get_Random(1, 3);
	if (_sex == 1)
	{
		_FIO = _m_NAMES_[Get_Random(0, _m_NAMES_->size() - 1)] + " " + _m_SURNAMES_[Get_Random(0, _m_SURNAMES_->size() - 1)];
	}
	else
	{
		_FIO = _f_NAMES_[Get_Random(0, _f_NAMES_->size() - 1)] + " " + _f_SURNAMES_[Get_Random(0, _f_SURNAMES_->size() - 1)];
	}
	_birth_year = Get_Random(1950, 2023);
}
inHabbitant::inHabbitant(inHabbitant* inHabbitant_obj)
{
	_FIO = inHabbitant_obj->_FIO;
	_birth_year = inHabbitant_obj->_birth_year;
	_sex = inHabbitant_obj->_sex;
}
void inHabbitant::ShowInfo()
{
	std::cout << "\nFIO:        " << _FIO;
	std::cout << "\nBirth Year: " << _birth_year;
	if (_sex == 1)
		std::cout << "\nsex:        male";
	else
		std::cout << "\nsex:        female";
	std::cout << "\n\n";
}
