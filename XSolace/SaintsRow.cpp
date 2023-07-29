#include "stdafx.h"
#include "SaintsRow.h"

namespace SaintsRow {

	namespace vars {

		bool clearWeather = false;
		bool godMode = false;
		bool infiniteAmmo = false;
		bool infiniteSpint = false;
		bool rainyWeather = false;
		bool showFps = false;
		bool showMemUsage = false;
		bool superbeermuscles = false;

		uint32_t health = 0x83A77498; // default 1000.0
		uint32_t maxHealth = 0x83A77494; // default 1000.0 // set to 0 for godmode
		uint32_t money = 0x83A77630;
		uint32_t noReload = 0x82487850;
		uint32_t stamina = 0x82B4EB30;

		uint32_t noReload_off = 0x396BFFFF;
		uint32_t noReload_on = 0x396B0000;
	}

	namespace gameFuncs {

		int(__fastcall* ConsoleCmds)(const char* cmd) = reinterpret_cast<int(__fastcall*)(const char* cmd)>(0x8263CB10);
		void(*SuperBeerMuscles_OFF)() = reinterpret_cast<void(*)()>(0x822060C0);
		void(*SuperBeerMuscles_ON)() = reinterpret_cast<void(*)()>(0x82205B30);
	}

	namespace funcs {

		void SendCommand(const char* cmd) {

			gameFuncs::ConsoleCmds(cmd);
		}

		void ClearNotoriety() {

			SendCommand("set_notoriety_gang 0");
			SendCommand("set_notoriety_police 0");
			xTools::Xam::XNotify("Cleared gang and police noteriety");
		}

		void ClearWeather() {

			SendCommand("weather_set_stage 1");
			xTools::Xam::XNotify("Set weather to clear");
		}

		void GiveAllWeapons() {

			SendCommand("give_player_n_weapons 7");
			xTools::Xam::XNotify("Gave player all weapons");
		}

		void Give10kMoney() {
			uint32_t current = xTools::ReadUInt32(vars::money);
			xTools::WriteUInt32(vars::money, current + 1000000u);
			xTools::Xam::XNotify("Gave player $10,000");
		}

		bool GodMode() {

			if (!vars::godMode) {
				xTools::WriteUInt32(vars::maxHealth, 1);
				xTools::WriteFloat(vars::health, 999999.0f);
				xTools::Xam::XNotify("God Mode : Enabled");
				vars::godMode = true;
			}
			else {
				xTools::WriteUInt32(vars::maxHealth, 1000u);
				xTools::WriteFloat(vars::health, 1000.0f);
				xTools::Xam::XNotify("God Mode : Disabled");
				vars::godMode = false;
			}
			return vars::godMode;
		}

		bool InfiniteAmmo() {

			if (!vars::infiniteAmmo) {
				SendCommand("ammo 1");
				xTools::WriteUInt32(vars::noReload, vars::noReload_on);
				xTools::Xam::XNotify("Infinite Ammo : Enabled");
				vars::infiniteAmmo = true;
			}
			else {
				SendCommand("ammo 0");
				xTools::WriteUInt32(vars::noReload, vars::noReload_off);
				xTools::Xam::XNotify("Infinite Ammo : Disabled");
				vars::infiniteAmmo = false;
			}
			return vars::infiniteAmmo;
		}

		bool InfiniteSprint() {

			if (!vars::infiniteSpint) {
				xTools::WriteUInt8(vars::stamina, 0x2);
				xTools::Xam::XNotify("Infinite Sprint : Enabled");
				vars::infiniteSpint = true;
			}
			else {
				xTools::WriteUInt8(vars::stamina, 0x0);
				xTools::Xam::XNotify("Infinite Sprint : Disabled");
				vars::infiniteSpint = false;
			}
			return vars::infiniteSpint;
		}

		void RainyWeather() {

			SendCommand("weather_set_stage 4");
			xTools::Xam::XNotify("Set weather to rainy");
		}

		bool ShowFps() {

			if (!vars::showFps) {
				SendCommand("show_fps 1");
				xTools::Xam::XNotify("Show FPS : Enabled");
				vars::showFps = true;
			}
			else {
				SendCommand("show_fps 0");
				xTools::Xam::XNotify("Show FPS : Disabled");
				vars::showFps = false;
			}
			return vars::showFps;
		}

