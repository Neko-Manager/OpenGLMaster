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
	//mScene->LoadContent();
	return true;
}

/*
 * initializing a window frame for graphics rendering
 */
void Window::StartFrame()
{
    glfwPollEvents(); // This function is used to process events like keyboard input and mouse movement. It checks for events in the event queue and processes them accordingly.

    ImGui_ImplOpenGL3_NewFrame(); // Prepare ImGui for rendering with OpenGL
    ImGui_ImplGlfw_NewFrame(); // Prepare ImGui for rendering with GLFW
    ImGui::NewFrame(); // Begin a new ImGui frame

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Set clear color to teal
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
}

void Window::Update(float deltaTime)
{
	//TODO: mScene Update
}

void Window::Render(float deltaTime)
{
	//TODO: mScene Render
}

void Window::EndFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	// This function is part of the GLFW library and is used to swap the front and back buffers of the window. Swapping buffers is essential for double-buffered rendering to display the updated frame.
	glfwSwapBuffers(mGLFWWindow);
}

bool Window::IsClosed()
{
	return glfwWindowShouldClose(mGLFWWindow); // Checking whether a GLFW window should close
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

void Window::SetScene(Scene* scene)
{
	mScene = scene; // Sets what scene the window should have.
}

void Window::SetWidth(int width)
{
	mWidth = width;
}

void Window::SetHeight(int height)
{
	mHeight = height;
}

int Window::GetWidth() const
{
	return mWidth;
}

int Window::GetHeight() const
{
	return mHeight;
}
