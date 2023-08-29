#include "stdafx.h"
#include "SleepingDogs.h"

namespace SleepingDogs {

	namespace vars {

		bool godMode = false;
		bool maxHealth = false;

		uint32_t moneyPtr = 0x8304CDFC;
		uint32_t moneyOffset = 0x3C0;
		uint32_t playerPtr = 0x82FDEA08;
		uint32_t playerPtrOffset = 0x1C3A0;
		uint32_t healthOffset = 0x1C3CC;
		uint32_t maxHealthOffset = 0x1C3D4;
	}

	namespace gameFuncs {
		//BOOL __fastcall AddHealth(int a1, unsigned int a2, int a3)
		bool(__fastcall* AddHealth)(int playerPtr, uint32_t healthValue, int a3) = reinterpret_cast<bool(__fastcall*)(int playerPtr, uint32_t healthValue, int a3)>(0x82793720);
	}

	namespace funcs {

		uint32_t GetHealthAddr() {
			return xTools::Memory::ReadUInt32(vars::playerPtr) + vars::healthOffset;
		}

		uint32_t GetMaXHealthAddr() {
			return xTools::Memory::ReadUInt32(vars::playerPtr) + vars::maxHealthOffset;
		}
		uint32_t GetMoneyAddr() {
			return xTools::Memory::ReadUInt32(vars::moneyPtr) + vars::moneyOffset;
		}

		uint32_t GetPlayerStructAddr() {
			return xTools::Memory::ReadUInt32(vars::playerPtr) + vars::playerPtrOffset;
		}

		void PlayerMaxHealth() {
				xTools::Memory::WriteFloat(GetMaXHealthAddr(), 9999999.0f);
				gameFuncs::AddHealth((int)GetPlayerStructAddr(), 9999999u, 0);
				xTools::Xam::PulseController();
				xTools::Xam::XNotify("Gave Player 9999999 Health");
		}

		void Give5k() {
			uint32_t currMoney = xTools::Memory::ReadUInt32(GetMoneyAddr());
			xTools::Memory::WriteUInt32(GetMoneyAddr(), currMoney + 5000);
			xTools::Xam::PulseController();
			xTools::Xam::XNotify("Gave player $5,000");
		}

		void Give50K() {
			uint32_t currMoney = xTools::Memory::ReadUInt32(GetMoneyAddr());
			xTools::Memory::WriteUInt32(GetMoneyAddr(), currMoney + 50000);
			xTools::Xam::PulseController();
			xTools::Xam::XNotify("Gave player $50,000");
		}
	}

	namespace pages {

		const wchar_t* MainPage() {
			std::wstring newLine = L"\r\n";
			std::wstring mainPage;
			mainPage += L"Give 9999999 Health : D_LEFT+A";
			mainPage += newLine;
			mainPage += L"Give Player $5K : D_LEFT+X";
			mainPage += newLine;
			mainPage += L"Give Player $50K : D_LEFT+Y";
			mainPage += newLine + newLine;
			mainPage += L"More coming soon....";
			return mainPage.c_str();
		}
	}

	void ShowMainPage() {

		const wchar_t* buttonLabels[] = { L"Continue",  L"Close" };
		uint32_t buttonPressedIndex = 0;
		xTools::Xam::ShowMessageBox(
			L"Sleeping Dogs TU1",
			pages::MainPage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels),
			&buttonPressedIndex,
			XMB_ALERTICON,
			1
		);
	}

	void _SleepingDogs::LoadPlugin() {

		XINPUT_STATE state = { 0 };
		ZeroMemory(&state, sizeof(state));

		ShowMainPage();

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_SLEEPINGDOGS) {
			bool hasToggled = false;
			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					ShowMainPage();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::PlayerMaxHealth();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::Give5k();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::Give50K();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(300);
		}
	}
}