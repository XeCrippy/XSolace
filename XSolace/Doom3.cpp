#include "stdafx.h"
#include "Doom3.h"

namespace Doom3 {

	namespace vars {
		
		bool fastRun = false;
		bool fastWalk = false;
		bool enemyHealth = false;
		bool infiniteAmmo = false;
		bool infiniteFlashlight = false;
		bool lowGravity = false;
		bool showFps = false;
		bool superJump = false;
		bool thirdPerson = false;
	}

	namespace gameFuncs {

		void(__fastcall* Cbuf_AppendText)(int ptr, const char* cmd) = reinterpret_cast<void(__fastcall*)(int ptr, const char* cmd)>(0x8212EA18);
	}

	namespace funcs {

		void __fastcall SendCommand(const char* cmd) {

			gameFuncs::Cbuf_AppendText(0x825C7138, cmd);
		}

		void net_allowCheats() {
			uint32_t ptr = 0x82598700;
			uint32_t currAddr = xTools::Memory::ReadUInt32(ptr) + 0x24;
			xTools::Memory::WriteUInt32(currAddr, 0x1);
		}

		bool com_showFPS() {

			if (!vars::showFps) {
				SendCommand("com_showFPS 1");
				xTools::Xam::XNotify("Show FPS : Enabled");
				vars::showFps = true;
			}
			else {
				SendCommand("com_showFPS 0");
				xTools::Xam::XNotify("Show FPS : Disabled");
				vars::showFps = false;
			}
			return vars::showFps;
		}

		bool FastRun() {
			if (!vars::fastRun) {
				SendCommand("pm_runspeed 500");
				xTools::Xam::XNotify("Fast Run : Enabled");
				vars::fastRun = true;
			}
			else {
				SendCommand("pm_runspeed 220");
				xTools::Xam::XNotify("Fast Run : Disabled");
				vars::fastRun = false;
			}
			return vars::fastRun;
		}

		bool FastWalk() {
			if (!vars::fastWalk) {
				SendCommand("pm_walkspeed 500");
				xTools::Xam::XNotify("Fast Walk : Enabled");
				vars::fastWalk = true;
			}
			else {
				SendCommand("pm_walkspeed 140");
				xTools::Xam::XNotify("Fast Walk : Disabled");
				vars::fastWalk = false;
			}
			return vars::fastWalk;
		}

		bool g_infiniteAmmo() {

			if (!vars::infiniteAmmo) {
				SendCommand("g_infiniteAmmo 1");
				xTools::Xam::XNotify("Infinite Ammo : Enabled");
				vars::infiniteAmmo = true;
			}
			else {
				SendCommand("g_infiniteAmmo 0");
				xTools::Xam::XNotify("Infinite Ammo : Disabled");
				vars::infiniteAmmo = false;
			}
			return vars::infiniteAmmo;
		}

		void GiveAll() {
			SendCommand("give all");
			xTools::Xam::XNotify("Gave all weapons");
		}

		bool InfiniteFlashlight() {
			if (!vars::infiniteFlashlight) {
				SendCommand("flashlight_batteryDrainTimeMS 0");
				xTools::Xam::XNotify("Infinite Flashlight : Enabled");
				vars::infiniteFlashlight = true;
			}
			else {
				SendCommand("flashlight_batteryDrainTimeMS 30000");
				xTools::Xam::XNotify("Infinite Flashlight : Disabled");
				vars::infiniteFlashlight = false;
			}
			return vars::infiniteFlashlight;
		}

		void KillAllMonsters() {
			SendCommand("killMonsters");
			xTools::Xam::XNotify("Killed all monsters");
		}

		bool LowGravity() {
			if (!vars::lowGravity) {
				SendCommand("g_gravity 100");
				xTools::Xam::XNotify("Low Gravity : Enabled");
				vars::lowGravity = true;
			}
			else {
				SendCommand("g_gravity 1066");
				xTools::Xam::XNotify("Low Gravity : Disabled");
				vars::lowGravity = false;
			}
			return vars::lowGravity;
		}

