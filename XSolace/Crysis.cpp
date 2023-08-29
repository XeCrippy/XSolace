#include "stdafx.h"
#include "Crysis.h"

namespace Crysis {

	XINPUT_STATE state = { 0 };

	namespace vars {

		bool godMode = false;
		bool infiniteAmmo = false;

		uint32_t cxconsolePtr = 0x837CF198;
		
	}

	namespace gameFuncs {
		void(__fastcall* ExecuteStringInternal)(uint32_t consolePtr, const char* command, const bool bFromConsole, const bool bSilentMode) = reinterpret_cast<void(__fastcall*)(uint32_t, const char*, const bool, const bool)>(0x82286300);
	}

	namespace funcs {
		void __fastcall ExecCommand(const char* command) {
			uint32_t cxconsole = *(uint32_t*)vars::cxconsolePtr;
			gameFuncs::ExecuteStringInternal(cxconsole, command, false, true);
		}

		bool GodMode() {
			if (!vars::godMode) {
				ExecCommand("g_godMode 1");
				xTools::Xam::XNotify("God Mode : Enabled");
				vars::godMode = true;
			}
			else {
				ExecCommand("g_godMode 0");
				xTools::Xam::XNotify("God Mode : Disabled");
				vars::godMode = false;
			}
			return vars::godMode;
		}

		bool InfinteAmmo() {
			if (!vars::infiniteAmmo) {
				ExecCommand("i_unlimitedammo 1");
				xTools::Xam::XNotify("Infinite Ammo : Enabled");
				vars::infiniteAmmo = true;
			}
			else {
				ExecCommand("i_unlimitedammo 0");
				xTools::Xam::XNotify("Infinite Ammo : Disabled");
				vars::infiniteAmmo = false;
			}
			return vars::infiniteAmmo;
		}
	}

	namespace pages {

		const wchar_t* MainPage() {

			std::wstring newLine = L"\r\n";
			std::wstring mainPage;
			mainPage += L"God Mode : D_Left + A";
			mainPage += newLine;
			mainPage += L"Infinite Ammo : D_Left + X";
			mainPage += newLine;
			mainPage += L" : D_Left + Y";
			mainPage += newLine;
			mainPage += L": D_Left + B";
			mainPage += newLine;
			mainPage += L" : D_Up + A";
			mainPage += newLine;
			mainPage += L" : D_Up + X";
			mainPage += newLine;
			mainPage += L" : D_Up + Y";
			mainPage += newLine;
			mainPage += L" : D_Up + B";
			mainPage += newLine;
			mainPage += L" : D-Right + X";
			mainPage += newLine;
			mainPage += L" : D-Right + Y";
			mainPage += newLine;
			mainPage += L" : D-Right + B";
			mainPage += newLine + newLine;
			mainPage += L": LB + RB";
			mainPage += newLine;
			mainPage += L"Console Commands : LB + B";
			return mainPage.c_str();
		}

		const wchar_t* KeyboardPage() {

			std::wstring keyboardPage;
			std::wstring newLine = L"\r\n";
			keyboardPage += L"Enter custom console commands";
			keyboardPage += newLine;
			keyboardPage += L"Example : i_unlimitedammo 1";
			return keyboardPage.c_str();
		}
	}

	void ShowMainPageUI() {

		const wchar_t* buttonLabels[] = { L"Continue" };
		xTools::Xam::ShowMessageBox(
			L"Crysis Trainer by XeCrippy",
			pages::MainPage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels)
		);
	}

	void ShowKeyboardUI()
	{
		DWORD hr = 0;
		HRESULT hre = 0;
		WCHAR r1[512];
		XOVERLAPPED kb_overlapped;
		
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		XInputGetState(0, &state);

		hre = XShowKeyboardUI(0, VKBD_DEFAULT, L"ammo 1", L"Custom Commands", pages::KeyboardPage(), r1, 512, &kb_overlapped); // show keyboard ui

		while (!XHasOverlappedIoCompleted(&kb_overlapped)) Sleep(25);

		if (hre == ERROR_IO_PENDING)  hr = _wtoi(r1); // returns input keyboard result

		std::string cmd = std::_Narrow_str(r1);

		funcs::ExecCommand(cmd.c_str());
	}

	void _Crysis::LoadPlugin() {

		ShowMainPageUI();

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_DOOM3BFG) {
			bool hasToggled = false;
			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					ShowMainPageUI();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::GodMode();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::InfinteAmmo();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					ShowKeyboardUI();
					hasToggled = true;
				}
			}
			if (hasToggled)Sleep(300);
		}
	}
}