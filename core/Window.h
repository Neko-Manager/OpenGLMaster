#pragma once
#include <iostream>

#ifndef WINDOW_H
#define WINDOW_H

class Window
{
	Window(std::string name, Scene* scene, int width, int height);
	~Window();
public:

private:
	std::string mName; // Member name for the main window
	int mWidth, mHeight;

	Scene* mScene{ nullptr }; // Member Pointer to the scene component
	struct GLFWwindow* mGLFWWindow{ nullptr }; // Creating a new struct of type GLFWwindow pointer / adress.
};

#endif