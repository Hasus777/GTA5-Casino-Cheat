#include "menu.h"
#include "settings.h"
#include "functions.h"
#include "imguipp.h"
#include "icons.h"
#include "memory.h"
#include <Windows.h>
#include <iostream>
#include "externvar.h"
#include <fstream>
// TO-DO Add frame to config
#pragma warning(disable : 4996)
bool BrowserOpen = false;
std::string SelectedFile;
const char* ConData = "NULL";

// cheat vars
const char* InfoText = "8==D GTA5 Menu, By Addison Sawyer C==8";
const char* InfoText6 = "::Pointers::";
const char* InfoText7 = "Module Base Address -> GTA5.exe";
const char* InfoText8 = "Static Ptr Base Address -> 0x02931990";
const char* InfoText9 = "::Offsets::";
const char* InfoText10 = "Roulett Winning Number | [Byte4] | 0x40, 0x8, 0x8, 0x8, 0x108, 0x4D8";
const char* InfoText11 = "Player Bet | [Byte4] | 0x30, 0x50, 0x1B8, 0xB8, 0x108, 0x34";

static float TitleColor[] = { 0.449864f, 0.188883f, 0.994413f, 1.f };
static float BttnColor[] = { 0.449864f, 0.188883f, 0.994413f, 1.f };
static float BttnHvrColor[] = { 0.450980f, 0.188235f, 0.996078f, 0.788235f };
static float FrameBackGround[] = { 0.145f, 0.141f, 0.145f, 1.f };
static float SliderColor[] = { 0.298000f, 0.298000f, 0.298f, 1.f };
static float SliderGrabColor[] = { 0.449864f, 0.188883f, 0.994413f, 1.f };
static float CheckBoxColor[] = { 0.449864f, 0.188883f, 0.994413f, 1.f };

const wchar_t* Game = L"";

int Bet = 100;

bool Enabled = true;
bool Attach = false;

bool loadConfig()
{
	ConData = "We made it";
	std::ifstream in(SelectedFile);
	ConData = SelectedFile.c_str();

	if (!in.is_open())
	{
		//ConData = "Hello World";
		return false;
	}

	std::string param;
	float value;

	while (!in.eof())
	{
		in >> param;
		in >> value;


		if (param == "TITLE_COLOR_R")
		{
			TitleColor[0] = value;
		}
		else if (param == "TITLE_COLOR_G")
		{
			TitleColor[1] = value;
		}
		else if (param == "TITLE_COLOR_B")
		{
			TitleColor[2] = value;
		}
		else if (param == "TITLE_COLOR_A")
		{
			TitleColor[3] = value;
		}
		else if (param == "BTTN_COLOR_R")
		{
			BttnColor[0] = value;
		}
		else if (param == "BTTN_COLOR_G")
		{
			BttnColor[1] = value;
		}
		else if (param == "BTTN_COLOR_B")
		{
			BttnColor[2] = value;
		}
		else if (param == "BTTN_COLOR_A")
		{
			BttnColor[3] = value;
		}
		else if (param == "BTTN_HVR_COLOR_R")
		{
			BttnHvrColor[0] = value;
		}
		else if (param == "BTTN_HVR_COLOR_G")
		{
			BttnHvrColor[1] = value;
		}
		else if (param == "BTTN_HVR_COLOR_B")
		{
			BttnHvrColor[2] = value;
		}
		else if (param == "BTTN_HVR_COLOR_A")
		{
			BttnHvrColor[3] = value;
		}
		else if (param == "SLIDER_COLOR_R")
		{
			SliderColor[0] = value;
		}
		else if (param == "SLIDER_COLOR_G")
		{
			SliderColor[1] = value;
		}
		else if (param == "SLIDER_COLOR_B")
		{
			SliderColor[2] = value;
		}
		else if (param == "SLIDER_COLOR_A")
		{
			SliderColor[3] = value;
		}
		else if (param == "SLIDER_GRAB_COLOR_R")
		{
			SliderGrabColor[0] = value;
		}
		else if (param == "SLIDER_GRAB_COLOR_G")
		{
			SliderGrabColor[1] = value;
		}
		else if (param == "SLIDER_GRAB_COLOR_B")
		{
			SliderGrabColor[2] = value;
		}
		else if (param == "SLIDER_GRAB_COLOR_A")
		{
			SliderGrabColor[3] = value;
		}
		else if (param == "CHECK_BOX_R")
		{
			CheckBoxColor[0] = value;
		}
		else if (param == "CHECK_BOX_G")
		{
			CheckBoxColor[1] = value;
		}
		else if (param == "CHECK_BOX_B")
		{
			CheckBoxColor[2] = value;
		}
		else if (param == "CHECK_BOX_A")
		{
			CheckBoxColor[3] = value;
		}
	}
	in.close();
	Settings::Tab = 2;
	return true;
}

