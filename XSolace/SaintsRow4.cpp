#include "stdafx.h"
#include "SaintsRow4.h"

namespace SaintsRow4 {

	namespace vars {
		bool bigHeadMode = false;
		bool bloodyMess = false;
		bool bushwickBill = false;
		bool disableWardenNoteriety = false;
		bool elevatorToHeaven = false;
		bool fastForward = false;
		bool giantPlayer = false;
		bool goldenGun = false;
		bool hideHud = false;
		bool infiniteSprint = false;
		bool lowGravity = false;
		bool mascotPeds = false;
		bool neverDie = false;
		bool noGlitchCity = false;
		bool pimpsNhoesPeds = false;
		bool rainingPeds = false;
		bool slowMo = false;
		bool superBeerMuscles = false;
		bool superExplosions = false;
		bool superSaints = false;
		bool tinyPlayer = false;
		bool unlimitedClip = false;

		uint32_t playerSize1 = 0x83D6BF60;
		uint32_t playerSize2 = 0x83D6BF64;
	}

	namespace gameFuncs {
		int(*AddPoliceNoteriety_)() = reinterpret_cast<int(*)()>(0x824CD110);
		void(*BigHeadMode_On)() = reinterpret_cast<void(*)()>(0x824CE230);
		void(*BigHeadMode_Off)() = reinterpret_cast<void(*)()>(0x824CE240);
		void(*BloodyMess_On)() = reinterpret_cast<void(*)()>(0x824CDF98);
		void(*BloodyMess_Off)() = reinterpret_cast<void(*)()>(0x824CDFB0);
		int(*BushwickBill_On)() = reinterpret_cast<int(*)()>(0x824CD488);
		void(*BushwickBill_Off)() = reinterpret_cast<void(*)()>(0x824CE860);
		void(*DisableWardenNoteriety_On)() = reinterpret_cast<void(*)()>(0x824CE1C8);
		void(*DisableWardenNoteriety_Off)() = reinterpret_cast<void(*)() > (0x824CE1D8);
		void(*ElevatorToHeaven_On)() = reinterpret_cast<void(*)()>(0x824CDF68);
		void(*ElevatorToHeaven_Off)() = reinterpret_cast<void(*)()>(0x824CEF40);
		void(*FastForward_On)() = reinterpret_cast<void(*)()>(0x824CE110);
		void(*FastForward_Off)() = reinterpret_cast<void(*)()>(0x824CE130);
		void(*GoldenGun_On)() = reinterpret_cast<void(*)()>(0x824CD210);
		void(*GoldenGun_Off)() = reinterpret_cast<void(*)()>(0x824CD228);
		int(*HideHud_On)() = reinterpret_cast<int(*)()>(0x824CDF80);
		void(*HideHud_Off)() = reinterpret_cast<void(*)()>(0x824CE360);
		void(*InfiniteSprint_On)() = reinterpret_cast<void(*)()>(0x824CD1C8);
		void(*InfiniteSprint_Off)() = reinterpret_cast<void(*)()>(0x824CE778);
		int(*InstantCash_)() = reinterpret_cast<int(*)()>(0x824CD0B0);
		int(*InstantRespect_)() = reinterpret_cast<int(*)()>(0x824CD0F8);
		int(*LowGravity_On)() = reinterpret_cast<int(*)()>(0x824CDED8);
		int(*LowGravity_Off)() = reinterpret_cast<int(*)()>(0x824CEEB0);
		unsigned int(*MascotPeds_On)() = reinterpret_cast<unsigned int(*)()>(0x824CDFC8);
		void(*MascotPeds_Off)() = reinterpret_cast<void(*)()>(0x824CE0D8);
		int(*NeverDie_On)() = reinterpret_cast<int(*)()>(0x824CDDA0);
		int(*NeverDie_Off)() = reinterpret_cast<int(*)()>(0x824CED48);
		void(*NoGlitchCity_On)() = reinterpret_cast<void(*)()>(0x824CE200);
		void(*NoGlitchCity_Off)() = reinterpret_cast<void(*)()>(0x824CE218);
		unsigned int(*PimpsNHoesPeds_On)() = reinterpret_cast<unsigned int(*)()>(0x824CE050);
		void(*PimpsNHoesPeds_Off)() = reinterpret_cast<void(*)()>(0x824CE0D8);
		void(*RainingPeds_On)() = reinterpret_cast<void(*)()>(0x824CDB58);
		void(*RainingPeds_Off)() = reinterpret_cast<void(*)()>(0x824CEBF8);
		int(*RemovePoliceNoteriety_)() = reinterpret_cast<int(*)()>(0x824CD158);
		void(*SlowMo_On)() = reinterpret_cast<void(*)()>(0x824CE0F0);
		void(*SlowMo_Off)() = reinterpret_cast<void(*)()>(0x824CE130);
		void(*SuperBeerMuscles_On)() = reinterpret_cast<void(*)()>(0x824CD298);
		void(*SuperBeerMuscles_Off)() = reinterpret_cast<void(*)()>(0x824CE7A8);
		void(*SuperExplosions_On)() = reinterpret_cast<void(*)()>(0x824CDEB8);
		void(*SuperExplosions_Off)() = reinterpret_cast<void(*)()>(0x824CEE98);
		int(*SuperSaints_On)() = reinterpret_cast<int(*)()>(0x824CDDB0);
		void(*SuperSaints_Off)() = reinterpret_cast<void(*)()>(0x824CED58);
		void(*UnlimitedClip_On)() = reinterpret_cast<void(*)()>(0x824CDEA0);
		void(*UnlimitedClip_Off)() = reinterpret_cast<void(*)()>(0x824CEE80);
	}

