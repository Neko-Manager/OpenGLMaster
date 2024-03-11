// OpenGLV2024.cpp : Defines the entry point for the application.
//

#include "core/Application.h"
#include <iostream>
#include <string>

int main()
{
	int num1 = 10;
	double num2 = 4.5;

	std::string result = std::to_string(num1) + " " + std::to_string(num2);

	std::cout << "Result: " << result << std::endl;

	return 0;
	//    return Application::Get()->Run();
}