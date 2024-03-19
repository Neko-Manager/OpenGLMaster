// OpenGLV2024.cpp : Defines the entry point for the application.
//

#include "core/Application.h"
#include <iostream>
#include <string>
#include <assert.h>

int main{
	int num1 = 10;
	double num2 = 4.5;

	std::string result = std::to_string(num1) + " " + std::to_string(num2);

	int x = 1;
	auto geterror = std::runtime_error("This is an error"); 

	///Krasj måter

	///1.
	/*	if (x == 0) 
		{
			return 1;
		}
		else
		{
			std:: cout << geterror.what();
		}*/

	///2.
	/*assert(x != 1 && "Crash test succsessfull");*/

 

	return 0;
	//    return Application::Get()->Run();
}