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
void Flat::DeleteinHabbitant(int selected_inHabbitant_index)
{
	delete inHabbitant_list_vct[selected_inHabbitant_index];
	inHabbitant_list_vct.erase(inHabbitant_list_vct.begin() + selected_inHabbitant_index);
}
Flat::~Flat()
{
	for (int i = 0; i < inHabbitant_list_vct.size(); i++)
	{
		delete inHabbitant_list_vct[i];
	}
}