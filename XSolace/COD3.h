#pragma once
#include "stdafx.h"

namespace COD3 {
	class Cod3 {
	public:
	    void LoadPlugin();

	private:
		bool minicon;
		bool MiniCon();

		static void (*Cbuf_ExecuteText)(int clientIndex, const char* cmd);

		void KeyboardMenu();
		void SendCommand(const char* cmd);
		void ToggleGodMode();
		void ToggleNoClip();
		
	};
}