#include "stdafx.h"
#include "SaintsRowGOH.h"

namespace SaintsRowGOH {

	namespace vars {
		bool bushwickBill = false;
		bool elevatorToHeaven = false;
		bool fastForward = false;
		bool giantPlayer = false;
		bool goldenGun = false;
		bool hellPeds = false;
		bool hideHud = false;
		bool infiniteSprint = false;
		bool lowGravity = false;
		bool mascotPeds = false;
		bool neverDie = false;
		bool slowMo = false;
		bool superBeerMuscles = false;
		bool superExplosions = false;
		bool superSaints = false;
		bool tinyPlayer = false;
		bool unlimitedClip = false;

		uint32_t playerSize1 = 0x83E6DF98;
		uint32_t playerSize2 = 0x83E6DF9C;
	}

	namespace gameFuncs {
		void(*BushwickBill_On)() = reinterpret_cast<void(*)()>(0x82551EF8);
		void(*BushwickBill_Off)() = reinterpret_cast<void(*)()>(0x82553338);
		void(*ElevatorToHeaven_On)() = reinterpret_cast<void(*)()>(0x825529D8);
		void(*ElevatorToHeaven_Off)() = reinterpret_cast<void(*)()>(0x82553A18);
		void(*FastForward_On)() = reinterpret_cast<void(*)()>(0x82552C08);
		void(*FastForward_Off)() = reinterpret_cast<void(*)()>(0x82552C28);
		void(*GoldenGun_On)() = reinterpret_cast<void(*)()>(0x82551C20);
		void(*GoldenGun_Off)() = reinterpret_cast<void(*)()>(0x82551C38);
		unsigned int(*HellPeds_On)() = reinterpret_cast<unsigned int(*)()>(0x82552B60);
		void(*HellPeds_Off)() = reinterpret_cast<void(*)()>(0x82552AC0);
		int(*HideHUD_On)() = reinterpret_cast<int(*)()>(0x825529F0);
		void(*HideHUD_Off)() = reinterpret_cast<void(*)()>(0x82552E38);
		void(*InfiniteSprint_On)() = reinterpret_cast<void(*)()>(0x82551BD8);
		void(*InfiniteSprint_Off)() = reinterpret_cast<void(*)()>(0x82553250);
		int(*InstantCash)() = reinterpret_cast<int(*)()>(0x82551868);
		int(*InstantRespect)() = reinterpret_cast<int(*)()>(0x825518B0);
		int(*LowGravity_On)() = reinterpret_cast<int(*)()>(0x82552948);
		int(*LowGravity_Off)() = reinterpret_cast<int(*)()>(0x82553988);
		unsigned int(*MascotPeds_On)() = reinterpret_cast<unsigned int(*)()>(0x82552A38);
		void(*MascotPeds_Off)() = reinterpret_cast<void(*)()>(0x82552AC0);
		int(*NeverDie_On)() = reinterpret_cast<int(*)()>(0x82552810);
		int(*NeverDie_Off)() = reinterpret_cast<int(*)()>(0x82553820);
		void(*SlowMo_On)() = reinterpret_cast<void(*)()>(0x82552BE8);
		void(*SlowMo_Off)() = reinterpret_cast<void(*)()>(0x82552C28);
		void(*SuperBeerMuscles_On)() = reinterpret_cast<void(*)()>(0x82551CA8);
		void(*SuperBeerMuscles_Off)() = reinterpret_cast<void(*)()>(0x82553280);
		void(*SuperExplosions_On)() = reinterpret_cast<void(*)()>(0x82552928);
		void(*SuperExplosions_Off)() = reinterpret_cast<void(*)()>(0x82553970);
		int(*SuperSaints_On)() = reinterpret_cast<int(*)()>(0x82552820);
		void(*SuperSaints_Off)() = reinterpret_cast<void(*)()>(0x82553830);
		void(*UnlimitedClip_On)() = reinterpret_cast<void(*)()>(0x82552910);
		void(*UnlimitedClip_Off)() = reinterpret_cast<void(*)()>(0x82553958);
	}

	namespace funcs {

		bool BushwickBill() {
			if (!vars::bushwickBill) {
				gameFuncs::BushwickBill_On();
				xTools::Xam::XNotify("Bushwick Bill : Enabled");
				vars::bushwickBill = true;
			}
			else {
				gameFuncs::BushwickBill_Off();
				xTools::Xam::XNotify("Bushwick Bill : Disabled");
				vars::bushwickBill = false;
			}
			return vars::bushwickBill;
		}

