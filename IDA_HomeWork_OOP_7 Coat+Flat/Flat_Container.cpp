#include "Flat_Container.h"


//std::map <int, std::string> keycodes{ {27, "Esc"}, {13, "Enter"}, {48, "0"}, {57, "9"} };
//std::string console_clear = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
//std::string big_space = "                                                           ";
//std::map <int, int> codes_of_digits{ {49, 0}, {50, 1}, {51, 2},{52, 3},{53, 4},{54, 5},{55, 6},{56, 7},{57, 8} };
//// Операции с дробями 
////std::map <int, std::string> Fraction::codes_of_operation{ {1," + "}, {2," - "}, {3," * "}, {4, " / "}, {5, "++"}, {6,"++"}, {7, "--"}, {8,"--"},{9,"+"}, {0, "-"} };
//
//// Стандартный набор операций
//std::map <int, std::string> Flat_Container::codes_of_operation2{ {1," + "}, {2," - "}, {3," * "}, {4, " / "}, {5, " * "},
//	{6," / "}, {7, " > "}, {8," < "},{9," = "}, {0, "=="},
//	{11, " ++"} /*prefix*/,  {12, "++ "} /*postfix*/, {13, " --"}, {14, "-- "}, {15, " +"}, {16, " -"} };



std::vector <Flat*> Flat_Container::_objects_list;
