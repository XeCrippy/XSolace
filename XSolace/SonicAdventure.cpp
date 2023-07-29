#include "stdafx.h"
#include "SonicAdventure.h"

namespace SonicAdventure {

	namespace vars {

		bool	infLives = false;
		bool infRings = false;
		bool timer = false;

		uint32_t addRingsOnDmg = 0x8225967C;
		uint32_t disableTimer = 0x82259D14; // 39600000

		uint32_t addRingsOnDmg_off = 0x39600000;
		uint32_t addRingsOnDmg_on = 0x396003E7;
		uint32_t disableTimer_on = 0x39600000;
		uint32_t disableTimer_off = 0x39600001;
	}

	namespace gameFuncs {

		void(__fastcall* AddNumRing)(uint16_t ssNumber) = reinterpret_cast<void(__fastcall*)(uint16_t ssNumber)>(0x82259820);
		void(__fastcall* SetTotalRing)(uint32_t num) = reinterpret_cast<void(__fastcall*)(uint32_t num)>(0x82259698);
		void(__fastcall* SleepTimer)() = reinterpret_cast<void(__fastcall*)()>(0x82259D20);
		void(__fastcall* WakeTimer)() = reinterpret_cast<void(__fastcall*)()>(0x82259D10);
	}

	namespace funcs {

		void Add999Rings() {
			gameFuncs::AddNumRing(999u);
			xTools::Xam::PulseController();
		}

		void __fastcall TimerSleep() {
			xTools::WriteUInt32(vars::disableTimer, vars::disableTimer_on);
			gameFuncs::SleepTimer();
		}

		void __fastcall TimerWake() {
			xTools::WriteUInt32(vars::disableTimer, vars::disableTimer_off);
			gameFuncs::WakeTimer();
		}

		bool InfRings() {
			if (!vars::infRings) {
				xTools::WriteUInt32(vars::addRingsOnDmg, vars::addRingsOnDmg_on);
				xTools::Xam::PulseController();
				xTools::Xam::XNotify("Infinite Rings : Enabled");
				vars::infRings = true;
			}
			else {
				xTools::WriteUInt32(vars::addRingsOnDmg, vars::addRingsOnDmg_off);
				xTools::Xam::PulseController();
				xTools::Xam::XNotify("Infinite Rings : Disabled");
				vars::infRings = false;
			}
			return vars::infRings;
		}

		bool Timer() {
			if (!vars::timer) {
				TimerSleep();
				xTools::Xam::PulseController();
				xTools::Xam::XNotify("Timer : Frozen");
				vars::timer = true;
			}
			else {
				TimerWake();
				xTools::Xam::PulseController();
				xTools::Xam::XNotify("Timer : Unfrozen");
				vars::timer = false;
			}
			return vars::timer;
		}
	}

	namespace pages {

		const wchar_t* Welcome() {

			std::wstring newLine = L"\r\n";
			std::wstring welcomePage;
			welcomePage += L"Infinite Rings : Dpad-Left+A";
			welcomePage += newLine;
			welcomePage += L"Toggle Timer : Dpad-Left+X";
			welcomePage += newLine;
			welcomePage += L"Give 999 Rings : Dpad-Left+Y";
			welcomePage += newLine + newLine;
			welcomePage += L"Return Here : Dpad-LB+RB";
			return welcomePage.c_str();
		}
	}

	const wchar_t* buttonLabels[] = { L"Continue" };

	void MsgBox() {

		xTools::Xam::ShowMessageBox(
			L"Sonic Adventure Trainer",
			pages::Welcome(),
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

					funcs::InfRings();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::Timer();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::Add999Rings();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(500);
		}
	}
}