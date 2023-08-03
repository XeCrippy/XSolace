#include "stdafx.h"
#include "DeadRising2.h"

namespace DeadRising2 {

	namespace vars {

		bool god = false; 
		bool graphs = false;
		bool setHooks = false;
		bool ohk = false;

		uint32_t currentPP = 0xE7ACF4B8;
		uint32_t EnableRenderCPUBudgetChartz = 0x82B50F30;
		uint32_t enableRenderPerformanceInfoChartz = 0x82B50F2F; // byte
		uint32_t moneyPtr = 0xE7ACF490;
		uint32_t stHealth = 0x825FF2EC;

		uint32_t godMode_off = 0xD023002C;
		uint32_t nop = 0x60000000;
	}

	namespace gameFuncs {

		uint32_t(__fastcall *AddMoney)(uint32_t result, int money, int a3, int a4) = reinterpret_cast<uint32_t(__fastcall*)(uint32_t  result, int money, int a1, int a2)>(0x82601038);
	}

	namespace funcs {

		void _AddMoney(int money) {
			gameFuncs::AddMoney(vars::moneyPtr, money, 0, 0);
		}

		bool GodMode() {
			if (!vars::god) {
				xTools::Memory::WriteUInt32(vars::stHealth, vars::nop);
				xTools::Xam::XNotify("God Mode : Enabled");
				xTools::Xam::PulseController();
				vars::god = true;
			}
			else {
				xTools::Memory::WriteUInt32(vars::stHealth, vars::godMode_off);
				xTools::Xam::XNotify("God Mode : Disabled");
				xTools::Xam::PulseController();
				vars::god = false;
			}
			return vars::god;
		}

		void ModPP() {
			uint32_t currPP = xTools::Memory::ReadUInt32(vars::currentPP);
			xTools::Memory::WriteUInt32(vars::currentPP, 999999);
			xTools::Xam::XNotify("Added 999999 PP");
			xTools::Xam::PulseController();
		}

		bool ShowGraphs() {
			if (!vars::graphs) {
				xTools::Memory::WriteUInt8(vars::enableRenderPerformanceInfoChartz, 1);
				xTools::Memory::WriteUInt8(vars::EnableRenderCPUBudgetChartz, 1);
				xTools::Xam::XNotify("Performance Graphs : Enabled");
				xTools::Xam::PulseController();
				vars::graphs = true;
			}
			else {
				xTools::Memory::WriteUInt8(vars::enableRenderPerformanceInfoChartz, 0);
				xTools::Memory::WriteUInt8(vars::EnableRenderCPUBudgetChartz, 0);
				xTools::Xam::XNotify("Performance Graphs : Disabled");
				xTools::Xam::PulseController();
				vars::graphs = false;
			}
			return vars::graphs;
		}
	}

	void _DeadRising2::Page2() {

		const wchar_t* buttonLabels[] = { L"Back",  L"Close" };
		uint32_t buttonPressedIndex = 0;
		uint32_t result = xTools::Xam::ShowMessageBox(
			L"Dead Rising 2 Test",
			L"Page 2 Test",
			buttonLabels,
			ARRAYSIZE(buttonLabels),
			&buttonPressedIndex,
			XMB_ALERTICON,
			1
		);

		if (result == ERROR_SUCCESS) {
			switch (buttonPressedIndex) {
			case 0:
				Sleep(100);
				_DeadRising2::WelcomePage();
				break;
			default:
				break;
			}
		}
	}

	void _DeadRising2::WelcomePage() {

		const wchar_t* buttonLabels[] = { L"Next", L"Close" };
		uint32_t buttonPressedIndex = 0;
		uint32_t result = xTools::Xam::ShowMessageBox(
			L"Dead Rising 2 Test",
			L"Page 1 Test....Coming Soon",
			buttonLabels,
			ARRAYSIZE(buttonLabels),
			&buttonPressedIndex,
			XMB_ALERTICON,
			0
		);

		if (result == ERROR_SUCCESS) {
			switch (buttonPressedIndex) {
			case 0:
				Sleep(100);
				_DeadRising2::Page2();
				break;
			case 1:
				break;
			case 2:
				break;
			}
		}
	}

	void _DeadRising2::LoadPlugin() {

		XINPUT_STATE state = { 0 };

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_DEADRISING2) {
			
			bool hasToggled = false;

			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					_DeadRising2::WelcomePage();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(500);
		}
	}
}