		bool ShowMemUsage() {

			if (!vars::showMemUsage) {
				SendCommand("show_mem_usage 1");
				xTools::Xam::XNotify("Show Memory Usage : Enabled");
				vars::showMemUsage = true;
			}
			else {
				SendCommand("show_mem_usage 0");
				xTools::Xam::XNotify("Show Memory Usage : Disabled");
				vars::showMemUsage = false;
			}
			return vars::showMemUsage;
		}

		void SBM_ON() {
			gameFuncs::SuperBeerMuscles_ON();
			xTools::Xam::XNotify("Super Beer Muscles : Enabled");
		}

		void SBM_OFF() {
			gameFuncs::SuperBeerMuscles_OFF();
			xTools::Xam::XNotify("Super Beer Muscles : Disabled");
		}

		bool SuperBeerMuscles() {

			if (!vars::superbeermuscles) {
				SBM_ON();
				vars::superbeermuscles = true;
			}
			else {
				SBM_OFF();
				vars::superbeermuscles = false;
			}
			return vars::superbeermuscles;
		}

		void UnlockAllCheats() {

			SendCommand("cheats_unlock_all");
			xTools::Xam::XNotify("Unlocked all cheats");
		}

		void UnlockAllMusic() {

			SendCommand("music_store_unlock_all");
			xTools::Xam::XNotify("Unlocked all music");
		}
	}

	XINPUT_STATE state = { 0 };

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
			mainPage += L"Show FPS : D-Up + X";
			mainPage += newLine;
			mainPage += L"Show Memory : D-Up + Y";
			mainPage += newLine;
			mainPage += L"Clear Weather : D-Up + B";
			mainPage += newLine;
			mainPage += L"Infinite Sprint : D-Up + A";
			mainPage += newLine;
			mainPage += L"Unlock All Music : D-Right + X";
			mainPage += newLine;
			mainPage += L"Unlock All Cheats : D-Right + Y";
			mainPage += newLine;
			mainPage += L"Super Beer Muscles : D-Right + B";
			mainPage += newLine + newLine;
			mainPage += L"Return Here : LB + RB";
			mainPage += newLine;
			mainPage += L"Console Commands : LB + B";
			return mainPage.c_str();
		}

		const wchar_t* KeyboardPage() {

			std::wstring keyboardPage;
			std::wstring newLine = L"\r\n";
			keyboardPage += L"Enter custom console commands";
			keyboardPage += newLine;
			keyboardPage += L"Example : ammo 1";
			return keyboardPage.c_str();
		}
	}

	namespace pageTitles {

		const wchar_t* ConsoleCmdsPageTitle = L"Send Custom Commands";
		const wchar_t* MainPageTitle = L"Solace 360 : Saints Row TU1";
	}

	void MainPageUI() {

		const wchar_t* buttonLabels[] = { L"Continue" };
		xTools::Xam::ShowMessageBox(
			pageTitles::MainPageTitle,
			pages::MainPage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels)
		);
	}

	void ShowKeyboardUI()
	{
		DWORD hr = 0;
		HRESULT hre = 0;
		WCHAR r1[512];
		XOVERLAPPED kb_overlapped;

		ZeroMemory(&state, sizeof(XINPUT_STATE));

		XInputGetState(0, &state);

		hre = XShowKeyboardUI(0, VKBD_DEFAULT, L"ammo 1", pageTitles::ConsoleCmdsPageTitle, pages::KeyboardPage(), r1, 512, &kb_overlapped); // show keyboard ui

		while (!XHasOverlappedIoCompleted(&kb_overlapped)) Sleep(25);

		if (hre == ERROR_IO_PENDING)  hr = _wtoi(r1); // returns input keyboard result

		std::string cmd = std::_Narrow_str(r1);

		funcs::SendCommand(cmd.c_str());
	}

	void _SaintsRow::LoadPlugin() {

		MainPageUI();

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_SAINTSROW) {

			bool hasToggled = false;
			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					MainPageUI();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					ShowKeyboardUI();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::GodMode();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::InfiniteAmmo();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::Give10kMoney();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::ClearNotoriety();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::ShowFps();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::ShowMemUsage();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::InfiniteSprint();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::UnlockAllMusic();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::UnlockAllCheats();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::SuperBeerMuscles();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(500);
		}
	}
}