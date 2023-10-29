#include <imgui.h>
#include <window.h>

#include <iostream>

int main(void)
{
	Window win(1280, 720, "Проводник ебать");
    while (win.StartUpdate())
    {
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("Folder"))
			{
				ImGui::MenuItem("Add");
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Kill jews"))
			{
				ImGui::MenuItem("it's da joos");
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
		
        win.EndUpdate();
    }

	Window::StopIMGUI();

    return 0;
}
