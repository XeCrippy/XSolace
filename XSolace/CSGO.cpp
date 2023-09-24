#include "stdafx.h"
#include "CSGO.h"

namespace CSGO {

	namespace vars {

		bool showFps = false;
		bool friction = false;
		bool godMode = false;
		bool gravity = false;
		bool infiniteAmmo = false;
		bool money = false;
		bool sayText = true;
		bool score = false;

		uint32_t cl_showFPS = 0x88720710; // 0 | 1,2,3,4,10
		uint32_t ptr = 0x89FE2F4C;
		uint32_t sv_friction = 0x8871A930; // default 4.0
		uint32_t sv_gravity = 0x8871A444; // default 800.0
		uint32_t sv_infinite_ammo = 0x886BD48C; //  0 | 1

		uint32_t health_offset = 0x210;
		uint32_t maxHealth_offset = 0x20C;
		uint32_t money_offset = 0x1A28;
		uint32_t score_offset = 0x1D08;

		uint8_t byte_off = 0x0;
		uint8_t byte_on = 0x1;
	}

	namespace gameFuncs {

		void(__fastcall* Cbuf_AddText)(int a1, const char* cmd, int a3) = reinterpret_cast<void(__fastcall*)(int a1, const char* cmd, int a3)>(0x86a1a330);
		void (*Cbuf_ExecuteText)(int a1) = reinterpret_cast<void(*)(int a1)>(0x86a1afb8);
	}

	namespace funcs {

		void __fastcall SendCommand(const char* cmd) {
			gameFuncs::Cbuf_AddText(0, cmd, 0);
			gameFuncs::Cbuf_ExecuteText(NULL);
		}

		void GodCvar() {
			vars::godMode = !vars::godMode;
			SendCommand("god;say Toggled God Mode");
		}

		bool GodMode() {

			uint32_t health = xTools::Memory::ReadUInt32(vars::ptr) + vars::health_offset;
			uint32_t maxHealth = xTools::Memory::ReadUInt32(vars::ptr) + vars::maxHealth_offset;

			if (!vars::godMode) {
				xTools::Memory::WriteUInt32(maxHealth, 9999999U);
				xTools::Memory::WriteUInt32(health, 9999999U);
				SendCommand("say Health set to 9999999");
				vars::godMode = true;
			}
			else {

				xTools::Memory::WriteUInt32(maxHealth, 100u);
				xTools::Memory::WriteUInt32(health, 100u);
				SendCommand("say Health set to 100");
				vars::godMode = false;
			}
			return vars::godMode;
		}

		bool InfiniteAmmo() {


			if (!vars::infiniteAmmo) {

				xTools::Memory::WriteUInt32(vars::sv_infinite_ammo, vars::byte_on);
				vars::infiniteAmmo = true;
			}
			else {

				xTools::Memory::WriteUInt32(vars::sv_infinite_ammo, vars::byte_off);
				vars::infiniteAmmo = false;
			}
			return vars::infiniteAmmo;
		}

		void KillBots() {
			SendCommand("bot_kill");
		}

		bool MaxMoney() {

			uint32_t _money = xTools::Memory::ReadUInt32(vars::ptr) + vars::money_offset;

			if (!vars::money) {

				xTools::Memory::WriteUInt32(_money, 10000u);
				SendCommand("say Gave Max Money");
				vars::money = true;
			}
			else {

				xTools::Memory::WriteUInt32(_money, 100u);
				vars::money = false;
			}
			return vars::money;
		}

		bool InsaneScore() {

			uint32_t _score = xTools::Memory::ReadUInt32(vars::ptr) + vars::score_offset;

			if (!vars::score) {

				xTools::Memory::WriteUInt32(_score, 1333337u);
				SendCommand("say Set score to 1333337");
				vars::score = true;
			}
			else {

				xTools::Memory::WriteUInt32(_score, 100u);
				SendCommand("say Set score to 100");
				vars::score = false;
			}
			return vars::score;
		}

		bool LowGravity() {

			if (!vars::gravity) {

				xTools::Memory::WriteFloat(vars::sv_gravity, 100.0f);
				SendCommand("say Low Gravity Enabled");
				vars::gravity = true;
			}
			else {

				xTools::Memory::WriteFloat(vars::sv_gravity, 800.0f);
				SendCommand("say Low Gravity Disabled");
				vars::gravity = false;
			}
			return vars::gravity;
		}

		void __fastcall NoClip() {
			SendCommand("noclip;say Toggled No Clip");
		}

		bool ShowFPS() {

			if (!vars::showFps) {

				xTools::Memory::WriteUInt8(vars::cl_showFPS, 0x4);
				SendCommand("cl_showfps 4;cl_showpos 1;+graph;say Show Debug Info Enabled");
				vars::showFps = true;
			}
			else {

				xTools::Memory::WriteUInt8(vars::cl_showFPS, 0x0);
				SendCommand("cl_showfps 0;cl_showpos 0;-graph;say Show Debug Info Disabled");
				vars::showFps = false;
			}
			return vars::showFps;
		}

		bool SlipperyFloor() {

			if (!vars::friction) {

				xTools::Memory::WriteFloat(vars::sv_friction, 0.5f);
				SendCommand("say Slippery Floor Enabled");
				vars::friction = true;
			}
			else {

				xTools::Memory::WriteFloat(vars::sv_friction, 4.0f);
				SendCommand("say Slippery Floor Disabled");
				vars::friction = false;
			}
			return vars::friction;
		}

