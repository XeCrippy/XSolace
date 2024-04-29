#pragma once
#include "stdafx.h"

namespace SonicAdventure {
	class Sonic {
	public:
	    void LoadPlugin();

	private:
		bool infLives;
		bool infRings;
		bool timer;

		static bool(*WriteAchievements)(uint32_t ptr, int userIndex, int achievementID, bool isAsync);

		const wchar_t* Welcome();

		static void(__fastcall* AddNumRing)(uint16_t ssNumber);
		static void(__fastcall* SetTotalRing)(uint32_t num);
		static void(__fastcall* SleepTimer)();
		static void(__fastcall* WakeTimer)();

		static const uint32_t addRingsOnDmg = 0x8225967C;
		static const uint32_t disableTimer = 0x82259D14; // 39600000

		static const uint32_t addRingsOnDmg_off = 0x39600000;
		static const uint32_t addRingsOnDmg_on = 0x396003E7;
		static const uint32_t disableTimer_on = 0x39600000;
		static const uint32_t disableTimer_off = 0x39600001;

		bool InfRings();
		bool Timer();

		void Add999Rings();
		void MsgBox();
		void __fastcall TimerSleep();
		void __fastcall TimerWake();
		void UnlockAchievements();
	};
}