#include "stdafx.h"
#include "TheClub.h"

namespace TheClub {

	namespace vars {
		uint32_t CheatsAlwaysGetAMedal = 0x82927D44;
		uint32_t CheatsDisableTutorialLevel = 0x8293F8EC;
		uint32_t CheatsExplosiveFB = 0x827ABB48;
		uint32_t CheatsExplosiveHE = 0x827ABB24;
		uint32_t CheatsExplosiveSmoke = 0x827ABB6C;
		uint32_t CheatsGiveAllWeapons = 0x827AB854; //  0 | 1
		uint32_t CheatsInfiniteAmmo = 0x827ADA30;
		uint32_t CheatsNoTimeAttackTimeout = 0x82928288;
		uint32_t CheatsPlayerInvunerable = 0x827AB830;
		uint32_t CheatsRetainAmmo = 0x827ADA54;
		uint32_t CheatsStopTimer = 0x827BE9AC;
		uint32_t CheatsUnlockAll = 0x8292B1A4;
		uint32_t CheatsUseDebugPlayerRestart = 0x827BE9D0;

		uint8_t OFF = 0x0;
		uint8_t ON = 0x1;

		bool alwaysGetAMedal = false;
		bool disableTutorialLevel = false;
		bool giveAllWeapons = false;
		bool infiniteAmmo = false;
		bool noAttackTimeout = false;
		bool playerInvunerable = false;
		bool stopTimer = false;
		bool unlockAll = false;
	}

	namespace funcs {

		bool AlwaysGetAMedal() {

			if (!vars::alwaysGetAMedal) {

			    xTools::Memory::WriteUInt8(vars::CheatsAlwaysGetAMedal, vars::ON);
				vars::alwaysGetAMedal = true;
			}
			else {

				xTools::Memory::WriteUInt8(vars::CheatsAlwaysGetAMedal, vars::OFF);
				vars::alwaysGetAMedal = false;
			}
			return vars::alwaysGetAMedal;
		}

		bool DisableTutorialLevel() {

			if (!vars::disableTutorialLevel) {

				*(uint8_t*)vars::CheatsDisableTutorialLevel = vars::ON;
				vars::disableTutorialLevel = true;
			}
			else {

				*(uint8_t*)vars::CheatsDisableTutorialLevel = vars::OFF;
				vars::disableTutorialLevel = false;
			}
			return vars::disableTutorialLevel;
		}

		bool GiveAllWeapons() {

			if (!vars::giveAllWeapons) {

				*(uint8_t*)vars::CheatsGiveAllWeapons = vars::ON;
				vars::giveAllWeapons = true;
			}
			else {

				*(uint8_t*)vars::CheatsGiveAllWeapons = vars::OFF;
				vars::giveAllWeapons = false;
			}
			return vars::giveAllWeapons;
		}

		bool InfiniteAmmo() {

			if (!vars::infiniteAmmo) {

				*(uint8_t*)vars::CheatsInfiniteAmmo = vars::ON;
				*(uint8_t*)vars::CheatsRetainAmmo = vars::ON;
				vars::infiniteAmmo = true;
			}
			else {

				*(uint8_t*)vars::CheatsInfiniteAmmo = vars::OFF;
				*(uint8_t*)vars::CheatsRetainAmmo = vars::OFF;
				vars::infiniteAmmo = false;
			}
			return vars::infiniteAmmo;
		}

		bool NoAttackTimeout() {

			if (!vars::noAttackTimeout) {

				*(uint8_t*)vars::CheatsNoTimeAttackTimeout = vars::ON;
				vars::noAttackTimeout = true;
			}
			else {

				*(uint8_t*)vars::CheatsNoTimeAttackTimeout = vars::OFF;
				vars::noAttackTimeout = false;
			}
			return vars::noAttackTimeout;
		}

		bool PlayerInvunerable() {

			if (!vars::playerInvunerable) {
				*(uint8_t*)vars::CheatsPlayerInvunerable = vars::ON;
				vars::playerInvunerable = true;
			}
			else {

				*(uint8_t*)vars::CheatsPlayerInvunerable = vars::OFF;
				vars::playerInvunerable = false;
			}
			return vars::playerInvunerable;
		}

		bool StopTimer() {

			if (!vars::stopTimer) {

				*(uint8_t*)vars::CheatsStopTimer = vars::ON;
				vars::stopTimer = true;
			}
			else {

				*(uint8_t*)vars::CheatsStopTimer = vars::OFF;
				vars::stopTimer = false;
			}
			return vars::stopTimer;
		}

		bool UnlockAll() {

			if (!vars::unlockAll) {

				*(uint8_t*)vars::CheatsUnlockAll = vars::ON;
				vars::unlockAll = true;
			}
			else {

				*(uint8_t*)vars::CheatsUnlockAll = vars::OFF;
				vars::unlockAll = false;
			}
			return vars::unlockAll;
		}
	}

	void _TheClub::LoadPlugin() {

		xTools::Xam::XNotify("Coming soon....");
	}
}