bool saveConfig()
{
	std::string SettingText = "";
	int number = rand() % 10000;
	std::string config = "Config" + std::to_string(number) + ".config";
	FILE* pFile = fopen(config.c_str(), "a");
	for (int i = 0; i < 4; i++)
	{
		std::string TitleColorConfig = std::to_string(TitleColor[i]);

		switch (i)
		{
		case 0: SettingText = "TITLE_COLOR_R " + TitleColorConfig; break;
		case 1: SettingText = "TITLE_COLOR_G " + TitleColorConfig; break;
		case 2: SettingText = "TITLE_COLOR_B " + TitleColorConfig; break;
		case 3: SettingText = "TITLE_COLOR_A " + TitleColorConfig; break;
		}

		fprintf(pFile, "%s\n", SettingText.c_str());
	}
	for (int i = 0; i < 4; i++)
	{
		std::string BttnColorConfig = std::to_string(BttnColor[i]);
		switch (i)
		{
		case 0: SettingText = "BTTN_COLOR_R " + BttnColorConfig; break;
		case 1: SettingText = "BTTN_COLOR_G " + BttnColorConfig; break;
		case 2: SettingText = "BTTN_COLOR_B " + BttnColorConfig; break;
		case 3: SettingText = "BTTN_COLOR_A " + BttnColorConfig; break;
		}
		fprintf(pFile, "%s\n", SettingText.c_str());
	}
	for (int i = 0; i < 4; i++)
	{
		std::string BttnHvrColorConfig = std::to_string(BttnHvrColor[i]);

		switch (i)
		{
		case 0: SettingText = "BTTN_HVR_COLOR_R " + BttnHvrColorConfig; break;
		case 1: SettingText = "BTTN_HVR_COLOR_G " + BttnHvrColorConfig; break;
		case 2: SettingText = "BTTN_HVR_COLOR_B " + BttnHvrColorConfig; break;
		case 3: SettingText = "BTTN_HVR_COLOR_A " + BttnHvrColorConfig; break;
		}
		fprintf(pFile, "%s\n", SettingText.c_str());
	}
	for (int i = 0; i < 4; i++)
	{
		std::string SliderColorConfig = std::to_string(SliderColor[i]);

		switch (i)
		{
		case 0: SettingText = "SLIDER_COLOR_R " + SliderColorConfig; break;
		case 1: SettingText = "SLIDER_COLOR_G " + SliderColorConfig; break;
		case 2: SettingText = "SLIDER_COLOR_B " + SliderColorConfig; break;
		case 3: SettingText = "SLIDER_COLOR_A " + SliderColorConfig; break;
		}
		fprintf(pFile, "%s\n", SettingText.c_str());
	}
	for (int i = 0; i < 4; i++)
	{
		std::string SliderGrabColorConfig = std::to_string(SliderGrabColor[i]);

		switch (i)
		{
		case 0: SettingText = "SLIDER_GRAB_COLOR_R " + SliderGrabColorConfig; break;
		case 1: SettingText = "SLIDER_GRAB_COLOR_G " + SliderGrabColorConfig; break;
		case 2: SettingText = "SLIDER_GRAB_COLOR_B " + SliderGrabColorConfig; break;
		case 3: SettingText = "SLIDER_GRAB_COLOR_A " + SliderGrabColorConfig; break;
		}
		fprintf(pFile, "%s\n", SettingText.c_str());
	}
	for (int i = 0; i < 4; i++)
	{
		std::string CheckBoxConfig = std::to_string(CheckBoxColor[i]);

		switch (i)
		{
		case 0: SettingText = "CHECK_BOX_R " + CheckBoxConfig; break;
		case 1: SettingText = "CHECK_BOX_G " + CheckBoxConfig; break;
		case 2: SettingText = "CHECK_BOX_B " + CheckBoxConfig; break;
		case 3: SettingText = "CHECK_BOX_A " + CheckBoxConfig; break;
		}
		fprintf(pFile, "%s\n", SettingText.c_str());
	}
	fclose(pFile);
	return true;
}

