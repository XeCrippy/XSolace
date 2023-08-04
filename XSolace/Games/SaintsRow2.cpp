#include "stdafx.h"
#include "SaintsRow2.h"

namespace SaintsRow2 {

	namespace vars {

		bool bushwickBill = false;
		bool elevatorToHeaven = false;
		bool giantPlayer = false;
		bool infiniteAmmo = false;
		bool infiniteSprint = false;
		bool neverDie = false;
		bool rainingPeds = false;
		bool removeNoteriety = false;
		bool superBeerMuscles = false;
		bool superExplosions = false;
		bool tinyPlayer = false;

		uint32_t giveMoneyAmount = 0x82B76378; // float
		uint32_t money = 0x83EB1274;
		uint32_t playerSize = 0x83A48960; //
	}

	namespace gameFuncs {

		void(*addGangNoteriety)() = reinterpret_cast<void(*)()>(0x82390830);//
		int(*addPoliceNoteriety)() = reinterpret_cast<int(*)()>(0x823907C0);//
		void(*giveMoney)() = reinterpret_cast<void(*)()> (0x82390680); //
		int(*bushwickBill_on)() = reinterpret_cast<int(*)()>(0x82390BD0);//
		int(*bushwickBill_off)() = reinterpret_cast<int(*)()>(0x823916C8);//
		void(*elevatorToHeaven_on)() = reinterpret_cast<void(*)()>(0x823914F8);//
		int(*elevatorToHeaven_off)() = reinterpret_cast<int(*)()>(0x82391C60);//
		void(*infiniteAmmo_on)() = reinterpret_cast<void(*)()>(0x82391220);//
		void(*infiniteAmmo_off)() = reinterpret_cast<void(*)()>(0x82391A38);//
		void(*infiniteSprint_on)() = reinterpret_cast<void(*)()>(0x823908F0);//
		void(*infiniteSprint_off)() = reinterpret_cast<void(*)()>(0x823915E0);//
		int(*neverDie_on)() = reinterpret_cast<int(*)()>(0x823911A0);//
		int(*neverDie_off)() = reinterpret_cast<int(*)()>(0x82391980);//
		void(*rainingPeds_on)() = reinterpret_cast<void(*)()>(0x82391078);//
		void(*rainingPeds_off)() = reinterpret_cast<void(*)()>(0x823918B0);//
		int(*removeGangNoteriety)() = reinterpret_cast<int(*)()>(0x82390710);//
		int(*removePoliceNoteriety)() = reinterpret_cast<int(*)()>(0x823906C0);//
		int(*superBeerMuscles_on)() = reinterpret_cast<int(*)()>(0x82390968);
		int(*superBeerMuscles_off)() = reinterpret_cast<int(*)()>(0x82391610);
		void(*superExplosions_on)() = reinterpret_cast<void(*)()>(0x82391470);
		void(*superExplosions_off)() = reinterpret_cast<void(*)()>(0x82391BD8);
	}

	namespace funcs {

		void GiveMoney() {
			uint32_t currMoney = xTools::Memory::ReadUInt32(vars::money);
			uint32_t newMoney = currMoney + 1000000u;
			xTools::Memory::WriteUInt32(vars::money, newMoney);
			xTools::Xam::XNotify("Gave player $10K");
		}

		void GiveNoteriety() {
			gameFuncs::addGangNoteriety();
			gameFuncs::addPoliceNoteriety();
			xTools::Xam::XNotify("Added Noteriety");
		}

		void RemoveNoteriety() {
			gameFuncs::removeGangNoteriety();
			gameFuncs::removePoliceNoteriety();
			xTools::Xam::XNotify("Cleared Noteriety");
		}

		bool BushwickBill() {
			if (!vars::bushwickBill) {
				gameFuncs::bushwickBill_on();
				xTools::Xam::XNotify("Bushwick Bill : Enabled");
				vars::bushwickBill = true;
			}
			else {
				gameFuncs::bushwickBill_off();
				xTools::Xam::XNotify("Bushwick Bill : Disabled");
				vars::bushwickBill = false;
			}
			return vars::bushwickBill;
		}

		bool ElevatorToHeaven() {
			if (!vars::elevatorToHeaven) {
				gameFuncs::elevatorToHeaven_on();
				xTools::Xam::XNotify("Elevator To Heaven : Enabled");
				vars::elevatorToHeaven = true;
			}
			else {
				gameFuncs::elevatorToHeaven_on();
				xTools::Xam::XNotify("Elevator To Heaven : Disabled");
				vars::elevatorToHeaven = false;
			}
			return vars::elevatorToHeaven;
		}

		bool GiantPlayer() {
			if (!vars::giantPlayer) {
				xTools::Memory::WriteFloat(vars::playerSize, 2.0);
				xTools::Xam::XNotify("Giant Player : Enabled");
				vars::giantPlayer = true;
			}
			else {
				xTools::Memory::WriteFloat(vars::playerSize, 0.0f);
				xTools::Xam::XNotify("Giant Player : Disabled");
				vars::giantPlayer = false;
			}
			return vars::giantPlayer;
		}

