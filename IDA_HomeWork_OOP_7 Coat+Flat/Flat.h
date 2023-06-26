#pragma once
#include <vector>

#include "inHabbitant.h"
#include "Service functions.h"

class Flat
{
	int _flat_number;
	double _area; //sqrmeters
	double _price; //rub
	int inHabbitant_size = 5;	
	std::vector<inHabbitant*> inHabbitant_list_vct;
	static int _flat_number_counter;
public:
	// Constructors // Initialisation // Destructors // Memory Clean -------
	Flat(int max_inHabbitans);
	~Flat();

	// Shows ---------------------------------------------------------------
	void ShowInfo();

	static std::string Open_Interface_Info()
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
	static std::vector<int>& Get_Operation_Info()
	{
		//codes_of_operation
		//{ {1, " + "}, { 2," - " }, { 3," * " }, { 4, " / " }, { 5, " * " },
		//	{ 6," / " }, { 7, " > " }, { 8," < " }, { 9," = " }, { 0, "==" },
		//	{ 11, " ++" } /*prefix*/, { 12, "++ " } /*postfix*/, { 13, " --" }, { 14, "-- " }, { 15, " +" }, { 16, " -" } };

		std::vector <int>* available_operations = new std::vector <int>{ 7 /* > */, 8 /* < */, 9 /* = */, 0/* == */ };
		return *available_operations;
	}

	// Setters // Getters --------------------------------------------------
	int GetFlatNumber() { return _flat_number; }
	int GetinHabbitansAmount() { return inHabbitant_list_vct.size(); }
	
	// Data manage ---------------------------------------------------------
	void AddNewinHabbitant(inHabbitant* tmp_ptr) { inHabbitant_list_vct.push_back(tmp_ptr); }
	void DeleteinHabbitant(int selected_inHabbitant_index);
	inHabbitant* GetinHabbitantObj(int inHabbitant_index) { return inHabbitant_list_vct[inHabbitant_index]; }

	//Overload operators ---------------------------------------------------
	bool operator > (const Flat& obj) const
	{
		if (_price > obj._price) return true;
		return false;
	}
	bool operator < (const Flat& obj) const
	{
		if (_price < obj._price) return true;
		return false;
	}
	bool operator == (const Flat& obj) const
	{
		if (_area == obj._area) return true;
		return false;
	}
	void operator = (const Flat& obj)
	{
		//*this = obj;
		_area = obj._area;
		_price = obj._price;
	}

	friend std::ostream& operator << (std::ostream& out, Flat* obj);
	friend std::ostream& operator << (std::ostream& out, Flat& obj)
	{
		
	}

};