bool FileBrowse()
{
	if (BrowserOpen == true)
	{
		ImGui::FileBrowser fileDialog;

		// (optional) set browser properties
		fileDialog.SetTitle("File Browser");
		fileDialog.SetTypeFilters({ ".config" });
		fileDialog.Open();
		fileDialog.Display();
		if (fileDialog.HasSelected())
		{
			SelectedFile = fileDialog.GetSelected().string();
			BrowserOpen = false;
			loadConfig();
		}
	}

}

static size_t lastTime = 1;
void Menu::Render()
{
	// Grab our Application
	DWORD procId = GetProcId(Game);

	uintptr_t moduleBase = GetModuleBaseAddress(procId, Game);

	HANDLE hProcess = 0;

	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

	uintptr_t dynamicPtrBaseAddr = moduleBase + 0x02931990; // This is the Player Address
	// Keep Max Cheats Out Here to Prevent Revert

	// Winning Num Cheat
	std::vector<unsigned int> WinningNumOffset = { 0x40, 0x8, 0x8, 0x8, 0x108, 0x4D8 };
	uintptr_t WinningNumAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, WinningNumOffset);

	int currentWinningNum = 0;

	ReadProcessMemory(hProcess, (BYTE*)WinningNumAddr, &currentWinningNum, sizeof(currentWinningNum), nullptr);

	int newWinningNum = 1;

	WriteProcessMemory(hProcess, (BYTE*)WinningNumAddr, &newWinningNum, sizeof(newWinningNum), nullptr);
	// End Winning Num Cheat

	// Winning Num High Roller Cheat
	std::vector<unsigned int> WinningNumHROffset = { 0x30, 0x8, 0x108, 0x4F0 };

	uintptr_t WinningNumHRAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, WinningNumHROffset);

	int currentWinningNumHR = 0;

	ReadProcessMemory(hProcess, (BYTE*)WinningNumHRAddr, &currentWinningNumHR, sizeof(currentWinningNumHR), nullptr);

	int newWinningNumHR = 1;

	WriteProcessMemory(hProcess, (BYTE*)WinningNumHRAddr, &newWinningNumHR, sizeof(newWinningNumHR), nullptr);
	// End Winning Num High Roller Cheat

	// Find All Bets and Set Them To Modded Size
	for (int i = 0; i < 7; i++)
	{
		unsigned int BetFinalOffset = 0x10 * i;
		std::vector<unsigned int> Bet2Offset = { 0x30, 0x50, 0x1B8, 0xB8, 0x108, 0x34 + BetFinalOffset };
		uintptr_t Bet2Addr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, Bet2Offset);


		int currentBet = 0;

		ReadProcessMemory(hProcess, (BYTE*)Bet2Addr, &currentBet, sizeof(currentBet), nullptr);

		int newBet = Bet;

		WriteProcessMemory(hProcess, (BYTE*)Bet2Addr, &newBet, sizeof(newBet), nullptr);
	}

	// Start Our Render
	ImGui::Columns(2);
	ImGui::SetColumnOffset(1, 230);

	{
		//Left side

		static ImVec4 active = imguipp::to_vec4(41, 40, 41, 255);
		static ImVec4 inactive = imguipp::to_vec4(31, 30, 31, 255);

		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? active : inactive);
		if (ImGui::Button(ICON_FA_CODE " Cheats", ImVec2(230 - 15, 41)))
			Settings::Tab = 1;

		ImGui::Spacing();		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
		if (ImGui::Button(ICON_FA_DOWNLOAD " Theme", ImVec2(230 - 15, 41)))
			Settings::Tab = 2;

		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? active : inactive);
		if (ImGui::Button(ICON_FA_BOOK " Info", ImVec2(230 - 15, 41)))
			Settings::Tab = 3;

		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 5 ? active : inactive);
		if (ImGui::Button(ICON_FA_EJECT " Exit", ImVec2(230 - 15, 41)))
			Settings::Tab = 5;

		ImGui::PopStyleColor(4);

		ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 30);
		imguipp::center_text_ex("Made By Addison Sawyer", 230, 1, false);
	}

	ImGui::NextColumn();

	//Right side
	{

		if (Settings::Tab == 1)
		{
			// put maxes outside the execute func they need to be permanant
			ImGui::Text("Bet On : Red 1");
			if (ImGui::Checkbox("Attach To GTA", &Attach))
			{
				Game = L"GTA5.exe";
			}
			else if (!Attach)
			{
				Game = L"";
			}
			ImGui::SliderInt("Set Bet", &Bet, 1, 60000);

		}
		else if (Settings::Tab == 2)
		{
			ImGui::ColorEdit4("Title Color", TitleColor);
			ImGui::ColorEdit4("Button Color", BttnColor); // Doesnt Change Bttn Color IDK Why
			ImGui::ColorEdit4("Button Hover Color", BttnHvrColor);
			ImGui::ColorEdit4("Slider Color", SliderColor);
			ImGui::ColorEdit4("Slider Grab Color", SliderGrabColor);
			if (ImGui::Button("Save Config", ImVec2(200, 35)))
			{
				saveConfig();
			}
			if (ImGui::Button("Load Config", ImVec2(200, 35)))
			{
				BrowserOpen = true;
				if (BrowserOpen == true)
				{
					Settings::Tab = 4;
				}

			}
		}
		else if (Settings::Tab == 3)
		{
			ImGui::Text(InfoText);
			ImGui::Text(InfoText6);
			ImGui::Text(InfoText7);
			ImGui::Text(InfoText8);
			ImGui::Text(InfoText9);
			ImGui::Text(InfoText10);
			ImGui::Text(InfoText11);
		}
		else if (Settings::Tab == 4)
		{
			ImGui::Text(ConData);
			FileBrowse();
		}
		else if (Settings::Tab == 5)
		{
			Enabled = !Enabled;
		}
	}
}