		bool pm_thirdPerson() {

			if (!vars::thirdPerson) {
				SendCommand("pm_thirdPerson 1");
				xTools::Xam::XNotify("Third Person : Enabled");
				vars::thirdPerson = true;
			}
			else {
				SendCommand("pm_thirdPerson 0");
				xTools::Xam::XNotify("Third Person : Disabled");
				vars::thirdPerson = false;
			}
			return vars::thirdPerson;
		}

		bool ShowEnemyHealth() {
			if (!vars::enemyHealth) {
				SendCommand("ai_showHealth 1");
				xTools::Xam::XNotify("Show Enemy Health : Enabled");
				vars::enemyHealth = true;
			}
			else {
				SendCommand("ai_showHealth 0");
				xTools::Xam::XNotify("Show Enemy Health : Disabled");
				vars::enemyHealth = false;
			}
			return vars::enemyHealth;
		}

		bool SuperJump() {
			if (!vars::superJump) {
				SendCommand("pm_jumpHeight 500");
				xTools::Xam::XNotify("Super Jump : Enabled");
				vars::superJump = true;
			}
			else {
				SendCommand("pm_jumpHeight 48");
				xTools::Xam::XNotify("Super Jump : Disabled");
				vars::superJump = false;
			}
			return vars::superJump;
		}

		void ToggleGodMode() {
			SendCommand("god");
			xTools::Xam::XNotify("Toggled God Mode");
		}

		void ToggleNoClip() {
			SendCommand("noclip");
			xTools::Xam::XNotify("Toggled No Clip");
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
			mainPage += L"Give All Guns : D_LEFT+Y";
			mainPage += newLine;
			mainPage += L"Show FPS : D_LEFT+B";
			mainPage += newLine;
			mainPage += L"Super Jump : D_UP+A";
			mainPage += newLine;
			mainPage += L"Fast Run : D_UP+X";
			mainPage += newLine;
			mainPage += L"Fast Walk : D_UP+Y";
			mainPage += newLine;
			mainPage += L"Low Gravity : D_UP+B";
			mainPage += newLine;
			mainPage += L"Kill All Monsters : D_RIGHT+A";
			mainPage += newLine;
			mainPage += L"Infinite Flashlight : D_RIGHT+X";
			mainPage += newLine;
			mainPage += L"Third Person : D_RIGHT+Y";
			mainPage += newLine;
			mainPage += L"No Clip : D_RIGHT+B";
			mainPage += newLine;
			mainPage += L"Console Commands : D_DOWN+X";
			mainPage += newLine;
			mainPage += L"Return Here : LB+RB";
			return mainPage.c_str();
		}
	}

	void ShowMainPageUI() {

		const wchar_t* buttonLabels[] = { L"Continue" };
		xTools::Xam::ShowMessageBox(
		    L"Doom 3 BFG",
			pages::MainPage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels)
		);
	}

	XINPUT_STATE state = { 0 };

	void ShowKeyboardUI()
	{
		DWORD hr = 0;
		HRESULT hre = 0;
		WCHAR r1[512];
		XOVERLAPPED kb_overlapped;

		ZeroMemory(&state, sizeof(XINPUT_STATE));

		XInputGetState(0, &state);

		hre = XShowKeyboardUI(0, VKBD_DEFAULT, L"god", L"Console Commands", L"Enter Console Command\r\nEx: g_fov 120\r\nEx: g_fov 120;com_showFPS 1", r1, 512, &kb_overlapped); // show keyboard ui

		while (!XHasOverlappedIoCompleted(&kb_overlapped)) Sleep(25);

		if (hre == ERROR_IO_PENDING)  hr = _wtoi(r1); // returns input keyboard result

		std::string cmd = std::_Narrow_str(r1);

		funcs::SendCommand(cmd.c_str());
	}

	void _Doom3::LoadPlugin() {

		funcs::net_allowCheats();
		ShowMainPageUI();

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_DOOM3BFG) {
			bool hasToggled = false;
			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					ShowMainPageUI();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::ToggleGodMode();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::g_infiniteAmmo();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::GiveAll();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::com_showFPS();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::SuperJump();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::FastRun();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::FastWalk();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::LowGravity();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::KillAllMonsters();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::InfiniteFlashlight();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::pm_thirdPerson();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::ToggleNoClip();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					ShowKeyboardUI();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(300);
		}
	}
}