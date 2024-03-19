#pragma once

#include "Scene.h"
#include "Window.h"
#include <memory>

/// Purpose of class:
/// Create a class which controls and initialize the application.
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

	///Not modifiable
private:
	Application() = default; // Default constructor, no need to generate in cpp

	void InitGLFW(); //Method for Initializing GLFW
	void InitApplication(); //Method for  Initializing the constructed application
	void LoadContent(); //Method to load content to be used from window-class

	Scene mScene{ "Scene" };
	Window mWindow{ "LearnOpenGL", &mScene, 1280, 720 };
};