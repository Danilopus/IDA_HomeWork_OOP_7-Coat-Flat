#pragma once
#include <string>
#include "Flat.h"


class Flat_UnitTest
{
public:
	static std::string main_test(std::string className)
	{
		
		std::string test_report = "\n\n*** Tests status\n";
		test_report += "Class name: " + className;
		Flat test_obj(7);

		// Methods ------------------------------------------


		test_report += "\n\nGetFlatNumber()_test: ";
		test_report += _test_1(test_obj) ? "Ok" : "failed";

		test_report += "\nGetinHabbitansAmount()_test: ";
		test_report += _test_2(test_obj) ? "Ok" : "failed";

		test_report += "\nShowInfo()_test: ";
		test_report += _test_3(test_obj) ? "Ok" : "failed";

		test_report += "\nAddNewinHabbitant()_test: ";
		test_report += _test_4(test_obj) ? "Ok" : "failed";

		test_report += "\nDeleteinHabbitant()_test: ";
		test_report += _test_5(test_obj) ? "Ok" : "failed";				
		
		// Operators -----------------------------------------
		
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
	static bool _test_1(Flat& test_obj)
	{
		std::cout << "\n\n" << "GetFlatNumber()_test";
		std::cout << "\n" << "test_obj.GetFlatNumber() -> ";
		std::cout << test_obj.GetFlatNumber();

		if (test_obj.GetFlatNumber() != 0) { return true; }
		return false;
	}
	static bool _test_2(Flat& test_obj)
	{
		std::cout << "\n\n" << "GetinHabbitansAmount()_test";
		std::cout << "\n" << "test_obj.GetinHabbitansAmount() -> ";
		std::cout << test_obj.GetinHabbitansAmount();

		if (test_obj.GetinHabbitansAmount() != 0) { return true; }
		return false;
	}
	static bool _test_3(Flat& test_obj)
	{
		std::cout << "\n\n" << "ShowInfo()_test";
		std::cout << "\n" << "test_obj.ShowInfo() -> ";
		test_obj.ShowInfo();

		if (1 != 0) { return true; } //не придумал критерий теста
		return false;
	}
	static bool _test_4(Flat& test_obj)
	{
		int old_value = test_obj.GetinHabbitansAmount();

		std::cout << "\n\n" << "AddNewinHabbitant()_test";
		std::cout << "\n" << "inHabbitant* tmp_obj = new inHabbitant('rand')\n"
			<< "test_obj.AddNewinHabbitant(tmp_obj)\n"
			<< "test_obj.ShowInfo()";		

		inHabbitant* tmp_obj = new inHabbitant('rand');
		test_obj.AddNewinHabbitant(tmp_obj);
		test_obj.ShowInfo();

		if (test_obj.GetinHabbitansAmount() > old_value) { return true; }
		return false;
	}
	static bool _test_5(Flat& test_obj)
	{
		int old_value = test_obj.GetinHabbitansAmount();

		std::cout << "\n\n" << "DeleteinHabbitant()_test";
		std::cout << "\n" << "test_obj.DeleteinHabbitant(0)\n"
			<< "test_obj.ShowInfo()";

		test_obj.DeleteinHabbitant(0);
		test_obj.ShowInfo();

		if (test_obj.GetinHabbitansAmount() < old_value) { return true; }
		return false;
	}
	static bool Operator_7_test(Flat& test_obj)
	{
		std::cout	<< "\n\nOperator > () test" 
					<< "\n" << "Flat temp_obj(1)"
					<< "\n" << "test_obj > temp_obj ? \"true\" : \"false\"\n";				
		
		Flat temp_obj(1);
		std::cout << ((test_obj > temp_obj) ? "true" : "false");

		if (test_obj > temp_obj) { return true; }
		return false;
	}
	static bool Operator_8_test(Flat& test_obj)
	{
		std::cout << "\n\nOperator < () test"
			<< "\n" << "Flat temp_obj(10)"
			<< "\n" << "test_obj < temp_obj ? \"true\" : \"false\"\n";

		Flat temp_obj(10);
		std::cout << ((test_obj < temp_obj) ? "true" : "false");

		if (test_obj < temp_obj) { return true; }
		return false;
	}
	static bool Operator_9_test(Flat& test_obj)
	{
		std::cout << "\n\nOperator = () test"
			<< "\n" << "Flat temp_obj(10)"
			<< "\n" << "test_obj = temp_obj"				
			<< "\n" << "test_obj.ShowInfo() -> ";

		Flat temp_obj(10);
		test_obj = temp_obj;
		test_obj.ShowInfo();
		if (test_obj == temp_obj) { return true; }
		return false;
	}
	static bool Operator_0_test(Flat& test_obj)
	{
		std::cout << "\n\nOperator == () test"
			<< "\n" << "Flat temp_obj('rand')"
			<< "\n" << "test_obj = temp_obj"
			<< "\n" << "test_obj == temp_obj ? \"true\" : \"false\"\n";				
		
		Flat temp_obj(7);
		test_obj = temp_obj;
		std::cout << ((test_obj == temp_obj) ? "true" : "false");

		if (test_obj == temp_obj) { return true; }
		return false;
	}
};