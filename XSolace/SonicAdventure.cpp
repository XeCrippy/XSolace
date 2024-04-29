#include "stdafx.h"
#include "SonicAdventure.h"

namespace SonicAdventure {

	void(__fastcall* Sonic::AddNumRing)(uint16_t ssNumber) = reinterpret_cast<void(__fastcall*)(uint16_t ssNumber)>(0x82259820);
	void(__fastcall* Sonic::SetTotalRing)(uint32_t num) = reinterpret_cast<void(__fastcall*)(uint32_t num)>(0x82259698);
	void(__fastcall* Sonic::SleepTimer)() = reinterpret_cast<void(__fastcall*)()>(0x82259D20);
	void(__fastcall* Sonic::WakeTimer)() = reinterpret_cast<void(__fastcall*)()>(0x82259D10);
	bool(*Sonic::WriteAchievements)(uint32_t ptr, int userIndex, int achievementID, bool isAsync) = reinterpret_cast<bool(*)(uint32_t ptr, int userIndex, int achievementID, bool isAsync)>(0x8277F718);

	void Sonic::Add999Rings() {
		AddNumRing(999u);
		xTools::Xam::PulseController();
	}

	void __fastcall Sonic::TimerSleep() {
		xTools::Memory::WriteUInt32(disableTimer, disableTimer_on);
		SleepTimer();
	}

	void __fastcall Sonic::TimerWake() {
		xTools::Memory::WriteUInt32(disableTimer, disableTimer_off);
		WakeTimer();
	}

	bool Sonic::InfRings() {
		if (!infRings) {
			xTools::Memory::WriteUInt32(addRingsOnDmg, addRingsOnDmg_on);
			xTools::Xam::PulseController();
			xTools::Xam::XNotify("Infinite Rings : Enabled");
			infRings = true;
		}
		else {
			xTools::Memory::WriteUInt32(addRingsOnDmg, addRingsOnDmg_off);
			xTools::Xam::PulseController();
			xTools::Xam::XNotify("Infinite Rings : Disabled");
			infRings = false;
		}
		return infRings;
	}

	bool Sonic::Timer() {
		if (!timer) {
			TimerSleep();
			xTools::Xam::PulseController();
			xTools::Xam::XNotify("Timer : Frozen");
			timer = true;
		}
		else {
			TimerWake();
			xTools::Xam::PulseController();
			xTools::Xam::XNotify("Timer : Unfrozen");
			timer = false;
		}
		return timer;
	}

	void Sonic::UnlockAchievements() {
		for (int i = 0; i < 20; i++) {
			WriteAchievements(0x4001F010, 0, i, true);
			Sleep(300);
		}
	}

	const wchar_t* Sonic::Welcome() {

		std::wstring newLine = L"\r\n";
		std::wstring welcomePage;
		welcomePage += L"Infinite Rings : Dpad_Left+A";
		welcomePage += newLine;
		welcomePage += L"Toggle Timer : Dpad_Left+X";
		welcomePage += newLine;
		welcomePage += L"Give 999 Rings : Dpad_Left+Y";
		welcomePage += newLine;
		welcomePage += L"Unlock All Achievements : Dpad_Left+B";
		welcomePage += newLine + newLine;
		welcomePage += L"Return Here : Dpad-LB+RB";
		return welcomePage.c_str();
	}

	const wchar_t* buttonLabels[] = { L"Continue" };

	void Sonic::MsgBox() {

		xTools::Xam::ShowMessageBox(
			L"Sonic Adventure Trainer",
			Welcome(),
			buttonLabels,
			ARRAYSIZE(buttonLabels),
			nullptr,
			XMB_ALERTICON
		);
	}

	void Sonic::LoadPlugin() {

		XINPUT_STATE state = { 0 };
		ZeroMemory(&state, sizeof(state));

		MsgBox();

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_SONICADVENTURE) {

			bool hasToggled = false;
			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					MsgBox();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					InfRings();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					Timer();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					Add999Rings();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					UnlockAchievements();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(500);
		}
	}
}

		