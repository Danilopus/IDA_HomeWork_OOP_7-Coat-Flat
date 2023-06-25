#include "OverCoat.h"

std::map<int, std::string> Type_by_length_codename{ {0, "Top"} ,{1, "Jacket"},{2, "Manto"} };
std::map<int, std::string> Manufacter_codename{ {0, "BOSS"} ,{1, "ZARA"},{2, "HandM"}, {3, "noname"}, {4, "adidas"},
	{5, "NorthFace"}, {6, "Columbia"}, {7, "UNICLO"} };
std::map<int, std::string> Colors_codename{ {0, "black"} ,{1, "brown"},{2, "yellow"}, {3, "white"}, {4, "indigo"} };
std::map<int, std::string> Material_codename{ {0, "Fur"} ,{1, "Leather"},{2, "Textile"}, {3, "Syntetic"}, {4, "Down"} };
std::map<int, std::string> Size_codename{ {0, "kid"} ,{1, "XXS"},{2, "XS"}, {3, "S"}, {4, "M"},{5, "L"}, {6, "XL"}, {7, "XXL"} };


OverCoat::OverCoat(char random_flag)
{
	//OverCoat* new_item = new OverCoat;
	_length = static_cast<Overcoat_length_type>(Get_Random(0, int(Overcoat_length_type::terminator)));
	_manufacter = static_cast<Manufacter>(Get_Random(0, int(Manufacter::terminator)));
	_color = static_cast<OverCoat_colors>(Get_Random(0, int(OverCoat_colors::terminator)));
	_material_type = static_cast<Material_type>(Get_Random(0, int(Material_type::terminator)));
	_size = static_cast<Dress_size>(Get_Random(0, int(Dress_size::terminator)));
	_price = Get_Random(2000, 5000);
}

std::vector<int>& OverCoat::Get_methods()
{
	//codes_of_operation
	//{ {1," + "}, {2," - "}, {3," * "}, {4, " / "}, {5, " * "}, {6," / "}, {7, " > "}, {8," < "},{9," = "}, {0, "=="} };

	//std::vector <int> available_operations{ 7 /* > */, 8 /* < */, 9 /* = */, 0/* == */ };


	std::vector <int>* available_operations = new std::vector <int> { 7 /* > */, 8 /* < */, 9 /* = */, 0/* == */ };
	//std::map <int, int> available_operands {{}}
	return *available_operations;
}

std::string OverCoat::Open_Interface_Info()
{
	std::string Open_Interface_Info;
	Open_Interface_Info += "\nConstructors:\n- Random (char parametr)\n- Detailed (all fields)";
	Open_Interface_Info += "\n\nMethods:";
	Open_Interface_Info += "\n1) ShowValues()";
	Open_Interface_Info += "\n2) Set_comment(string)";
	Open_Interface_Info += "\n3) Set_price(double)";

	return Open_Interface_Info;
}

bool OverCoat::operator>(const OverCoat& obj) const
{
	if (_price > obj._price) return true;
	return false;
}

bool OverCoat::operator<(const OverCoat& obj) const
{
	if (_price < obj._price) return true;
	return false;
}

bool OverCoat::operator==(const OverCoat& obj) const
{
	if (_length == obj._length) return true;
	return false;
}

void OverCoat::operator=(const OverCoat& obj)
{
	_length = obj._length;
	_manufacter = obj._manufacter;
	_color = obj._color;
	_material_type = obj._material_type;
	_size = static_cast<Dress_size>(Get_Random(0, int(Dress_size::terminator)));
	_price = obj._price; //rub
	_comment = obj._comment;
}
bool OverCoat::operator!=(double price) const
{
	if (_price != price) return true;
	return false;
}
std::ostream& operator<<(std::ostream& out, OverCoat& obj)
{
	out << std::endl << "Type:    " << Type_by_length_codename[int(obj._length)];
	out << std::endl << "Brand:   " << Manufacter_codename[int(obj._manufacter)];
	out << std::endl << "Color:   " << Colors_codename[int(obj._color)];
	out << std::endl << "Material:" << Material_codename[int(obj._material_type)];
	out << std::endl << "Size:    " << Size_codename[int(obj._size)];
	out << std::endl << "Price:   " << obj._price;
	out << std::endl << "Comment: " << obj._comment;

	return out;
}