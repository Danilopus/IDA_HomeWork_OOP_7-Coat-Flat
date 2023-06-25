#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>

enum class Manufacter {BOSS, ZARA, HandM, noname, adidas, terminator};
enum class Material_type { Fur, Leather, Textile, Syntetic, terminator};
enum class OverCoat_colors {black, brown, yellow, white, purple, indigo, terminator};
enum class Overcoat_length_type {top, jacket, manto, terminator};
enum class Dress_size { kid, XXS, XS, S, M, L, XL, XXL, terminator};
std::map<int, std::string> Manufacter_codename{ {0, "BOSS"} ,{1, "ZARA"},{2, "HandM"}, {3, "noname"}, {4, "adidas"} };

class OverCoat
{
	Overcoat_length_type _length;
	Manufacter _manufacter;
	OverCoat_colors _color;
	Material_type _material_type;
	Dress_size _size;
	std::string _comment;
	double _price; //rub
public:
	// Constructors // Initialisation // Destructors // Memory Clean -------
	OverCoat(Overcoat_length_type length, Manufacter _manufacter, OverCoat_colors color, Material_type overcoat_material_type, Dress_size size, std::string comment, double _price);
	OverCoat(char random_flag) 
	{
		//OverCoat* new_item = new OverCoat;
		_size = static_cast<Dress_size>(Get_Random(0, int(Dress_size::terminator)));
		_material_type = static_cast<Material_type>(Get_Random(0, int(Material_type::terminator)));
		_color = static_cast<OverCoat_colors>(Get_Random(0, int(OverCoat_colors::terminator)));
		_length = static_cast<Overcoat_length_type>(Get_Random(0, int(Overcoat_length_type::terminator)));
		_manufacter = static_cast<Manufacter>(Get_Random(0, int(Manufacter::terminator)));
	}

	~OverCoat()
	{
		//_manufacter

		//OverCoat_colors->size();
		//_color = OverCoat_colors::black;		

		//std::cout << "Vector reallocates memory";
		//_getch();	
	}

	//std::map <int, std::string>& Get_methods()
	std::vector <int>& Get_methods()
	{
		//codes_of_operation
		//{ {1," + "}, {2," - "}, {3," * "}, {4, " / "}, {5, " * "}, {6," / "}, {7, " > "}, {8," < "},{9," = "}, {0, "=="} };
		 std::vector <int> available_operations{ 7, 8, 9, 0 };
		//std::map <int, int> available_operands {{}}
		 return available_operations;
	}

	// Setters // Getters --------------------------------------------------
	OverCoat& Set_comment(std::string comment) { _comment = comment; return *this; }
	OverCoat& Set_price(double price) { _price = price; return *this; }


	// Shows ---------------------------------------------------------------
	void ShowValues() { std::cout << *this; }
	//void ShowValues() { std::cout << this; }

	static std::string Open_Interface_Info()
	{
		std::string Open_Interface_Info;
		Open_Interface_Info += "Constructors:\n- Random (char parametr)\n- Detailed (all fieleds)";
		Open_Interface_Info += "\nMethods:";
		Open_Interface_Info += "\n1) ShowValues()";
		Open_Interface_Info += "\n2) Set_comment(string)";
		Open_Interface_Info += "\n3) Set_price(double)";
			
		return Open_Interface_Info;
	}

	//Overload operators ---------------------------------------------------
		
	bool operator > (const OverCoat& obj) const
	{
		if (_price > obj._price) return true;
		return false;
	}
	
	bool operator < (const OverCoat& obj) const
	{
		if (_price < obj._price) return true;
		return false;
	}
	
	bool operator == (const OverCoat& obj) const
	{
		if (_length == obj._length) return true;
		return false;
	}

	bool operator = (const OverCoat& obj) 
	{
		_length = obj._length;
		_manufacter = obj._manufacter;
		_color = obj._color;
		_material_type = obj._material_type;
		_size = static_cast<Dress_size>(Get_Random(0, int(Dress_size::terminator)));
		_price = obj._price; //rub
	}


	friend std::ostream& operator << (std::ostream& out, OverCoat* obj);
	friend std::ostream& operator << (std::ostream& out, OverCoat& obj)
	{
		//std::cout << std::endl << OverCoat_obj._length;
		std::cout << std::endl << Manufacter_codename[int(obj._manufacter)];

	}
};

