#pragma once
#include "OverCoat.h";

class UnitTest
{
public:
	static std::string OverCoat_test()
	{
		std::string test_report = "\n\n*** Tests status\n";
		OverCoat test_obj('rand');

		test_report += "\nShowValues()_test: ";
		test_report += ShowValues_test(test_obj) ? "Ok" : "failed";

		test_report += "\nSet_comment()_test: ";
		test_report += Set_comment_test(test_obj) ? "Ok" : "failed";

		test_report += "\nSet_price()_test: ";
		test_report += Set_price_test(test_obj) ? "Ok" : "failed";

		test_report += "\nOperator > () test: ";
		test_report += Operator_7_test(test_obj) ? "Ok" : "failed";

		test_report += "\nOperator < () test: ";
		test_report += Operator_8_test(test_obj) ? "Ok" : "failed";

		test_report += "\nOperator = () test: ";
		test_report += Operator_9_test(test_obj) ? "Ok" : "failed";

		test_report += "\nOperator == () test: ";
		test_report += Operator_0_test(test_obj) ? "Ok" : "failed";


		return test_report;
	}
	static bool ShowValues_test(OverCoat& test_obj)
	{
		std::cout << "\nShowValues()_test\ntest_obj.ShowValues()\n";
		test_obj.ShowValues();

		if (test_obj != 0) { return true; }
		return false;
	}
	static bool Set_comment_test(OverCoat& test_obj)
	{
		std::cout << "\n" << "\n" << "Set_comment()_test\ntest_obj.Set_comment(Made in Turkey).ShowValues()\n";		
		test_obj.Set_comment("Made in Turkey").ShowValues();
				

		if (test_obj._comment == "Made in Turkey") { return true; }
		return false;
	}
	static bool Set_price_test(OverCoat& test_obj)
	{
		std::cout << "\n" << "\n" << "Set_price()_test\ntest_obj.Set_price(877.78).ShowValues();\n";
		test_obj.Set_price(877.78).ShowValues();
		
		if (test_obj.Get_price() == 877.78) { return true; }
		return false;
	}
	static bool Operator_7_test(OverCoat& test_obj)
	{
		std::cout << "\n\nOperator > () test" << "\n" << "temp_obj.Set_price(500)\ntest_obj > temp_obj ? \"true\" : \"false\"\n";
		OverCoat temp_obj('rand');
		temp_obj.Set_price(500);
		std::cout << ((test_obj > temp_obj) ? "true" : "false");
		if (test_obj > temp_obj) { return true; }
		return false;
	}
	static bool Operator_8_test(OverCoat& test_obj)
	{
		std::cout << "\n\nOperator < () test" << "\n" << "temp_obj.Set_price(500)\ntest_obj < temp_obj ? \"true\" : \"false\"\n";
		OverCoat temp_obj('rand');
		temp_obj.Set_price(500);
		std::cout << ((test_obj < temp_obj) ? "true" : "false");
		if (test_obj < temp_obj) { return false; }
		return true;

	}
	static bool Operator_9_test(OverCoat& test_obj)
	{
		std::cout << "\n\nOperator = () test" << "\n" << "OverCoat temp_obj('rand')\ntest_obj = temp_obj\ntest_obj.ShowValues()\n";
		OverCoat temp_obj('rand');
		test_obj = temp_obj;
		test_obj.ShowValues();
		if (test_obj == temp_obj) { return true; }
		return false;
	}
	static bool Operator_0_test(OverCoat& test_obj)
	{
		std::cout << "\n\nOperator == () test" << "\n" << "OverCoat temp_obj('rand')\ntest_obj = temp_obj\nstd::cout << (test_obj == temp_obj) ? \"true\" : \"false\"\n";
		OverCoat temp_obj('rand');
		test_obj = temp_obj;
		std::cout << ((test_obj == temp_obj) ? "true" : "false");
		if (test_obj == temp_obj) { return true; }
		return false;
	}
	
};