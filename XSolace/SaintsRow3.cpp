#include "stdafx.h"
#include "SaintsRow3.h"

namespace SaintsRow3 {

	namespace vars {

		bool godMode = false;
		bool infAmmo = false;
		bool infSprint = false;
		bool neverDie = false;
		bool pimpsNhoes = false;
		bool superBeerMuscles = false;
	}

	namespace gameFuncs {
		int(*AddGangNoteriety)() = reinterpret_cast<int(*)()>(0x823A0A90);
		int(*AddPoliceNoteriety)() = reinterpret_cast<int(*)()>(0x823A0A20);
		void(*GodMode_On)() = reinterpret_cast<void(*)()>(0x823A0B38);
		void(*GodMode_Off)() = reinterpret_cast<void(*)()>(0x823A2260);
		void(*InfiniteSprint_On)() = reinterpret_cast<void(*)()>(0x823A0B20);
		void(*InfiniteSprint_Off)() = reinterpret_cast<void(*)()>(0x823A1ED8);
		int(*InstantCash)() = reinterpret_cast<int(*)()>(0x823A08D0);
		int(*InstantRespect)() = reinterpret_cast<int(*)()>(0x823A0918);
		int(*NeverDie_On)() = reinterpret_cast<int(*)()>(0x823A16A8);
		int(*NeverDie_Off)() = reinterpret_cast<int(*)()>(0x823A24B0);
		int(*PimpsNHoesPeds_On)() = reinterpret_cast<int(*)()>(0x823A1A38);
		void(*PimpsNHoesPeds_Off)() = reinterpret_cast<void(*)()>(0x823A1A20);
		int(*RemoveGangNoteriety)() = reinterpret_cast<int(*)()>(0x823A0978);
		int(*RemovePoliceNoteriety)() = reinterpret_cast<int(*)()>(0x823A0930);
		void(*SuperBeerMuscles_On)() = reinterpret_cast<void(*)()>(0x823A0BF0);
		void(*SuperBeerMuscles_Off)() = reinterpret_cast<void(*)()>(0x823A1F08);
		void(*UnlimitedClip_On)() = reinterpret_cast<void(*)()>(0x823A17A8);
		void(*UnlimitedClip_Off)() = reinterpret_cast<void(*)()>(0x823A25E8);
	}

	namespace funcs {
		void _AddGangNoteriety() {
			gameFuncs::AddGangNoteriety();
		}

		void _AddPoliceNoteriety() {
			gameFuncs::AddPoliceNoteriety();
		}

		bool GodMode() {
			if (!vars::godMode) {
				//gameFuncs::GodMode_On();
				gameFuncs::NeverDie_On();
				xTools::Xam::XNotify("God Mode : Enabled");
				vars::godMode = true;
			}
			else {
				//gameFuncs::GodMode_Off();
				gameFuncs::NeverDie_Off();
				xTools::Xam::XNotify("God Mode : Disabled");
				vars::godMode = false;
			}
			return vars::godMode;
		}

		bool InfiniteSprint() {
			if (!vars::infSprint) {
				gameFuncs::InfiniteSprint_On();
				xTools::Xam::XNotify("Infinite Sprint : Enabled");
				vars::infSprint = true;
			}
			else {
				gameFuncs::InfiniteSprint_Off();
				xTools::Xam::XNotify("Infnite Sprint : Disabled");
				vars::infSprint = false;
			}
			return vars::infSprint;
		}

		void InstantCash() {
			gameFuncs::InstantCash();
			xTools::Xam::XNotify("Gave Player $100,000");
		}

		void InstantRespect() {
			gameFuncs::InstantRespect();
			xTools::Xam::XNotify("Gave Player 100,000 Respect");
		}

		bool NeverDie() {
			if (!vars::neverDie) {
				gameFuncs::NeverDie_On();
				vars::neverDie = true;
			}
			else {
				gameFuncs::NeverDie_Off();
				vars::neverDie = false;
			}
			return vars::neverDie;
		}

