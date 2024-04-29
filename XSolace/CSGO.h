#pragma once
#include "stdafx.h"

namespace CSGO {
	class CounterStrike {
	public:
		void LoadPlugin();

	private:
		bool showFps;
		bool friction;
		bool godMode;
		bool gravity;
		bool infiniteAmmo;
		bool money;
		bool sayText;
		bool score;

		static const uint32_t cl_showFPS = 0x88720710; // 0 | 1,2,3,4,10
		static const uint32_t ptr = 0x89FE2F4C;
		static const uint32_t sv_friction = 0x8871A930; // default 4.0
		static const uint32_t sv_gravity = 0x8871A444; // default 800.0
		static const uint32_t sv_infinite_ammo = 0x886BD48C; //  0 | 1

		static const uint32_t health_offset = 0x210;
		static const uint32_t maxHealth_offset = 0x20C;
		static const uint32_t money_offset = 0x1A28;
		static const uint32_t score_offset = 0x1D08;

		static const uint8_t byte_off = 0x0;
		static const uint8_t byte_on = 0x1;

		const wchar_t* KeyboardPage();
		const wchar_t* TogglesPage_();
		const wchar_t* WelcomePage_();

		static void(__fastcall* Cbuf_AddText)(int a1, const char* cmd, int a3);
		static void (*Cbuf_ExecuteText)(int a1);

		bool GodMode();
		bool InfiniteAmmo();
		bool InsaneScore();
		bool LowGravity();
		bool MaxMoney();
		bool ShowFPS();
		bool SlipperyFloor();
		bool SV_INFINITE_AMMO();

		void GodCvar();
		void KeyboardMenu();
		void KillBots();
		void __fastcall NoClip();
		void __fastcall SendCommand(const char* cmd);
		void TogglesPage();
		void WelcomePage();

	};
}