		bool ElevatorToHeaven() {
			if (!vars::elevatorToHeaven) {
				gameFuncs::ElevatorToHeaven_On();
				xTools::Xam::XNotify("Elevator To Heaven : Enabled");
				vars::elevatorToHeaven = true;
			}
			else {
				gameFuncs::ElevatorToHeaven_Off();
				xTools::Xam::XNotify("Elevator To Heaven : Disabled");
				vars::elevatorToHeaven = false;
			}
			return vars::elevatorToHeaven;
		}

		bool FastForward() {
			if (!vars::fastForward) {
				gameFuncs::FastForward_On();
				xTools::Xam::XNotify("Fast Forward : Enabled");
				vars::fastForward = true;
			}
			else {
				gameFuncs::FastForward_Off();
				xTools::Xam::XNotify("Fast Forward : Disabled");
				vars::fastForward = false;
			}
			return vars::fastForward;
		}

		bool GiantPlayer() {
			if (!vars::giantPlayer) {
				xTools::Memory::Write(vars::playerSize1, (float)1.189207);
				xTools::Memory::Write(vars::playerSize2, (float)1.189207);
				xTools::Xam::XNotify("Giant Player : Enabled");
				vars::giantPlayer = true;
			}
			else {
				xTools::Memory::Write(vars::playerSize1, (float)0.0);
				xTools::Memory::Write(vars::playerSize2, (float)0.0);
				xTools::Xam::XNotify("Giant Player : Disabled");
				vars::giantPlayer = false;
			}
			return vars::giantPlayer;
		}

		bool GoldenGun() {
			if (!vars::goldenGun) {
				gameFuncs::GoldenGun_On();
				xTools::Xam::XNotify("Golden Gun : Enabled");
				vars::goldenGun = true;
			}
			else {
				gameFuncs::GoldenGun_Off();
				xTools::Xam::XNotify("Golden Gun : Disabled");
				vars::goldenGun = false;
			}
			return vars::goldenGun;
		}

		bool HellPeds() {
			if (!vars::hellPeds) {
				gameFuncs::HellPeds_On();
				xTools::Xam::XNotify("Hell Pedestrians : Enabled");
				vars::hellPeds = true;
			}
			else {
				gameFuncs::HellPeds_Off();
				xTools::Xam::XNotify("Hell Pedestrians : Disabled");
				vars::hellPeds = false;
			}
			return vars::hellPeds;
		}

		bool HideHUD() {
			if (!vars::hideHud) {
				gameFuncs::HideHUD_On();
				xTools::Xam::XNotify("Hide HUD : Enabled");
				vars::hideHud = true;
			}
			else {
				gameFuncs::HideHUD_Off();
				xTools::Xam::XNotify("Hide HUD : Disabled");
				vars::hideHud = false;
			}
			return vars::hideHud;
		}

		bool InfiniteSprint() {
			if (!vars::infiniteSprint) {
				gameFuncs::InfiniteSprint_On();
				xTools::Xam::XNotify("Infinite Sprint : Enabled");
				vars::infiniteSprint = true;
			}
			else {
				gameFuncs::InfiniteSprint_Off();
				xTools::Xam::XNotify("Infinite Sprint : Disabled");
				vars::infiniteSprint = false;
			}
			return vars::infiniteSprint;
		}

		void _InstantCash() {
			gameFuncs::InstantCash();
			xTools::Xam::XNotify("Gave Player $100,000");
		}

		void _InstantRespect() {
			gameFuncs::InstantRespect();
			xTools::Xam::XNotify("Gave Player 100,000 Respect");
		}

		bool LowGravity() {
			if (!vars::lowGravity) {
				gameFuncs::LowGravity_On();
				xTools::Xam::XNotify("Low Gravity : Enabled");
				vars::lowGravity = true;
			}
			else {
				gameFuncs::LowGravity_Off();
				xTools::Xam::XNotify("Low Gravity : Disabled");
				vars::lowGravity = false;
			}
			return vars::lowGravity;
		}

