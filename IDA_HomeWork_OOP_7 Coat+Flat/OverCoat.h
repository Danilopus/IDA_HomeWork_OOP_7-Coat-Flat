#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>

enum class Overcoat_length_type { top, jacket, manto, terminator };
enum class Manufacter { BOSS, ZARA, HandM, noname, adidas, NorthFace, Columbia, UNICLO, terminator };
enum class OverCoat_colors { black, brown, yellow, white, purple, indigo, terminator };
enum class Material_type { Fur, Leather, Textile, Syntetic, Down, terminator };
enum class Dress_size { kid, XXS, XS, S, M, L, XL, XXL, terminator };

class OverCoat
{
	Overcoat_length_type _length;
	Manufacter _manufacter;
	OverCoat_colors _color;
	Material_type _material_type;
	Dress_size _size;
	double _price; //rub
public:
	std::string _comment;
	// Constructors // Initialisation // Destructors // Memory Clean -------
	OverCoat(Overcoat_length_type length, Manufacter _manufacter, OverCoat_colors color, Material_type overcoat_material_type, Dress_size size, std::string comment, double _price);
	OverCoat(char random_flag);

	~OverCoat() { } //std::cout << "destructor"; _getch();	}

	// Setters // Getters --------------------------------------------------
	OverCoat& Set_comment(std::string comment) { _comment = comment; return *this; }
	OverCoat& Set_price(double price) { _price = price; return *this; }
	double Get_price() { return _price; }
	static std::vector <int>& Get_methods();

	// Shows ---------------------------------------------------------------
	void ShowValues() { std::cout << *this; }
	//void ShowValues() { std::cout << this; }

	static std::string Open_Interface_Info();

	//Overload operators ---------------------------------------------------
		
	bool operator > (const OverCoat& obj) const;
	bool operator < (const OverCoat& obj) const;
	bool operator == (const OverCoat& obj) const;
	void operator = (const OverCoat& obj);
	bool operator != (double price) const;

	friend std::ostream& operator << (std::ostream& out, OverCoat* obj);
	friend std::ostream& operator << (std::ostream& out, OverCoat& obj);
};