		bool SV_INFINITE_AMMO() {

			if (!vars::infiniteAmmo) {
				SendCommand("sv_infinite_ammo 1;say Infinite Ammo Enabled");
				vars::infiniteAmmo = true;
			}
			else {
				SendCommand("sv_infinite_ammo 0; say Infinite Ammo Disabled");
				vars::infiniteAmmo = false;
			}
			return vars::infiniteAmmo;
		}
	}

	namespace pages {

		const wchar_t* KeyboardPage() {

			std::wstring kbpage;
			std::wstring newLine = L"\r\n";
			kbpage += L"[*] sv_cheats are enabled so most common cvars work";
			kbpage += newLine;
			kbpage += L"[*] Examples : ";
			kbpage += newLine;
			kbpage += L"[*] sv_infinite_ammo 1";
			kbpage += newLine;
			kbpage += L"[*] sv_infinite_ammo 1;fov_cs_debug 120";
			return kbpage.c_str();
		}

		const wchar_t* TogglesPage() {

			std::wstring newLine = L"\r\n";
			std::wstring togglesPage;
			togglesPage += L"Show Debug Info : ";
			togglesPage += vars::showFps ? L"Enabled" : L"Disabled";
			togglesPage += newLine;
			togglesPage += L"Infinite Ammo : ";
			togglesPage += vars::infiniteAmmo ? L"Enabled" : L"Disabled";
			togglesPage += newLine;
			togglesPage += L"God Mode : ";
			togglesPage += vars::godMode ? L"Enabled" : L"Disabled";
			togglesPage += newLine;
			togglesPage += L"Slippery Floor : ";
			togglesPage += vars::friction ? L"Enabled" : L"Disabled";
			togglesPage += newLine;
			togglesPage += L"Low Gravity : ";
			togglesPage += vars::gravity ? L"Enabled" : L"Disabled";
			togglesPage += newLine;
			togglesPage += L"Max Money : ";
			togglesPage += vars::money ? L"Enabled" : L"Disabled";
			togglesPage += newLine;
			togglesPage += L"Insane Score : ";
			togglesPage += vars::score ? L"Enabled" : L"Disabled";
			return togglesPage.c_str();
		}

		const wchar_t* WelcomePage() {
			std::wstring newLine = L"\r\n";
			std::wstring welcomePage;
			welcomePage += L"Show Debug Info : LB+A";
			welcomePage += newLine;
			welcomePage += L"Infinite Ammo : LB+B";
			welcomePage += newLine;
			welcomePage += L"God Mode : LB+Y";
			welcomePage += newLine;
			welcomePage += L"Slippery Floor : LB+X";
			welcomePage += newLine;
			welcomePage += L"Low Gravity : RB+A";
			welcomePage += newLine;
			welcomePage += L"Max Money : RB+B";
			welcomePage += newLine;
			welcomePage += L"Insane Score : RB+Y";
			welcomePage += newLine;
			welcomePage += L"Kill Bots : RB+X (currently disabled)";
			welcomePage += newLine;
			welcomePage += L"No Clip : Dpad Left+X";
			welcomePage += newLine;
			welcomePage += L"Return Here : LB+RB";
			welcomePage += newLine;
			welcomePage += L"View Toggle Info : LB+Dpad Down";
			welcomePage += newLine;
			welcomePage += L"Custom Console Commands : LB+Dpad Right";
			return welcomePage.c_str();
		}
	}

	namespace pageTitles {

		const wchar_t* KeyboardTitle = L"CSGO : Send Custom Console Command";
		const wchar_t* TogglesTitle = L"CSGO : Toggle Info";
		const wchar_t* WelcomeTitle = L"Counter Strike: Global Offensive";
	}

	void TogglesPage() {

		const wchar_t* buttonLabels[] = { L"Close" };

		xTools::Xam::ShowMessageBox(
			pageTitles::TogglesTitle,
			pages::TogglesPage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels)
		);
	}

	void WelcomePage() {
		const wchar_t* buttonLabels[] = { L"Continue" };
		xTools::Xam::ShowMessageBox(
			pageTitles::WelcomeTitle,
			pages::WelcomePage(),
			buttonLabels,
			ARRAYSIZE(buttonLabels)
			);
	}

	XINPUT_STATE state = { 0 };

	void KeyboardMenu() {

		unsigned long hr = 0;
		HRESULT hre = 0;
		wchar_t r1[512];
		XOVERLAPPED kb_overlapped;
		
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		XInputGetState(0, &state);

		hre = XShowKeyboardUI(0, VKBD_DEFAULT, L"god", pageTitles::KeyboardTitle, pages::KeyboardPage(), r1, 512, &kb_overlapped); // show keyboard ui

		while (!XHasOverlappedIoCompleted(&kb_overlapped)) Sleep(25);

		if (hre == ERROR_IO_PENDING)  hr = _wtoi(r1); // returns input keyboard result

		std::string cmd; //= std::_Narrow_str(r1);
		cmd += std::_Narrow_str(r1);
		cmd += ";say Sent custom cvar : ";
		cmd += std::_Narrow_str(r1);
		funcs::SendCommand(cmd.c_str());
	}

	void CounterStrike::LoadPlugin() {

		WelcomePage();

		funcs::SendCommand("sv_cheats 1;set developer 1");

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_COUNTERSTRIKE) {

			bool hasToggled = false;

			XInputGetState(0, &state);

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					WelcomePage();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) {

					TogglesPage();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::ShowFPS();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::SlipperyFloor();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::GodMode();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::SV_INFINITE_AMMO();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					funcs::LowGravity();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					funcs::MaxMoney();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					funcs::InsaneScore();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					//KillBots();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					funcs::NoClip();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) {

					KeyboardMenu();
				}
			}
			if (hasToggled) Sleep(300);
		}
	}
}