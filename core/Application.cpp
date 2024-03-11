#include <Application.h>
#include "GLFW/glfw3.h"

Application* Application::Get()
{
	static Application* app = new Application; // A Static pointer so that you cannot modify it in runtime.
	return app;
}

void Application::InitGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Application::InitApplication()
{
	InitGLFW();
	//TODO: Add window class and the functions mWindow.Init(); mWindow.RegisterWindowCallbacks();
}

void Application::LoadContent()
{
	//TODO: mWindow.LoadContent();
}

int Application::RunApplication()
{
	InitApplication();
	LoadContent();

	//Creating deltaTime
	float lastFrame = 0.f;

	while (!mWindow.IsClosed())
	{
		float currentFrame = static_cast<float>(glfwGetTime()); // Cast convert the function() into a type of <class>, in this instance from glfwGetTime() which is a double into float
		float deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		mWindow.StartFrame();
		mWindow.Update(deltaTime);
		mWindow.Render(deltaTime);
		mWindow.EndFrame();
	}

	return 0;
}