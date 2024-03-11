#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

///Purpose of class:
///Create a class which controls and initialize the application.
///   The program uses the "Singleton Pattern:
///   creational design pattern that ensures only a single instance of a class exists throughout an application
///   and provides access to that instance from anywhere in the codebase".

class Application
{
	///Modifiable
public:
	///Deleteing copy of constructor and "move".
	Application(const Application&) = delete; //Constructor deleted
	Application(Application&&) = delete; //Move Constructor deleted

	static Application* Get(); // Static member function to retrieve the singleton instance

	int RunApplication(); // Runs the application: running the while/render loop

private:
	Application() = default; // Default constructor, no need to generate in cpp

	void InitGLFW();
	void InitApplication();
	void LoadContent();
};

#endif