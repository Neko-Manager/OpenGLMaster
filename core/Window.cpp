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
	// Adding lambda functions for callbacks
    //** Lambda functions  Lambda functions were introduced in C++11 as a way to create function objects (closures) directly in code without the need for defining a separate function.
    //**They are particularly useful in situations where you need to pass a simple function as an argument to another function, such as in algorithms like std::sort, std::find_if, etc.

    // This line sets the framebuffer size callback for the GLFW window mGLFWWindow.
	 glfwSetFramebufferSizeCallback(mGLFWWindow, [](GLFWwindow* window, int width, int height) {
        auto app = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window)); // This line retrieves a pointer to a Window object associated with the GLFW window.
        if (app)
        {
            app->FramebufferSizeCallback(window, width, height);
            app->SetWidth(width);
            app->SetHeight(height);
        }
        }); // This line sets the framebuffer size callback for the GLFW window mGLFWWindow.

    glfwSetCursorPosCallback(mGLFWWindow, [](GLFWwindow* window, double xpos, double ypos) {
        auto app = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if (app) app->MouseMoveCallback(window, xpos, ypos);
        }); // Lambda function taking window and cursor position parameters.

    glfwSetMouseButtonCallback(mGLFWWindow, [](GLFWwindow* window, int button, int action, int mods) {
        auto app = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if (app) app->MouseButtonCallback(window, button, action, mods);
        }); // Lambda function taking window and mouse buttons and action.

    glfwSetScrollCallback(mGLFWWindow, [](GLFWwindow* window, double xoffset, double yoffset) {
        auto app = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if (app) app->MouseScrollCallback(window, xoffset, yoffset);
        }); // Lambda function taking window and scroll button.

    glfwSetKeyCallback(mGLFWWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        auto app = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if (app) app->KeyCallback(window, key, scancode, action, mods);
        }); // Lambda function taking window, keyboard events and actions.

    // Store pointer so it can be accessed in callbacks
    glfwSetWindowUserPointer(mGLFWWindow, this);
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
