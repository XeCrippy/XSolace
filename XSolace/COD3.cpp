#include "stdafx.h"
#include "COD3.h"

namespace COD3 {

	//bool minicon;

    void (*Cod3::Cbuf_ExecuteText)(int clientIndex, const char* cmd) = reinterpret_cast<void(*)(int, const char*)>(0x8247DBC8); 

	void Cod3::SendCommand(const char* cmd) {
		Cbuf_ExecuteText(0, cmd);
	}

	bool Cod3::MiniCon() {
		if (!minicon) {
			SendCommand("con_minicon 1;con_miniconlines 10;con_minicontime 999");
			xTools::Xam::XNotify("Mini Console : Enabled");
			minicon = true;
		}
		else {
			SendCommand("con_minicon 0;con_miniconlines 0;con_minicontime 0");
			xTools::Xam::XNotify("Mini Console : Disabled");
			minicon = false;
		}
		return minicon;
	}

	void Cod3::ToggleGodMode() {
		SendCommand("god");
		xTools::Xam::PulseController();
		xTools::Xam::XNotify("Toggled : God Mode");
		
	}

	void Cod3::ToggleNoClip() {
		SendCommand("noclip");
		xTools::Xam::PulseController();
		xTools::Xam::XNotify("Toggled : No Clip");
		
	}

	void Cod3::KeyboardMenu() {

		XINPUT_STATE state = { 0 };
		unsigned long hr = 0;
		HRESULT hre = 0;
		wchar_t r1[512];
		XOVERLAPPED kb_overlapped;

		ZeroMemory(&state, sizeof(XINPUT_STATE));

		XInputGetState(0, &state);

		hre = XShowKeyboardUI(0, VKBD_DEFAULT, L"god", L"COD 3 Console Commands", L"Enter Custom Console Commands\r\nExample: cg_fov 120", r1, 512, &kb_overlapped); // show keyboard ui

		while (!XHasOverlappedIoCompleted(&kb_overlapped)) Sleep(25);

		if (hre == ERROR_IO_PENDING)  hr = _wtoi(r1); // returns input keyboard result

		std::string cmd = std::_Narrow_str(r1);
		SendCommand(cmd.c_str());
	}

	 void Cod3::LoadPlugin() {

		 XINPUT_STATE state = { 0 };
		 ZeroMemory(&state, sizeof(state));

		 while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_COD3) {

			 bool hasToggled = false;

			 if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				 if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					 KeyboardMenu();
					 hasToggled = true;
				 }
				 if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					 ToggleGodMode();
					 hasToggled = true;
				 }
			 }
			 if (hasToggled) Sleep(300);
		 }
	 }
}