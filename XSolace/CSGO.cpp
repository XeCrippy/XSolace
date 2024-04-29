#include "stdafx.h"
#include "CSGO.h"

namespace CSGO {
	void(__fastcall* CounterStrike::Cbuf_AddText)(int a1, const char* cmd, int a3) = reinterpret_cast<void(__fastcall*)(int a1, const char* cmd, int a3)>(0x86a1a330);
	void (*CounterStrike::Cbuf_ExecuteText)(int a1) = reinterpret_cast<void(*)(int a1)>(0x86a1afb8);

	void __fastcall CounterStrike::SendCommand(const char* cmd) {
		Cbuf_AddText(0, cmd, 0);
		Cbuf_ExecuteText(NULL);
	}

	void CounterStrike::GodCvar() {
		godMode = !godMode;
		SendCommand("god;say Toggled God Mode");
	}

	bool CounterStrike::GodMode() {

		uint32_t health = xTools::Memory::ReadUInt32(ptr) + health_offset;
		uint32_t maxHealth = xTools::Memory::ReadUInt32(ptr) + maxHealth_offset;

		if (!godMode) {
			xTools::Memory::WriteUInt32(maxHealth, 9999999U);
			xTools::Memory::WriteUInt32(health, 9999999U);
			SendCommand("say Health set to 9999999");
			godMode = true;
		}
		else {

			xTools::Memory::WriteUInt32(maxHealth, 100u);
			xTools::Memory::WriteUInt32(health, 100u);
			SendCommand("say Health set to 100");
			godMode = false;
		}
		return godMode;
	}

	bool CounterStrike::InfiniteAmmo() {


		if (!infiniteAmmo) {

			xTools::Memory::WriteUInt32(sv_infinite_ammo, byte_on);
			infiniteAmmo = true;
		}
		else {

			xTools::Memory::WriteUInt32(sv_infinite_ammo, byte_off);
			infiniteAmmo = false;
		}
		return infiniteAmmo;
	}

	void CounterStrike::KillBots() {
		SendCommand("bot_kill");
	}

	bool CounterStrike::MaxMoney() {

		uint32_t _money = xTools::Memory::ReadUInt32(ptr) + money_offset;

		if (!money) {

			xTools::Memory::WriteUInt32(_money, 10000u);
			SendCommand("say Gave Max Money");
			money = true;
		}
		else {

			xTools::Memory::WriteUInt32(_money, 100u);
			money = false;
		}
		return money;
	}

	bool CounterStrike::InsaneScore() {

		uint32_t _score = xTools::Memory::ReadUInt32(ptr) + score_offset;

		if (!score) {

			xTools::Memory::WriteUInt32(_score, 1333337u);
			SendCommand("say Set score to 1333337");
			score = true;
		}
		else {

			xTools::Memory::WriteUInt32(_score, 100u);
			SendCommand("say Set score to 100");
			score = false;
		}
		return score;
	}

	bool CounterStrike::LowGravity() {

		if (!gravity) {

			xTools::Memory::WriteFloat(sv_gravity, 100.0f);
			SendCommand("say Low Gravity Enabled");
			gravity = true;
		}
		else {

			xTools::Memory::WriteFloat(sv_gravity, 800.0f);
			SendCommand("say Low Gravity Disabled");
			gravity = false;
		}
		return gravity;
	}

	void __fastcall CounterStrike::NoClip() {
		SendCommand("noclip;say Toggled No Clip");
	}

	bool CounterStrike::ShowFPS() {

		if (!showFps) {

			xTools::Memory::WriteUInt8(cl_showFPS, 0x4);
			SendCommand("cl_showfps 4;cl_showpos 1;+graph;say Show Debug Info Enabled");
			showFps = true;
		}
		else {

			xTools::Memory::WriteUInt8(cl_showFPS, 0x0);
			SendCommand("cl_showfps 0;cl_showpos 0;-graph;say Show Debug Info Disabled");
			showFps = false;
		}
		return showFps;
	}

