#include "stdafx.h"
#include "SonicGenerations.h"

namespace SonicGenerations {

	namespace vars {

		bool infRings = false;
		bool ringMultiply = false;
		bool timerFreeze = false;

		uint32_t freezeTimer = 0x82A21CF8;
		uint32_t freezeTimer_off = 0xEC01002A;
		uint32_t infiniteRings = 0x8289FCA4;
		uint32_t infiniteRings_off = 0x7D7E5850;
		uint32_t infiniteRings_on = 0x396B0000;
		uint32_t ringMultiplier = 0x828A3F24;
		uint32_t ringMultiplier_off = 0x7D6BF214;
		uint32_t ringMultiplier_on = 0x396B000A;

		uint32_t nop = 0x60000000;
		uint32_t ringsPtr = 0x839C46A0;
		uint32_t ringsOffset = 0x5B8;
	}

	namespace gameFuncs {
		int(__fastcall* AddLives)(int result, int a2) = reinterpret_cast<int(__fastcall*)(int result, int a2)>(0x82A30A78);
	}

	namespace funcs {
		void _AddLives(int lives) {
			gameFuncs::AddLives((int)0x003B1430, lives);
			xTools::Xam::PulseController();
		}

		void AddRings(int rings) {
			uint32_t ringsAddr = xTools::Memory::Read<uint32_t>(vars::ringsPtr) + vars::ringsOffset;
			xTools::Memory::Write<uint32_t>(ringsAddr, rings);
			xTools::Xam::PulseController();
		}

		bool FreezeTimer() {
			if (!vars::timerFreeze) {
				xTools::Memory::Write<uint32_t>(vars::freezeTimer, vars::nop);
				xTools::Xam::PulseController();
				xTools::Xam::XNotify("Freeze Timer : Enabled");
				vars::timerFreeze = true;
			}
			else {
				xTools::Memory::Write<uint32_t>(vars::freezeTimer, vars::freezeTimer_off);
				xTools::Xam::PulseController();
				xTools::Xam::XNotify("Freeze Timer : Disabled");
				vars::timerFreeze = false;
			}
			return vars::timerFreeze;
		}

		bool InfiniteRings() {
			if (!vars::infRings) {
				xTools::Memory::Write<uint32_t>(vars::infiniteRings, vars::infiniteRings_on);
				xTools::Xam::PulseController();
				xTools::Xam::XNotify("Infinite Rings : Enabled");
				vars::infRings = true;
			}
			else {
				xTools::Memory::Write<uint32_t>(vars::infiniteRings, vars::infiniteRings_off);
				xTools::Xam::PulseController();
				xTools::Xam::XNotify("Infinite Rings : Disabled");
				vars::infRings = false;
			}
			return vars::infRings;
		}

		bool RingsMultiplier() {
			if (!vars::ringMultiply) {
				xTools::Memory::Write<uint32_t>(vars::ringMultiplier, vars::ringMultiplier_on);
				xTools::Xam::PulseController();
				xTools::Xam::XNotify("Rings Multiplier : Enabled");
				vars::ringMultiply = true;
			}
			else {
				xTools::Memory::Write<uint32_t>(vars::ringMultiplier, vars::ringMultiplier_off);
				xTools::Xam::PulseController();
				xTools::Xam::XNotify("Rings Multiplier : Disabled");
				vars::ringMultiply = false;
			}
			return vars::ringMultiply;
		}
	}

	const wchar_t* MainPage() {
		std::wstring newLine = L"\r\n";
		std::wstring mainPage;
		mainPage += L"Infinite Rings : D_LEFT+A";
		mainPage += newLine;
		mainPage += L"Add 99 Rings : D_LEFT+X";
		mainPage += newLine;
		mainPage += L"Add 999 Rings : D_LEFT+Y";
		mainPage += newLine;
		mainPage += L"Add 99 Lives : D_LEFT+B";
		mainPage += newLine;
		mainPage += L"Ring Multiplier : D_UP+A";
		mainPage += newLine;
		mainPage += L"Freeze Timer : D_UP+X";
		return mainPage.c_str();
	}

	const wchar_t* MainTitle = L"Sonic Generations TU2";

	void _SonicGenerations::ShowMainPage() {

		const wchar_t* buttonLabels[] = { L"Continue",  L"Close" };
		uint32_t buttonPressedIndex = 0;
		uint32_t result = xTools::Xam::ShowMessageBox(
			MainTitle,
			MainPage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels),
			&buttonPressedIndex,
			XMB_ALERTICON,
			0
		);
	}

	void _SonicGenerations::LoadPlugin() {

		XINPUT_STATE state = { 0 };
		ZeroMemory(&state, sizeof(state));

		ShowMainPage();

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_SONICGENERATIONS) {

			bool hasToggled = false;
			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					ShowMainPage();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::InfiniteRings();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::AddRings(99);
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::AddRings(999);
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::_AddLives(99);
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::RingsMultiplier();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::FreezeTimer();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(300);
		}
	}
}