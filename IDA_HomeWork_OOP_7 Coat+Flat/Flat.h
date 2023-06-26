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

	static std::string Open_Interface_Info();
	static std::vector<int>& Get_Operation_Info();

	// Setters // Getters --------------------------------------------------
	int GetFlatNumber() { return _flat_number; }
	int GetinHabbitansAmount() { return inHabbitant_list_vct.size(); }
	
	// Data manage ---------------------------------------------------------
	void AddNewinHabbitant(inHabbitant* tmp_ptr) { inHabbitant_list_vct.push_back(tmp_ptr); }
	void DeleteinHabbitant(int selected_inHabbitant_index);
	inHabbitant* GetinHabbitantObj(int inHabbitant_index) { return inHabbitant_list_vct[inHabbitant_index]; }

	//Overload operators ---------------------------------------------------
	bool operator > (const Flat& obj) const;
	bool operator < (const Flat& obj) const;
	bool operator == (const Flat& obj) const;
	void operator = (const Flat& obj);

	friend std::ostream& operator << (std::ostream& out, Flat* obj);
	friend std::ostream& operator << (std::ostream& out, Flat& obj);	

};