	bool CounterStrike::SlipperyFloor() {

		if (!friction) {

			xTools::Memory::WriteFloat(sv_friction, 0.5f);
			SendCommand("say Slippery Floor Enabled");
			friction = true;
		}
		else {

			xTools::Memory::WriteFloat(sv_friction, 4.0f);
			SendCommand("say Slippery Floor Disabled");
			friction = false;
		}
		return friction;
	}

	bool CounterStrike::SV_INFINITE_AMMO() {

		if (!infiniteAmmo) {
			SendCommand("sv_infinite_ammo 1;say Infinite Ammo Enabled");
			infiniteAmmo = true;
		}
		else {
			SendCommand("sv_infinite_ammo 0; say Infinite Ammo Disabled");
			infiniteAmmo = false;
		}
		return infiniteAmmo;
	}


	const wchar_t* CounterStrike::KeyboardPage() {

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

	const wchar_t* CounterStrike::TogglesPage_() {

		std::wstring newLine = L"\r\n";
		std::wstring togglesPage;
		togglesPage += L"Show Debug Info : ";
		togglesPage += showFps ? L"Enabled" : L"Disabled";
		togglesPage += newLine;
		togglesPage += L"Infinite Ammo : ";
		togglesPage += infiniteAmmo ? L"Enabled" : L"Disabled";
		togglesPage += newLine;
		togglesPage += L"God Mode : ";
		togglesPage += godMode ? L"Enabled" : L"Disabled";
		togglesPage += newLine;
		togglesPage += L"Slippery Floor : ";
		togglesPage += friction ? L"Enabled" : L"Disabled";
		togglesPage += newLine;
		togglesPage += L"Low Gravity : ";
		togglesPage += gravity ? L"Enabled" : L"Disabled";
		togglesPage += newLine;
		togglesPage += L"Max Money : ";
		togglesPage += money ? L"Enabled" : L"Disabled";
		togglesPage += newLine;
		togglesPage += L"Insane Score : ";
		togglesPage += score ? L"Enabled" : L"Disabled";
		return togglesPage.c_str();
	}

	const wchar_t* CounterStrike::WelcomePage_() {
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

	const wchar_t* KeyboardTitle = L"CSGO : Send Custom Console Command";
	const wchar_t* TogglesTitle = L"CSGO : Toggle Info";
	const wchar_t* WelcomeTitle = L"Counter Strike: Global Offensive";

	void CounterStrike::TogglesPage() {

		const wchar_t* buttonLabels[] = { L"Close" };

		xTools::Xam::ShowMessageBox(
			TogglesTitle,
			TogglesPage_(),
			buttonLabels,
			ARRAYSIZE(buttonLabels)
		);
	}

	void CounterStrike::WelcomePage() {
		const wchar_t* buttonLabels[] = { L"Continue" };
		xTools::Xam::ShowMessageBox(
			WelcomeTitle,
			WelcomePage_(),
			buttonLabels,
			ARRAYSIZE(buttonLabels)
		);
	}

	XINPUT_STATE state = { 0 };

	void CounterStrike::KeyboardMenu() {

		unsigned long hr = 0;
		HRESULT hre = 0;
		wchar_t r1[512];
		XOVERLAPPED kb_overlapped;

		ZeroMemory(&state, sizeof(XINPUT_STATE));

		XInputGetState(0, &state);

		hre = XShowKeyboardUI(0, VKBD_DEFAULT, L"god", KeyboardTitle, KeyboardPage(), r1, 512, &kb_overlapped); // show keyboard ui

		while (!XHasOverlappedIoCompleted(&kb_overlapped)) Sleep(25);

		if (hre == ERROR_IO_PENDING)  hr = _wtoi(r1); // returns input keyboard result

		std::string cmd; //= std::_Narrow_str(r1);
		cmd += std::_Narrow_str(r1);
		cmd += ";say Sent custom cvar : ";
		cmd += std::_Narrow_str(r1);
		SendCommand(cmd.c_str());
	}

	void CounterStrike::LoadPlugin() {

		WelcomePage();

		SendCommand("sv_cheats 1;set developer 1");

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

					ShowFPS();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					SlipperyFloor();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					GodMode();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					SV_INFINITE_AMMO();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

					LowGravity();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

					MaxMoney();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

					InsaneScore();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					//KillBots();
					hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					NoClip();
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