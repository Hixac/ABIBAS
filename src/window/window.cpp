#include "imgui.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <window.h>

Window::Window(unsigned int width, unsigned int height, const char* title)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwInit();
	
	m_pWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);

	glfwMakeContextCurrent(m_pWindow);
    glfwSwapInterval(1);

	IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
	
	glfwMakeContextCurrent(m_pWindow);
	ImGui_ImplGlfw_InitForOpenGL(m_pWindow, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

Window::~Window()
{	
	glfwDestroyWindow(m_pWindow);
	glfwTerminate();
}

bool Window::StartUpdate()
{
	glfwPollEvents();

	ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

	return IsClosed();
}

void Window::EndUpdate()
{
	ImGui::Render();
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(m_pWindow);
}

bool Window::IsClosed()
{
	return !glfwWindowShouldClose(m_pWindow);
}

void Window::StopIMGUI()
{
	ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
