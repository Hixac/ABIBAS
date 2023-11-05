#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>
#include <stdexcept>
#include <window.h>
#include <spdlog/spdlog.h>
#define DEBUG
#include <Base.h>

#include <filesystem>
#include <vector>
#include <iostream>

std::vector<std::filesystem::path> GetAllDirsInPath(const std::filesystem::path& in)
{
	bool IsAtLeastOneDir = false;
	std::vector<std::filesystem::path> dirs;
	
	for (const auto & entry : std::filesystem::directory_iterator(in))
	{
		if (std::filesystem::is_directory(entry))
		{
			IsAtLeastOneDir = true;
		    dirs.push_back(entry);
		}
	}

	if (!IsAtLeastOneDir)
		throw std::invalid_argument("No directories!");
	
	return dirs;
}

int main(void)
{
	INIT_LOG();
	
	static std::string exPath = "/home/hixac/Projects/";
	static std::vector<std::filesystem::path> dirs = GetAllDirsInPath(exPath);
	static int item_current_idx = 0;
	
  	Window win(1280, 720, "Проводник ебать");
    while (win.StartUpdate())
    {
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("Folder"))
			{
				try
				{
					ImGui::InputText("Input", &exPath);
					dirs = GetAllDirsInPath(exPath);

					item_current_idx = 0;

					LOG_INFO("Correctly changed to " + exPath);
				}
				catch (...)
				{
					LOG_WARN("Bullshit!");
				}
				
				if (ImGui::BeginCombo("Directories", dirs[item_current_idx].c_str()))
				{
					for (int n = 0; n < dirs.size(); n++)
					{
						const bool is_selected = (item_current_idx == n);
						if (ImGui::Selectable(dirs[n].c_str(), is_selected))
						{
							item_current_idx = n;
							exPath = dirs[n];
						}
						if (is_selected)
							ImGui::SetItemDefaultFocus();
					}
					ImGui::EndCombo();
				}
				
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
		ImGui::Begin("Show", NULL, ImGuiWindowFlags_NoMove || ImGuiWindowFlags_NoCollapse);
		ImGui::SetWindowSize({(float)win.GetWidth(), (float)win.GetHeight()});
		ImGui::SetWindowPos({0, 18});
		
		if (ImGui::BeginTable("Files table", 1))
		{
			try
			{
				for (const auto & entry : std::filesystem::directory_iterator(exPath))
				{
					ImGui::TableNextRow();
					ImGui::TableNextColumn();
					ImGui::Button(entry.path().filename().c_str());
				}
			} catch (...)
			{
				ImGui::Text("Error! No path found!");
			}
		    
			ImGui::EndTable();
		}
		ImGui::End();
		
        win.EndUpdate();
    }

	Window::StopIMGUI();

    return 0;
}
