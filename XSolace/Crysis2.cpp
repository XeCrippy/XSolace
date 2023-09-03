#include "stdafx.h"
#include "Crysis2.h"

namespace Crysis2 {

	XINPUT_STATE state;

	bool fov = false;
	bool godMode = false;
	bool infiniteAmmo = false;

	void(__fastcall *ExecuteStringInternal)(uint32_t consolePtr, const char* command, int bFromConsole, int bSilentMode) = reinterpret_cast<void(__fastcall*)(uint32_t, const char*, int, int)>(0x822D5B68); //0x82286300); crysis1

	void ExecCommand(const char* command) {
		uint32_t cxconsole = *(uint32_t*)0x83AC6E58; //0x837CF198; crysis1
		ExecuteStringInternal(cxconsole, command, 0, 0);
	}

	bool GodMode() {

		uint32_t pl_health_normal_threshold_time_to_regenerateSP = xTools::Memory::ReadUInt32(0x403CC138);
		uint32_t pl_health_normal_regeneration_rateSP = xTools::Memory::ReadUInt32(0x403CC170);

		if (!godMode) {
			xTools::Memory::WriteFloat(pl_health_normal_threshold_time_to_regenerateSP, -1.0f);
			xTools::Memory::WriteFloat(pl_health_normal_regeneration_rateSP, 999);
			xTools::Xam::XNotify("Demigod Mode : Enabled");
			godMode = true;
		}
		else {
			xTools::Memory::WriteFloat(pl_health_normal_threshold_time_to_regenerateSP, 15.0f);
			xTools::Memory::WriteUInt32(pl_health_normal_regeneration_rateSP, 2);
			xTools::Xam::XNotify("Demigod Mode : Disabled");
			godMode = false;
		}
		return godMode;
	}

	bool InfinteAmmo() {
		uint32_t ammo = 0x82FFB5B8;
		uint32_t nop = 0x60000000;
		uint32_t ammo_off = 0x90AB0004;

		if (!infiniteAmmo) {
			xTools::Memory::WriteUInt32(ammo, nop);
			xTools::Xam::XNotify("Infinite Ammo : Enabled");
			infiniteAmmo = true;
		}
		else {
			xTools::Memory::WriteUInt32(ammo, ammo_off);
			xTools::Xam::XNotify("Infinite Ammo : Disabled");
			infiniteAmmo = false;
		}
		return infiniteAmmo;
	}

	bool ToggleFov() {

		uint32_t cl_fov = xTools::Memory::ReadUInt32(0x83C5322C);

		if (!fov) {
			xTools::Memory::WriteFloat(cl_fov, 90.0f);
			xTools::Xam::XNotify("Far FOV : Enabled");
		    fov = true;
		}
		else {
			xTools::Memory::WriteFloat(cl_fov, 55.0f);
			xTools::Xam::XNotify("Far FOV : Disabled");
			fov = false;
		}
		return fov;
	}
		
	const wchar_t* MainPage() {

		std::wstring newLine = L"\r\n";
		std::wstring mainPage;
		mainPage += L"God Mode : D_LEFT+A";
		mainPage += newLine;
		mainPage += L"Infinite Ammo : D_LEFT+X";
		mainPage += newLine;
		mainPage += L"Far Fov : D_LEFT+Y";
		mainPage += newLine + newLine;
		mainPage += L"Console Commands : LB+B";
		mainPage += newLine;
		mainPage += L"Return Here : LB+RB";
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

	void ShowMainPageUI() {

		const wchar_t* buttonLabels[] = { L"Continue" };
		xTools::Xam::ShowMessageBox(
			L"Crysis Trainer by XeCrippy",
			MainPage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels)
		);
	}

	void _Crysis2::LoadPlugin() {

		ShowMainPageUI();

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_CRYSIS2) {
			bool hasToggled = false;
			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					ShowMainPageUI();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					GodMode();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					InfinteAmmo();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					ToggleFov();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					hasToggled = true;
				}
			}
			if (hasToggled)Sleep(500);
			hasToggled = false;
		}
	}
}