		bool PimpsNHoesPeds() {
			if (!vars::pimpsNhoes) {
				gameFuncs::PimpsNHoesPeds_On();
				xTools::Xam::XNotify("Pimps N Hoes Pedestrians : Enabled");
				vars::pimpsNhoes = true;
			}
			else {
				gameFuncs::PimpsNHoesPeds_Off();
				xTools::Xam::XNotify("Pimps N Hoes Pedestrians : Disabled");
				vars::pimpsNhoes = false;
			}
			return vars::pimpsNhoes;
		}

		void RemoveGangNoteriety() {
			gameFuncs::RemoveGangNoteriety();
			xTools::Xam::XNotify("Removed Gang Noteriety");
		}

		void RemovePoliceNoteriety() {
			gameFuncs::RemovePoliceNoteriety();
			xTools::Xam::XNotify("Removed Police Noteriety");
		}

		bool SuperBeerMuscles() {
			if (!vars::superBeerMuscles) {
				gameFuncs::SuperBeerMuscles_On();
				xTools::Xam::XNotify("Super Beer Muscles : Enabled");
				vars::superBeerMuscles = true;
			}
			else {
				gameFuncs::SuperBeerMuscles_Off();
				xTools::Xam::XNotify("Super Beer Muscles : Disabled");
				vars::superBeerMuscles = false;
			}
			return vars::superBeerMuscles;
		}

		bool UnlimitedClip() {
			if (!vars::infAmmo) {
				gameFuncs::UnlimitedClip_On();
				xTools::Xam::XNotify("Infinite Ammo : Enabled");
				vars::infAmmo = true;
			}
			else {
				gameFuncs::UnlimitedClip_Off();
				xTools::Xam::XNotify("Infinite Ammo : Disabled");
				vars::infAmmo = false;
			}
			return vars::infAmmo;
		}
	}

	namespace pages {
		const wchar_t* MainPage() {
			std::wstring newLine = L"\r\n";
			std::wstring mainPage;
			mainPage += L"God Mode : D_LEFT+A";
			mainPage += newLine;
			mainPage += L"Infinite Ammo : D_LEFT+X";
			mainPage += newLine;
			mainPage += L"Infinite Sprint : D_LEFT+Y";
			mainPage += newLine;
			mainPage += L"Instant Cash : D_LEFT+B";
			mainPage += newLine;
			mainPage += L"Instant Respect : D_UP+A";
			mainPage += newLine;
			mainPage += L"Remove Gang Noteriety : D_UP+X";
			mainPage += newLine;
			mainPage += L"Remove Police Noteriety : D_UP+Y";
			mainPage += newLine;
			mainPage += L"Super Beer Muscles : D_UP+B";
			mainPage += newLine;
			mainPage += L"Pimps N Hoes Peds : D_RIGHT+A";
			mainPage += newLine;
			mainPage += L"Add Gang Noteriety : D_RIGHT+X";
			mainPage += newLine;
			mainPage += L"Add Police Noteriety : D_RIGHT+Y";
			return mainPage.c_str();
		}
	}

	namespace pageTitles {
		const wchar_t* mainTitle = L"Saints Row The Third TU4";
	}

	void ShowMainPageUI() {
		const wchar_t* buttonLabels[] = { L"Continue" };
		xTools::Xam::ShowMessageBox(
			pageTitles::mainTitle,
			pages::MainPage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels)
		);
	}

	void SR3::LoadPlugin() {

		XINPUT_STATE state = { 0 };
		ShowMainPageUI();

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_SAINTSROW3) {
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

					funcs::UnlimitedClip();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::InfiniteSprint();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::InstantCash();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::InstantRespect();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::RemoveGangNoteriety();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::RemovePoliceNoteriety();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::SuperBeerMuscles();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::PimpsNHoesPeds();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::_AddGangNoteriety();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::_AddPoliceNoteriety();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(300);
		}
	}
}