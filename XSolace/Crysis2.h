#pragma once
#include "stdafx.h"

namespace Crysis2 {
	class _Crysis2 {
	public:
		void LoadPlugin();

	private:
		bool aimAssist;
		bool fov;
		bool godMode;
		bool infiniteAmmo;

		const wchar_t* KeyboardPage();
		const wchar_t* MainPage();

		static int(*ExecuteStringInternal)(uint32_t consolePtr, const char* command, bool bFromConsole, bool bSilentMode);

		bool AdvancedAimAssist();
		bool DemigodMode();
		bool InfinteAmmo();
		bool ToggleFov();

		void ExecCommand(const char* command);
		void ShowMainPageUI();
	};
}