	namespace funcs {

		void AddPoliceNoteriety() {
			gameFuncs::AddPoliceNoteriety_();
			xTools::Xam::XNotify("Added Police Noteriety");
		}

		bool BigHeadMode() {
			if (!vars::bigHeadMode) {
				gameFuncs::BigHeadMode_On();
				xTools::Xam::XNotify("Big Head Mode : Enabled");
				vars::bigHeadMode = true;
			}
			else {
				gameFuncs::BigHeadMode_Off();
				xTools::Xam::XNotify("Big Head Mode : Disabled");
				vars::bigHeadMode = false;
			}
			return vars::bigHeadMode;
		}

		bool BloodyMess() {
			if (!vars::bloodyMess) {
				gameFuncs::BloodyMess_On();
				xTools::Xam::XNotify("Bloody Mess : Enabled");
				vars::bloodyMess = true;
			}
			else {
				gameFuncs::BloodyMess_Off();
				xTools::Xam::XNotify("Bloody Mess : Disabled");
				vars::bloodyMess = false;
			}
			return vars::bloodyMess;
		}

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

		bool DisabledWardenNoteriety() {
			if (!vars::disableWardenNoteriety) {
				gameFuncs::DisableWardenNoteriety_On();
				xTools::Xam::XNotify("Disable Warden Noteriety : Enabled");
				vars::disableWardenNoteriety = true;
			}
			else {
				gameFuncs::DisableWardenNoteriety_Off();
				xTools::Xam::XNotify("Disable Warden Noteriety : Disabled");
				vars::disableWardenNoteriety = false;
			}
			return vars::disableWardenNoteriety;
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
				xTools::Memory::WriteFloat(vars::playerSize1, 2.0f);
				xTools::Memory::WriteFloat(vars::playerSize2, 2.0f);
				xTools::Xam::XNotify("Giant Player : Enabled");
				vars::giantPlayer = true;
			}
			else {
				xTools::Memory::WriteFloat(vars::playerSize1, 0.0f);
				xTools::Memory::WriteFloat(vars::playerSize2, 0.0f);
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

		bool HideHUD() {
			if (!vars::hideHud) {
				gameFuncs::HideHud_On();
				xTools::Xam::XNotify("Hide HUD : Enabled");
				vars::hideHud = true;
			}
			else {
				gameFuncs::HideHud_Off();
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

		void InstantCash() {
			gameFuncs::InstantCash_();
			xTools::Xam::XNotify("Gave Player $100,000");
		}

		void InstantRespect() {
			gameFuncs::InstantRespect_();
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

		bool NoGlitchCity() {
			if (!vars::noGlitchCity) {
				gameFuncs::NoGlitchCity_On();
				xTools::Xam::XNotify("No Glitch City : Enabled");
				vars::noGlitchCity = true;
			}
			else {
				gameFuncs::NoGlitchCity_Off();
				xTools::Xam::XNotify("No Glitch City : Disabled");
				vars::noGlitchCity = false;
			}
			return vars::noGlitchCity;
		}

		bool PimpsNHoesPeds() {
			if (!vars::pimpsNhoesPeds) {
				gameFuncs::PimpsNHoesPeds_On();
				xTools::Xam::XNotify("Pimps N Hoes Pedestrians : Enabled");
				vars::pimpsNhoesPeds = true;
			}
			else {
				gameFuncs::PimpsNHoesPeds_Off();
				xTools::Xam::XNotify("Pimps N Hoes Pedestrians : Disabled");
				vars::pimpsNhoesPeds = false;
			}
			return vars::pimpsNhoesPeds;
		}

		bool RainingPeds() {
			if (!vars::rainingPeds) {
				gameFuncs::RainingPeds_On();
				xTools::Xam::XNotify("Raining Peds : Enabled");
				vars::rainingPeds = true;
			}
			else {
				gameFuncs::RainingPeds_Off();
				xTools::Xam::XNotify("Raining Peds : Disabled");
				vars::rainingPeds = false;
			}
			return vars::rainingPeds;
		}

		void RemovePoliceNoteriety() {
			gameFuncs::RemovePoliceNoteriety_();
			xTools::Xam::XNotify("Removed Police Noteriety");
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
				gameFuncs::SuperExplosions_Off();
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
				xTools::Memory::WriteFloat(vars::playerSize1, 0.5f);
				xTools::Memory::WriteFloat(vars::playerSize2, 0.5f);
				xTools::Xam::XNotify("Tiny Player : Enabled");
				vars::tinyPlayer = true;
			}
			else {
				xTools::Memory::WriteFloat(vars::playerSize1, 0.0f);
				xTools::Memory::WriteFloat(vars::playerSize2, 0.0f);
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
			mainPage += L"Never Die : D_LEFT+A";
			mainPage += newLine;
			mainPage += L"Unlimited Clip : D_LEFT+X";
			mainPage += newLine;
			mainPage += L"Infinite Sprint : D_LEFT+Y";
			mainPage += newLine;
			mainPage += L"Low Gravity : D_LEFT+B";
			mainPage += newLine;
			mainPage += L"Instant Cash : D_UP+A";
			mainPage += newLine;
			mainPage += L"Instant Respect : D_UP+X";
			mainPage += newLine;
			mainPage += L"Golden Gun : D_UP+Y";
			mainPage += newLine;
			mainPage += L"Elevator To Heaven : D_UP+B";
			mainPage += newLine;
			mainPage += L"Super Beer Muscles : D_RIGHT+A";
			mainPage += newLine;
			mainPage += L"Super Exlosions : D_RIGHT+X";
			mainPage += newLine;
			mainPage += L"Super Saints : D_RIGHT+Y";
			mainPage += newLine;
			mainPage += L"Remove Police Noteriety : D_RIGHT+B";
			mainPage += newLine + newLine;
			mainPage += L"Return Here : LB+RB";
			return mainPage.c_str();
		}

		const wchar_t* Page2() {
			std::wstring newLine = L"\r\n";
			std::wstring page2;
			page2 += L"Big Head Mode : D_DOWN+A";
			page2 += newLine;
			page2 += L"Slow Mo : D_DOWN+X";
			page2 += newLine;
			page2 += L"Fast Forward : D_DOWN+Y";
			page2 += newLine;
			page2 += L"Bloody Mess : D_DOWN+B";
			page2 += newLine;
			page2 += L"Tiny Player : LB+A";
			page2 += newLine;
			page2 += L"Giant Player : LB+X";
			page2 += newLine;
			page2 += L"Bushwick Bill : LB+Y";
			page2 += newLine;
			page2 += L"Pimps N Hoes Peds : LB+B";
			page2 += newLine;
			page2 += L"Return Here : LB+RB";
			page2 += newLine + newLine;
			page2 += L"Author : XeCrippy";
			return page2.c_str();
		}
	}

	void _SaintsRow4::ShowMainPageUI() {
		const wchar_t* buttonLabels[] = { L"Next", L"Close"};
		const wchar_t* mainTitle = L"Saints Row IV TU7";
		uint32_t buttonPressedIndex = 0;
		uint32_t result = xTools::Xam::ShowMessageBox(
			mainTitle,
			pages::MainPage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels),
			&buttonPressedIndex
		);

		if (result == ERROR_SUCCESS) {

			switch (buttonPressedIndex) {
			case 0:
				_SaintsRow4::ShowPage2UI();
				break;
			case 1:
				break;
			default:
				break;
			}
		}
	}

	void _SaintsRow4::ShowPage2UI() {
		const wchar_t* buttonLabels[] = { L"Back", L"Close" };
		const wchar_t* mainTitle = L"Saints Row IV TU7";
		uint32_t buttonPressedIndex = 0;
		uint32_t result = xTools::Xam::ShowMessageBox(
			mainTitle,
			pages::Page2(),
			buttonLabels,
			ARRAYSIZE(buttonLabels),
			&buttonPressedIndex
		);

		if (result == ERROR_SUCCESS) {

			switch (buttonPressedIndex) {
			case 0:
				_SaintsRow4::ShowMainPageUI();
				break;
			case 1:
				break;
			default:
				break;
			}
		}
	}

	void _SaintsRow4::LoadPlugin() {

		XINPUT_STATE state = { 0 };
		ShowMainPageUI();

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_SAINTSROW4) {
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

					funcs::LowGravity();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::InstantCash();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::InstantRespect();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::GoldenGun();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::ElevatorToHeaven();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::SuperBeerMuscles();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::SuperExplosions();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::SuperSaints();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::RemovePoliceNoteriety();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::BigHeadMode();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::SlowMo();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::FastForward();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::BloodyMess();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::TinyPlayer();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::GiantPlayer();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::BushwickBill();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::PimpsNHoesPeds();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(300);
		 }
	}
}