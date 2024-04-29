#include "stdafx.h"
#include "Left4Dead2.h"

namespace Left4Dead2 {

	bool godMode = false;
	bool infAmmo = false;
	bool lowGravity = false;
	bool noClip = false;
	bool noTarget = false;
	bool showGraphs = false;
	bool showInfo = false;
	bool slipperyFloors = false;

	XINPUT_STATE state = { 0 };

	int(__fastcall* Cbuf_AddText)(int a1, const char* cmd, int a2) = reinterpret_cast<int(__fastcall*)(int, const char*, int)>(0x86BCDDB0);
	
	void L4D2::SendCommand(const char* cmd) {
		Cbuf_AddText(0, cmd, 0);
	}

	bool L4D2::DebugInfo() {
		if (!showInfo) {
			SendCommand("cl_showfps 4;cl_showpos 1;say Show Debug Info Enabled");
			showInfo = true;
		}
		else {
			SendCommand("cl_showfps 0;cl_showpos 0;say Show Debug Info Disabled");
			showInfo = false;
		}
		return showInfo;
	}

	bool L4D2::GodMode() {
		if (!godMode) {
			SendCommand("god 1;say God Mode Enabled");
			godMode = true;
		}
		else {
			SendCommand("god 0;say God Mode Disabled");
			godMode = false;
		}
		return godMode;
	}

	bool L4D2::InfiniteAmmo() {
		if (!infAmmo) {
			SendCommand("sv_infinite_ammo 1;say Infinite Ammo Enabled");
			infAmmo = true;
		}
		else {
			SendCommand("sv_infinite_ammo 0;say Infinite Ammo Disabled");
			infAmmo = false;
		}
		return infAmmo;
	}

	bool L4D2::LowGravity() {
		if (!lowGravity) {
			SendCommand("sv_gravity 200;say Low Gravity Enabled");
			lowGravity = true;
		}
		else {
			SendCommand("sv_gravity 800;say Low Gravity Disabled");
			lowGravity = false;
		}
		return lowGravity;
	}

	void L4D2::NoClip() {
		SendCommand("noclip;say Toggled No Clip");
	}

	void L4D2::Shake() {
		SendCommand("shake");
	}

	bool L4D2::ShowGraphs() {
		if (!showGraphs) {
			SendCommand("+graph;say Show Performance Graphs Enabled");
			showGraphs = true;
		}
		else {
			SendCommand("-graph;say Show Performance Graphs Disabled");
			showGraphs = false;
		}
		return showGraphs;
	}

	bool L4D2::SlipperyFloors() {
		if (!slipperyFloors) {
			SendCommand("sv_friction 0.5;say Slippery Floors Enabled");
			slipperyFloors = true;
		}
		else {
			SendCommand("sv_friction 4.0;say Slippery Floors Disabled");
			slipperyFloors = false;
		}
		return slipperyFloors;
	}

	const wchar_t* L4D2::KeyboardPage() {

		std::wstring kbpage;
		std::wstring newLine = L"\r\n";
		kbpage += L"[*] sv_cheats are enabled so most common cvars work";
		kbpage += newLine;
		kbpage += L"[*] Examples : ";
		kbpage += newLine;
		kbpage += L"[*] sv_infinite_ammo 1";
		kbpage += newLine;
		kbpage += L"[*] sv_infinite_ammo 1;cl_fov 120";
		return kbpage.c_str();
	}

	const wchar_t* L4D2::WelcomePage() {
		std::wstring newLine = L"\r\n";
		std::wstring welcomePage;
		welcomePage += L"God Mode : D_LEFT+A";
		welcomePage += newLine;
		welcomePage += L"Infinite Ammo : D_LEFT+X";
		welcomePage += newLine;
		welcomePage += L"Show Debug Info : D_LEFT+Y";
		welcomePage += newLine;
		welcomePage += L"Show Performance Graphs : D_LEFT+B";
		welcomePage += newLine;
		welcomePage += L"Slippery Floor : D_UP+A";
		welcomePage += newLine;
		welcomePage += L"Low Gravity : D_UP+X";
		welcomePage += newLine;
		welcomePage += L"No Clip : D_UP+Y";
		welcomePage += newLine;
		welcomePage += L"Return Here : LB+RB";
		welcomePage += newLine;
		welcomePage += L"Custom Console Commands : LB+X";
		return welcomePage.c_str();
	}

	void L4D2::KeyboardMenu() {

		unsigned long hr = 0;
		HRESULT hre = 0;
		wchar_t r1[512];
		XOVERLAPPED kb_overlapped;

		ZeroMemory(&state, sizeof(XINPUT_STATE));

		XInputGetState(0, &state);

		hre = XShowKeyboardUI(0, VKBD_DEFAULT, L"say My Nuts Itch", L"Console Commands", KeyboardPage(), r1, 512, &kb_overlapped); // show keyboard ui

		while (!XHasOverlappedIoCompleted(&kb_overlapped)) Sleep(25);

		if (hre == ERROR_IO_PENDING)  hr = _wtoi(r1); // returns input keyboard result

		std::string cmd; //= std::_Narrow_str(r1);
		cmd += std::_Narrow_str(r1);
		cmd += ";say Sent custom cvar : ";
		cmd += std::_Narrow_str(r1);
		SendCommand(cmd.c_str());
	}

	void L4D2::WelcomePage_() {
		const wchar_t* buttonLabels[] = { L"Continue" };
		const wchar_t* title = L"Left 4 Dead 2 TU6";
		xTools::Xam::ShowMessageBox(
			title,
			WelcomePage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels)
		);
	}

	void L4D2::LoadPlugin() {

		//WelcomePage();
		xTools::Xam::XNotify("L4D2 cheats loaded. Press LB+X in game for custom commands");
		SendCommand("sv_cheats 1;set developer 1");

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_LEFT4DEAD2) {

			bool hasToggled = false;

			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					WelcomePage();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					GodMode();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					InfiniteAmmo();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					DebugInfo();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					ShowGraphs();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					SlipperyFloors();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					LowGravity();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					KeyboardMenu();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(300);
		}
	}
}