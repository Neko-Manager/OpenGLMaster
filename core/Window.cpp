#include <Window.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"

Window::Window(std::string name, Scene* scene, int width, int height)
{
	mName = name;
	mScene = scene;
	mWidth = width;
	mHeight = height;
}

Window::~Window()
{
	glfwDestroyWindow(mGLFWWindow);
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}