		bool MascotPeds() {
			if (!vars::mascotPeds) {
				gameFuncs::MascotPeds_On();
				xTools::Xam::XNotify("Mascot Pedestrians : Enabled");
				vars::mascotPeds = true;
			}
			else {
				gameFuncs::MascotPeds_Off();
				xTools::Xam::XNotify("Mascot Pedestrians : Disabled");
				vars::mascotPeds = false;
			}
			return vars::mascotPeds;
		}

		bool NeverDie() {
			if (!vars::neverDie) {
				gameFuncs::NeverDie_On();
				xTools::Xam::XNotify("Never Die : Enabled");
				vars::neverDie = true;
			}
			else {
				gameFuncs::NeverDie_Off();
				xTools::Xam::XNotify("Never Die : Disabled");
				vars::neverDie = false;
			}
			return vars::neverDie;
		}

		bool SlowMo() {
			if (!vars::slowMo) {
				gameFuncs::SlowMo_On();
				xTools::Xam::XNotify("Slow Mo : Enabled");
				vars::slowMo = true;
			}
			else {
				gameFuncs::SlowMo_Off();
				xTools::Xam::XNotify("Slow Mo : Disabled");
				vars::slowMo = false;
			}
			return vars::slowMo;
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

		bool SuperExplosions() {
			if (!vars::superExplosions) {
				gameFuncs::SuperExplosions_On();
				xTools::Xam::XNotify("Super Explosions : Enabled");
				vars::superExplosions = true;
			}
			else {
				gameFuncs::SuperBeerMuscles_Off();
				xTools::Xam::XNotify("Super Explosions : Disabled");
				vars::superExplosions = false;
			}
			return vars::superExplosions;
		}

		bool SuperSaints() {
			if (!vars::superSaints) {
				gameFuncs::SuperSaints_On();
				xTools::Xam::XNotify("Super Saints : Enabled");
				vars::superSaints = true;
			}
			else {
				gameFuncs::SuperSaints_Off();
				xTools::Xam::XNotify("Super Saints : Disabled");
				vars::superSaints = false;
			}
			return vars::superSaints;
		}

		bool TinyPlayer() {
			if (!vars::tinyPlayer) {
				xTools::Memory::Write(vars::playerSize1, (float)0.84089601);
				xTools::Memory::Write(vars::playerSize2, (float)0.84089601);
				xTools::Xam::XNotify("Tiny Player : Enabled");
				vars::tinyPlayer = true;
			}
			else {
				xTools::Memory::Write(vars::playerSize1, (float)0.0);
				xTools::Memory::Write(vars::playerSize2, (float)0.0);
				xTools::Xam::XNotify("Tiny Player : Disabled");
				vars::tinyPlayer = false;
			}
			return vars::tinyPlayer;
		}

		bool UnlimitedClip() {
			if (!vars::unlimitedClip) {
				gameFuncs::UnlimitedClip_On();
				xTools::Xam::XNotify("Unlimited Clip : Enabled");
				vars::unlimitedClip = true;
			}
			else {
				gameFuncs::UnlimitedClip_Off();
				xTools::Xam::XNotify("Unlimited Clip : Disabled");
				vars::unlimitedClip = false;
			}
			return vars::unlimitedClip;
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
			mainPage += L"Tiny Player : D_UP+X";
			mainPage += newLine;
			mainPage += L"Giant Player : D_UP+Y";
			mainPage += newLine;
			mainPage += L"Bushwick Bill : D_UP+B";
			mainPage += newLine;
			mainPage += L"Golden Gun : D_RIGHT+A";
			mainPage += newLine;
			mainPage += L"Low Gravity : D_RIGHT+X";
			mainPage += newLine;
			mainPage += L"Mascot Peds : D_RIGHT+Y";
			mainPage += newLine;
			mainPage += L"Super Saints : D_RIGHT+B";
			return mainPage.c_str();
		}
	}

	namespace pageTitles {
		const wchar_t* mainTitle = L"Saints Row Gat Outta Hell";
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

	void SRGatOuttaHell::LoadPlugin() {
		XINPUT_STATE state = { 0 };
		ShowMainPageUI();

		while(xTools::Xam::GetCurrentTitleId() == xTools::GAME_SAINTSROWGOH) {
			bool hasToggled = false;
			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					ShowMainPageUI();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::NeverDie();
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

					funcs::_InstantCash();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::_InstantRespect();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::TinyPlayer();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::GiantPlayer();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::BushwickBill();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::GoldenGun();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::LowGravity();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::MascotPeds();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::SuperSaints();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(300);
		}
	}
}