void Menu::Theme()
{
	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowBorderSize = 0;
	style->WindowTitleAlign = ImVec2(0.5, 0.5);
	style->WindowMinSize = ImVec2(900, 310);

	style->FramePadding = ImVec2(8, 6);
	style->Colors[ImGuiCol_TitleBg] = ImColor(TitleColor[0], TitleColor[1], TitleColor[2], TitleColor[3]);
	style->Colors[ImGuiCol_TitleBgActive] = ImColor(TitleColor[0], TitleColor[1], TitleColor[2], TitleColor[3]);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(0, 0, 0, 130);

	style->Colors[ImGuiCol_Button] = ImColor(BttnColor[0], BttnColor[1], BttnColor[2], BttnColor[3]);
	style->Colors[ImGuiCol_ButtonActive] = ImColor(BttnHvrColor[0], BttnHvrColor[1], BttnHvrColor[2], BttnHvrColor[3]);
	style->Colors[ImGuiCol_ButtonHovered] = ImColor(BttnHvrColor[0], BttnHvrColor[1], BttnHvrColor[2], BttnHvrColor[3]);

	style->Colors[ImGuiCol_Separator] = ImColor(70, 70, 70, 255);
	style->Colors[ImGuiCol_SeparatorActive] = ImColor(76, 76, 76, 255);
	style->Colors[ImGuiCol_SeparatorHovered] = ImColor(76, 76, 76, 255);

	style->Colors[ImGuiCol_FrameBg] = ImColor(FrameBackGround[0], FrameBackGround[1], FrameBackGround[2], FrameBackGround[3]);
	style->Colors[ImGuiCol_FrameBgActive] = ImColor(FrameBackGround[0], FrameBackGround[1], FrameBackGround[2], FrameBackGround[3]);
	style->Colors[ImGuiCol_FrameBgHovered] = ImColor(FrameBackGround[0], FrameBackGround[1], FrameBackGround[2], FrameBackGround[3]);

	style->Colors[ImGuiCol_SliderGrab] = ImColor(SliderColor[0], SliderColor[1], SliderColor[2], SliderColor[3]);
	style->Colors[ImGuiCol_SliderGrabActive] = ImColor(SliderGrabColor[0], SliderGrabColor[1], SliderGrabColor[2], SliderGrabColor[3]);

	style->Colors[ImGuiCol_CheckMark] = ImColor(CheckBoxColor[0], CheckBoxColor[1], CheckBoxColor[2], CheckBoxColor[3]);
}