		bool InfiniteAmmo() {
			if (!vars::infiniteAmmo) {
				gameFuncs::infiniteAmmo_on();
				xTools::Xam::XNotify("Infinite Ammo : Enabled");
				vars::infiniteAmmo = true;
			}
			else {
				gameFuncs::infiniteAmmo_off();
				xTools::Xam::XNotify("Infinite Ammo : Disabled");
				vars::infiniteAmmo = false;
			}
			return vars::infiniteAmmo;
		}

		bool InfiniteSprint() {
			if (!vars::infiniteSprint) {
				gameFuncs::infiniteSprint_on();
				xTools::Xam::XNotify("Infinite Sprint : Enabled");
				vars::infiniteSprint = true;
			}
			else {
				gameFuncs::infiniteSprint_off();
				xTools::Xam::XNotify("Infinite Sprint : Disabled");
				vars::infiniteSprint = false;
			}
			return vars::infiniteSprint;
		}

		bool NeverDie() {
			if (!vars::neverDie) {
				gameFuncs::neverDie_on();
				xTools::Xam::XNotify("God Mode : Enabled");
				vars::neverDie = true;
			}
			else {
				gameFuncs::neverDie_on();
				xTools::Xam::XNotify("God Mode : Disabled");
				vars::neverDie = true;
			}
			return vars::neverDie;
		}

		bool RainingPeds() {
			if (!vars::rainingPeds) {
				gameFuncs::rainingPeds_on();
				xTools::Xam::XNotify("Raining Peds : Enabled");
				vars::rainingPeds = true;
			}
			else {
				gameFuncs::rainingPeds_off();
				xTools::Xam::XNotify("Raining Peds : Disabled");
				vars::rainingPeds = false;
			}
			return vars::rainingPeds;
		}

		bool SuperBeerMuscles() {
			if (!vars::superBeerMuscles) {
				gameFuncs::superBeerMuscles_on();
				xTools::Xam::XNotify("Super Beer Muscles : Enabled");
				vars::superBeerMuscles = true;
			}
			else {
				gameFuncs::superBeerMuscles_off();
				xTools::Xam::XNotify("Super Beer Muscles : Disabled");
				vars::superBeerMuscles = false;
			}
			return vars::superBeerMuscles;
		}

		bool SuperExplosions() {
			if (!vars::superExplosions) {
				gameFuncs::superExplosions_on();
				xTools::Xam::XNotify("Super Explosions : Enabled");
				vars::superExplosions = true;
			}
			else {
				gameFuncs::superExplosions_off();
				xTools::Xam::XNotify("Super Explosions : Disabled");
				vars::superExplosions = false;
			}
			return vars::superExplosions;
		}

		bool TinyPlayer() {
			if (!vars::tinyPlayer) {
				xTools::Memory::WriteFloat(vars::playerSize, 0.5f);
				xTools::Xam::XNotify("Tiny Player : Enabled");
				vars::tinyPlayer = true;
			}
			else {
				xTools::Memory::WriteFloat(vars::playerSize, 0.0f);
				xTools::Xam::XNotify("Tiny Player : Disabled");
				vars::tinyPlayer = false;
			}
			return vars::tinyPlayer;
		}
	}

	namespace pages {

		const wchar_t* MainPage() {

			std::wstring newLine = L"\r\n";
			std::wstring mainPage;
			mainPage += L"God Mode : D-Left + X";
			mainPage += newLine;
			mainPage += L"Infinite Ammo : D-Left + Y";
			mainPage += newLine;
			mainPage += L"Give $10K : D-Left + B";
			mainPage += newLine;
			mainPage += L"Clear Notoriety : D-Left + A";
			mainPage += newLine;
			mainPage += L"Infinite Sprint: D-Up + X";
			mainPage += newLine;
			mainPage += L"Tiny Player : D-Up + Y";
			mainPage += newLine;
			mainPage += L"Giant Player : D-Up + B";
			mainPage += newLine;
			mainPage += L"Super Beer Muscles : D-Up + A";
			mainPage += newLine;
			mainPage += L"Super Explosions : D-Right + X";
			mainPage += newLine;
			mainPage += L"Raining Peds : D-Right + Y";
			mainPage += newLine;
			mainPage += L"Elevator To Heaven : D-Right + B";
			mainPage += newLine;
			mainPage += L"Return Here : LB + RB";
			mainPage += newLine + newLine;
			mainPage += L"Author : XeCrippy";
			return mainPage.c_str();
		}
	}

	namespace pageTitles {

		const wchar_t* MainPageTitle = L"Solace 360 : Saints Row 2 TU1";
	}

	XINPUT_STATE state = { 0 };

	void MainPageUI() {

		const wchar_t* buttonLabels[] = { L"Continue" };
		xTools::Xam::ShowMessageBox(
			pageTitles::MainPageTitle,
			pages::MainPage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels)
		);
	}

	void _SR2::LoadPlugin() {

		MainPageUI();

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_SAINTSROW2) {

			bool hasToggled = false;

			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					MainPageUI();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::NeverDie();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::InfiniteAmmo();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::GiveMoney();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::RemoveNoteriety();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::InfiniteSprint();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::TinyPlayer();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::GiantPlayer();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::SuperBeerMuscles();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::SuperExplosions();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::RainingPeds();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::ElevatorToHeaven();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::BushwickBill();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(500);
		}
	}
}