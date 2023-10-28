#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GLFW/glfw3.h>
#include <memory>

class Window
{
public:
	Window(unsigned int width, unsigned int height, const char* title);
	~Window();
	
	static void StopIMGUI();

	bool StartUpdate();
    void EndUpdate();
	bool IsClosed();
private:
    GLFWwindow* m_pWindow;
};
