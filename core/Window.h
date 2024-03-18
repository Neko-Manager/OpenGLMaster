#pragma once
#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#ifndef WINDOW_H
#define WINDOW_H

/// Purpose of class:
/// Managing all methods and members neccessary to create a GLM-window.
/// managaing all glm-callbacks, such as for FramebufferSize and MouseMovementCallback.
/// </summary>

class Scene;

class Window
{
	///Modifiable
public:
	Window(std::string name, Scene* scene, int width, int height);//Constructor for window object
	~Window(); //Destructor for class object

	void InitWindow(); //Method for initlaizing window class
	bool LoadContent(); //Methods to check if loaded is content or not
	void SetScene(Scene* scene); //Method for creating a scene. Requires: scene object with pointer.
	void Update(float deltaTime); //Method for updating class in real time: deltaTime float
	void Render(float deltaTime); //Method for rendering class in real time: deltaTime float
	void EndFrame(); //Method to end frame

	bool IsClosed(); //Method to see if object is not loading anymore.

	///Callback Methods
	//Callback = a function passed into another function as an argument.
	//It is then invoked inside the outer function.
	void StoreWindowCallback(); //Method for storing callback functions to GLFWWindow
	void FramebufferSizeCallback(struct GLFWwindow* window, int height, int width); //Method to callback window GUI: GLFWWindow object pointer, integer for height and width
	void MouseMovementCallback(struct GLFWwindow* window, double xPos, double yPos); //Method to callback mouseMovement.
	void MouseButtonCallback(struct GLFWwindow* window, int button, int action, int mods); //Method  to callback MouseButton
	void MouseScrollCallback(struct GLFWwindow* window, double xOffset, double yOffset);
	void keyCallback(struct GLFWwindow* window, int key, int scanCode, int action, int mods);

	///Setters
	void SetWidth(int width);
	void SetHeight(int height);

	///Getters
	int GetWidth() const;
	int GetHeight() const;
	GLFWwindow* GetGLFWWindow() const { return mGLFWWindow; }

private:
	std::string mName; // Member name for the main window
	int mWidth, mHeight;

	Scene* mScene{ nullptr }; // Member Pointer to the scene component
	GLFWwindow* mGLFWWindow{ nullptr }; // Creating a new struct of type GLFWwindow pointer / adress.
};

#endif