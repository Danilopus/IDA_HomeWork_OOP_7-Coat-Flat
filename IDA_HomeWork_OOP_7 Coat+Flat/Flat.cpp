#include "Flat.h"

int Flat::_flat_number_counter=0;

//::::::::::::::::::Flat::Flat::Flat::::::::::::::::::
Flat::Flat(int max_inHabbitans)
{
	int inHabbitans_amount = Get_Random(max_inHabbitans / 2, max_inHabbitans + 1);
	for (int i = 0; i < inHabbitans_amount; i++)
	{
		inHabbitant* tmp_ptr = new inHabbitant(1);
		inHabbitant_list_vct.push_back(tmp_ptr);
	}
	_flat_number = ++_flat_number_counter; //создаем номера квартир по порядку
	_area = Get_Random(15.0 * inHabbitans_amount, 30.0 * inHabbitans_amount);
	_price = _area * Get_Random(5e5, 15e5);
}
void Flat::ShowInfo()
{
	std::cout << "\nFlat number " << _flat_number;
	std::cout << "\nArea        " << _area;
	std::cout << "\nPrice        " << _price	
	<< "\nDetailed inHabbitans info:\n";
	for (int i = 0; i < inHabbitant_list_vct.size(); i++)
	{
		std::cout << "[" << i + 1 << "]";
		inHabbitant_list_vct[i]->ShowInfo();
	}
}
std::string Flat::Open_Interface_Info()
{
	std::string Open_Interface_Info;
	Open_Interface_Info += "\nConstructors:\n- Random (int max_inHabbitant)";
	Open_Interface_Info += "\n\nMethods:";
	Open_Interface_Info += "\n1) GetFlatNumber()";
	Open_Interface_Info += "\n2) GetinHabbitansAmount()";
	Open_Interface_Info += "\n3) ShowInfo(double)";
	Open_Interface_Info += "\n4) AddNewinHabbitant()";
	Open_Interface_Info += "\n5) DeleteinHabbitant(int)";

	return Open_Interface_Info;
}
std::vector<int>& Flat::Get_Operation_Info()
{
	//codes_of_operation
	//{ {1, " + "}, { 2," - " }, { 3," * " }, { 4, " / " }, { 5, " * " },
	//	{ 6," / " }, { 7, " > " }, { 8," < " }, { 9," = " }, { 0, "==" },
	//	{ 11, " ++" } /*prefix*/, { 12, "++ " } /*postfix*/, { 13, " --" }, { 14, "-- " }, { 15, " +" }, { 16, " -" } };

	std::vector <int>* available_operations = new std::vector <int>{ 7 /* > */, 8 /* < */, 9 /* = */, 0/* == */ };
	return *available_operations;
}
void Flat::DeleteinHabbitant(int selected_inHabbitant_index)
{
	delete inHabbitant_list_vct[selected_inHabbitant_index];
	inHabbitant_list_vct.erase(inHabbitant_list_vct.begin() + selected_inHabbitant_index);
}
bool Flat::operator>(const Flat& obj) const
{
	if (_price > obj._price) return true;
	return false;
}
bool Flat::operator<(const Flat& obj) const
{
	if (_price < obj._price) return true;
	return false;
}
bool Flat::operator==(const Flat& obj) const
{
	if (_area == obj._area) return true;
	return false;
}
void Flat::operator=(const Flat& obj)
{
	//*this = obj;
	_area = obj._area;
	_price = obj._price;
}
Flat::~Flat()
{
	for (int i = 0; i < inHabbitant_list_vct.size(); i++)
	{
		delete inHabbitant_list_vct[i];
	}
}