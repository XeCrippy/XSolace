#include "stdafx.h"
#include "Mafia2.h"

namespace Mafia2 {

	bool infAmmo = false;

	uint32_t ammo = 0x881D32A0;
	uint32_t ammo_off = 0x7D4A2214;
	uint32_t ammo_on = 0x394A0000;

	bool InfiniteAmmo() {
		if (!infAmmo) {
			xTools::Memory::WriteUInt32(ammo, ammo_on);
			xTools::Xam::PulseController();
			xTools::Xam::XNotify("Infinite Ammo : Enabled");
			infAmmo = true;
		}
		else {
			xTools::Memory::WriteUInt32(ammo, ammo_off);
			xTools::Xam::PulseController();
			xTools::Xam::XNotify("Infinite Ammo : Disabled");
			infAmmo = false;
		}
		return infAmmo;
	}



	void _Mafia2::LoadPlugin() {

		XINPUT_STATE state = { 0 };
		ZeroMemory(&state, sizeof(state));

		while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_MAFIA2) {

			bool hasToggled = false;

			if (XInputGetState(0, &state) == ERROR_SUCCESS) {

				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

					//hasToggled = true;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

					InfiniteAmmo();
					hasToggled = true;
				}
			}
			if (hasToggled) Sleep(300);
		}
	}
}