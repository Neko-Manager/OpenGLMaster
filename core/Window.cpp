#include "Window.h"
#include "Scene.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


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

void Window::InitWindow()
{
	mGLFWWindow = glfwCreateWindow(mWidth, mHeight, mName.c_str(), NULL, NULL); // Creating an instance of the glfw window, then storing it into the GLFWwindow variable
	if (mGLFWWindow == NULL)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create glfw window"); //Crashed program and gives a message error
	}
    glfwMakeContextCurrent(mGLFWWindow); // Creating a window based on our mGLFWWindow variables

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::runtime_error("Failed to initialize glad"); //Crashed program and gives a message error
	}


	// Initialize ImgUi window and inputs
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui_ImplGlfw_InitForOpenGL(mGLFWWindow, false);
    ImGui_ImplOpenGL3_Init("#version 130");
}

bool Window::LoadContent()
{
	return true;
}

void Window::SetScene(Scene* scene)
{
}

void Window::Update(float deltaTime)
{
}

void Window::Render(float deltaTime)
{
}

void Window::EndFrame()
{
}

bool Window::IsClosed()
{
	return true;
}

void Window::StoreWindowCallback()
{
}

void Window::FramebufferSizeCallback(GLFWwindow* window, int height, int width)
{
}

void Window::MouseMovementCallback(GLFWwindow* window, double xPos, double yPos)
{
}

void Window::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
}

void Window::MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
}

void Window::keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
}

void Window::SetWidth(int width)
{
}

void Window::SetHeight(int height)
{
}

int Window::GetWidth() const
{
	return 0;
}

int Window::GetHeight() const
{
	return 0;
}
