#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>
#include <iomanip>
#include <cassert>

enum class Manufacter {BOSS, ZARA, HandM, noname, adidas, terminator};
enum class Material_type { Fur, Leather, Textile, Syntetic, terminator};
enum class OverCoat_colors {black, brown, yellow, white, purple, indigo, terminator};
enum Overcoat_length_type {top, jacket, manto, terminator};
enum Dress_size { kid, XXS, XS, S, M, L, XL, XXL, terminator};
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
	OverCoat(std::string comment, Dress_size size, Material_type overcoat_material_type,	OverCoat_colors color, Overcoat_length_type length, double _price);
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
	static void Memory_Clean();

	static void Get_methods()
	{

	}

	// Setters // Getters --------------------------------------------------
	OverCoat& Set_comment(std::string comment) { _comment = comment; return *this; }
	OverCoat& Set_price(double price) { _price = price; return *this; }


	// Shows ---------------------------------------------------------------
	void ShowValues() { std::cout << *this; }
	//void ShowValues() { std::cout << this; }

	static void ShowMethods();

	//Overload operators - reference returned -----------------------------------------

	//OverCoat* operator+(OverCoat & another_Money);
	OverCoat& operator+(const OverCoat& another_Money) const;
	OverCoat& operator-(const OverCoat& another_Money) const;
	OverCoat& operator*(const OverCoat& another_Money) const;
	OverCoat& operator*(double multiplier) const;
	OverCoat& operator/(double divider) const;
	double operator/(const OverCoat& another_Money) const;
	bool operator>(const OverCoat& another_Money) const;
	bool operator<(const OverCoat& another_Money) const;
	bool operator==(const OverCoat& another_Money) const;

	friend std::ostream& operator << (std::ostream& out, OverCoat* just_a_Money);
	friend std::ostream& operator << (std::ostream& out, OverCoat& OverCoat_obj)
	{
		std::cout << std::endl << OverCoat_obj._length;
		std::cout << std::endl << Manufacter_codename[int(OverCoat_obj._manufacter)];

	}
};

