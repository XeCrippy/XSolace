#pragma once
#include "stdafx.h"

namespace Left4Dead2 {

	class L4D2 {

	public :
	    void LoadPlugin();

	private :
		bool DebugInfo();
		bool GodMode();
		bool InfiniteAmmo();
		bool LowGravity();
		bool ShowGraphs();
		bool SlipperyFloors();
		
		void KeyboardMenu();
		void NoClip();
		void SendCommand(const char* cmd);
		void Shake();
		void WelcomePage_();
		
		const wchar_t* KeyboardPage();
		const wchar_t* WelcomePage();
	};
}