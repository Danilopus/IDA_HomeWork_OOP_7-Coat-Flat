#include "Contain_and_Handle.h"

std::map <int, std::string> keycodes{ {27, "Esc"}, {13, "Enter"}, {48, "0"}, {57, "9"} };
std::string console_clear = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
std::string big_space = "                                                           ";
std::map <int, int> codes_of_digits{ {49, 0}, {50, 1}, {51, 2},{52, 3},{53, 4},{54, 5},{55, 6},{56, 7},{57, 8} };
// Операции с дробями 
//std::map <int, std::string> Fraction::codes_of_operation{ {1," + "}, {2," - "}, {3," * "}, {4, " / "}, {5, "++"}, {6,"++"}, {7, "--"}, {8,"--"},{9,"+"}, {0, "-"} };

// Стандартный 
std::map <int, std::string> Contain_and_Handle::codes_of_operation{ {1," + "}, {2," - "}, {3," * "}, {4, " / "}, {5, " * "},
	{6," / "}, {7, " > "}, {8," < "},{9," = "}, {0, "=="},
	{11, " ++"} /*prefix*/,  {12, "++ "} /*postfix*/, {13, " --"}, {14, "-- "}, {15, " +"}, {16, " -"} };


std::vector <OverCoat*> Contain_and_Handle::_objects_list;

int Contain_and_Handle::_getch_to_int(int minimum, int maximum)
{
	int keycode = _getch();
	std::cout << console_clear;
	if (keycode == 27) return -1;
	if ((keycode >= 48 + minimum) && (keycode <= 48 + maximum))
		return (keycode - 48);
	//std::cout << "\nkeycode " << keycode;
	std::cout << "Press a number [" << minimum << ".." << maximum << "] ";
	_getch_to_int(minimum, maximum);
}
