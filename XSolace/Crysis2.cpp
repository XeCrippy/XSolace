#include "stdafx.h"
#include "Crysis2.h"

namespace Crysis2 {

	XINPUT_STATE state;

	int( *_Crysis2::ExecuteStringInternal)(uint32_t consolePtr, const char* command, bool bFromConsole, bool bSilentMode) = reinterpret_cast<int(*)(uint32_t, const char*, bool, bool)>(0x822D5B68); //0x82286300); crysis1

	void _Crysis2::ExecCommand(const char *command) {
		uint32_t cxconsole = *(uint32_t*)0x83AC6E58; //0x837CF198; crysis1
		ExecuteStringInternal(cxconsole, command, false, false);
	}

	bool _Crysis2::AdvancedAimAssist() {
		 
		uint32_t aim_assistFalloffDistance = *(uint32_t*)0x403CB744;
		uint32_t aim_assistGlidingMultiplier = *(uint32_t*)0x403CB6B8;
		uint32_t aim_assistMaxDistance = *(uint32_t*)0x403CB760;
		uint32_t aim_assistMaxDistanceTagged = *(uint32_t*)0x403CB70C;
		uint32_t aim_assistMaxDistance_IronSight = *(uint32_t*)0x403CB568;
		uint32_t aim_assistMinDistance = *(uint32_t*)0x403CB77C;
		uint32_t aim_assistMinTurnScale = *(uint32_t*)0x403CB69C;
		uint32_t aim_assistMinTurnScale_IronSight = *(uint32_t*)0x403CB54C;
		uint32_t aim_assistSnapRadiusScale = *(uint32_t*)0x403CB5D8;
		uint32_t aim_assistSnapRadiusTaggedScale = *(uint32_t*)0x403CB5BC;
		uint32_t aim_assistStrength = *(uint32_t*)0x403CB5F4;
		uint32_t aim_assistStrength_IronSight = *(uint32_t*)0x403CB5A0;

		if (!aimAssist) {
			xTools::Memory::WriteFloat(aim_assistFalloffDistance, 9999.0f);
			xTools::Memory::WriteFloat(aim_assistGlidingMultiplier, 99.0);
			xTools::Memory::WriteFloat(aim_assistMaxDistance, 9999.0f);
			xTools::Memory::WriteFloat(aim_assistMaxDistanceTagged, 9999.0f);
			xTools::Memory::WriteFloat(aim_assistMaxDistance_IronSight, 9999.0f);
			xTools::Memory::WriteFloat(aim_assistMinDistance, 0);
			//xTools::Memory::WriteFloat(aim_assistMinTurnScale, 0);
			//xTools::Memory::WriteFloat(aim_assistMinTurnScale_IronSight, 0);
			xTools::Memory::WriteFloat(aim_assistSnapRadiusScale, 30.0f);
			xTools::Memory::WriteFloat(aim_assistSnapRadiusTaggedScale, 30.0f);
			xTools::Memory::WriteFloat(aim_assistStrength, 99.0f);
			xTools::Memory::WriteFloat(aim_assistStrength_IronSight, 99.0f);
			xTools::Xam::XNotify("Enhanced Aim Assist : Enabled");
			aimAssist = true;
		}
		else {
			xTools::Memory::WriteFloat(aim_assistFalloffDistance, 50.0f);
			xTools::Memory::WriteFloat(aim_assistGlidingMultiplier, 2.0);
			xTools::Memory::WriteFloat(aim_assistMaxDistance, 50.0f);
			xTools::Memory::WriteFloat(aim_assistMaxDistanceTagged, 50.0f);
			xTools::Memory::WriteFloat(aim_assistMaxDistance_IronSight, 50.0f);
			xTools::Memory::WriteFloat(aim_assistMinDistance, 0);
			xTools::Memory::WriteFloat(aim_assistMinTurnScale, 0);
			xTools::Memory::WriteFloat(aim_assistSnapRadiusScale, 1.0f);
			xTools::Memory::WriteFloat(aim_assistSnapRadiusTaggedScale, 1.0f);
			xTools::Memory::WriteFloat(aim_assistStrength, 0.5f);
			xTools::Memory::WriteFloat(aim_assistStrength_IronSight, 0.5f);
			xTools::Xam::XNotify("Enhanced Aim Assist : Disabled");
			aimAssist = false;
		}
		return aimAssist;
	}

	bool _Crysis2::DemigodMode() {

		uint32_t pl_health_normal_threshold_time_to_regenerateSP = xTools::Memory::ReadUInt32(0x403CC138);
		uint32_t pl_health_normal_regeneration_rateSP = xTools::Memory::ReadUInt32(0x403CC170);

		if (!godMode) {
			xTools::Memory::WriteFloat(pl_health_normal_threshold_time_to_regenerateSP, 0);
			xTools::Memory::WriteFloat(pl_health_normal_regeneration_rateSP, 9999);
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

	bool _Crysis2::InfinteAmmo() {
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

	bool _Crysis2::ToggleFov() {

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
		
	const wchar_t* _Crysis2::MainPage() {

		std::wstring newLine = L"\r\n";
		std::wstring mainPage;
		mainPage += L"Demigod Mode : D_LEFT+A";
		mainPage += newLine;
		mainPage += L"Infinite Ammo : D_LEFT+X";
		mainPage += newLine;
		mainPage += L"Enhanced Aim Assist : D_LEFT+Y";
		mainPage += newLine;
		mainPage += L"Far Fov : D_LEFT+B";
		mainPage += newLine;
		mainPage += L"Return Here : LB+RB";
		return mainPage.c_str();
	}

	const wchar_t* _Crysis2::KeyboardPage() {

		std::wstring keyboardPage;
		std::wstring newLine = L"\r\n";
		keyboardPage += L"Enter custom console commands";
		keyboardPage += newLine;
		keyboardPage += L"Example : i_unlimitedammo 1";
		return keyboardPage.c_str();
	}

	void _Crysis2::ShowMainPageUI() {

		const wchar_t* buttonLabels[] = { L"Continue" };
		xTools::Xam::ShowMessageBox(
			L"Crysis 2 Trainer by XeCrippy",
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

					DemigodMode();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					InfinteAmmo();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					ToggleFov();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					AdvancedAimAssist();
					hasToggled = true;
				}
			}
			if (hasToggled)Sleep(300);
		}
	}
}