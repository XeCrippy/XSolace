#include "stdafx.h"
#include "EnemyTerritory.h"

namespace EnemyTerritory {

	namespace vars {

		bool fov = false;
		bool infAmmo = false;
		bool showFps = false;
		bool slipperyFloors = false;
		bool superJump = false;
		bool superSpeed = false;
		bool thirdPerson = false;

		uint32_t ammo = 0x823FD324;
		uint32_t ammo_off = 0x7CCB512E;
		uint32_t ammo_on = 0x60000000;
		uint32_t ptr = 0x834F4F6C;
	}

	namespace gameFuncs {

		void(__fastcall* Cbuf_AppendText)(int ptr, const char* cmd) = reinterpret_cast<void(__fastcall*)(int ptr, const char* cmd)>(0x821DED58);
	}

	namespace funcs {

		void __fastcall SendCommand(const char* cmd) {

			gameFuncs::Cbuf_AppendText(vars::ptr, cmd);
		}

		void ToggleGodMode() {
			SendCommand("god");
			xTools::Xam::PulseController();
		}

		void ToggleNoclip() {
			SendCommand("noclip");
			xTools::Xam::PulseController();
		}

		void ToggleNoTarget() {
			SendCommand("notarget");
			xTools::Xam::PulseController();
		}

		bool InfiniteAmmo() {
			if (!vars::infAmmo) {
				xTools::Memory::WriteUInt32(vars::ammo, vars::ammo_on);
				xTools::Xam::PulseController();
				vars::infAmmo = true;
			}
			else {
				xTools::Memory::WriteUInt32(vars::ammo, vars::ammo_off);
				xTools::Xam::PulseController();
				vars::infAmmo = false;
			}
			return vars::infAmmo;
		}

		bool ToggleFOV() {
			if (!vars::fov) {
				SendCommand("g_fov 120");
				xTools::Xam::PulseController();
				vars::fov = true;
			}
			else {
				SendCommand("g_fov 90");
				xTools::Xam::PulseController();
				vars::fov = false;
			}
			return vars::fov;
		}

		bool ToggleShowFPS() {
			if (!vars::showFps) {
				SendCommand("com_showfps 1");
				xTools::Xam::PulseController();
				vars::showFps = true;
			}
			else {
				SendCommand("com_showfps 0");
				xTools::Xam::PulseController();
				vars::showFps = false;
			}
			return vars::showFps;
		}

		bool ToggleSlipperyFloors() {
			if (!vars::slipperyFloors) {
				SendCommand("pm_friction 1");
				xTools::Xam::PulseController();
				vars::slipperyFloors = true;
			}
			else {
				SendCommand("pm_friction 4");
				xTools::Xam::PulseController();
				vars::slipperyFloors = false;
			}
			return vars::slipperyFloors;
		}

		bool ToggleSuperJump() {
			if (!vars::superJump) {
				SendCommand("pm_jumpheight 500");
				xTools::Xam::PulseController();
				vars::superJump = true;
			}
			else {
				SendCommand("pm_jumpheight 68");
				xTools::Xam::PulseController();
				vars::superJump = false;
			}
			return vars::superJump;
		}

		bool ToggleSuperSpeed() {
			if (!vars::superSpeed) {
				SendCommand("pm_sprintSpeedForward 999");
				xTools::Xam::PulseController();
				vars::superSpeed = true;
			}
			else {
				SendCommand("pm_sprintSpeedForward 352");
				xTools::Xam::PulseController();
				vars::superSpeed = false;
			}
			return vars::superSpeed;
		}

		bool ToggleThirdPerson() {
			if (!vars::thirdPerson) {
				SendCommand("pm_thirdperson 1");
				xTools::Xam::PulseController();
				vars::thirdPerson = true;
			}
			else {
				SendCommand("pm_thirdperson 0");
				xTools::Xam::PulseController();
				vars::thirdPerson = false;
			}
			return vars::thirdPerson;
		}
	}

	namespace pages {

		const wchar_t* KeyboardPage() {

			std::wstring kbpage;
			std::wstring newLine = L"\r\n";
			kbpage += L"[*] Enter Custom Console Commands";
			kbpage += newLine;
			kbpage += L"[*] Examples : ";
			kbpage += newLine;
			kbpage += L"[*] pm_jumpheight 999";
			kbpage += newLine;
			kbpage += L"[*] pm_jumpheight 999;g_fov 120";
			return kbpage.c_str();
		}

		const wchar_t* MainPage() {

			std::wstring newLine = L"\r\n";
			std::wstring mainPage;
			mainPage += L"God Mode : DPAD_LEFT+X";
			mainPage += newLine;
			mainPage += L"Infinite Ammo : DPAD_LEFT+Y";
			mainPage += newLine;
			mainPage += L"No Target : DPAD_LEFT+B";
			mainPage += newLine;
			mainPage += L"No Clip : DPAD_LEFT+A";
			mainPage += newLine;
			mainPage += L"Show FPS : DPAD_UP+X";
			mainPage += newLine;
			mainPage += L"Super Jump : DPAD_UP+Y";
			mainPage += newLine;
			mainPage += L"Super Speed : DPAD_UP+B";
			mainPage += newLine;
			mainPage += L"Third Person : DPAD_UP+A";
			mainPage += newLine;
			mainPage += L"Slippery Floors : DPAD_RIGHT+X";
			mainPage += newLine;
			mainPage += L"Toggle FOV : DPAD_RIGHT+Y";
			mainPage += newLine;
			mainPage += L"Console Commands : LB+DPAD_RIGHT";
			mainPage += newLine + newLine;
			mainPage += L"Author : XeCrippy";
			return mainPage.c_str();
		}
	}

	namespace pageTitles {

		const wchar_t* KeyboardTitle = L"Enemy Territory : Send Custom Console Command";
		const wchar_t* MainTitle = L"Solace 360 : Enemy Territory TU1";
	}

	XINPUT_STATE state = { 0 };

	void MainPageUI() {
		const wchar_t* buttonLabels[] = { L"Continue" };
		xTools::Xam::ShowMessageBox(
			pageTitles::MainTitle,
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

		hre = XShowKeyboardUI(0, VKBD_DEFAULT, L"god", pageTitles::KeyboardTitle, pages::KeyboardPage(), r1, 512, &kb_overlapped); // show keyboard ui

		while (!XHasOverlappedIoCompleted(&kb_overlapped)) Sleep(25);

		if (hre == ERROR_IO_PENDING)  hr = _wtoi(r1); // returns input keyboard result

		std::string cmd = std::_Narrow_str(r1);
		funcs::SendCommand(cmd.c_str());
	}

	void _EnemyTerritory::LoadPlugin() {

		MainPageUI();

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_ENEMYTERRITORY) {

			bool hasToggled = false;

			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					MainPageUI();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::ToggleGodMode();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::InfiniteAmmo();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::ToggleNoTarget();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::ToggleNoclip();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::ToggleShowFPS();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::ToggleSuperJump();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::ToggleSuperSpeed();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::ToggleThirdPerson();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::ToggleSlipperyFloors();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::ToggleFOV();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) {

					ShowKeyboardUI();
				}
			}
			if (hasToggled) Sleep(500);
		}
	}
}