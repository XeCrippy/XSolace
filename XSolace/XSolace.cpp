#include "stdafx.h"
#include "XSolace.h"

bool PluginMain::s_Running = false;
uint32_t PluginMain::s_CurrentTitleId = 0;

void PluginMain::Start()
{
	s_Running = true;
    xTools::Memory::ThreadEx(reinterpret_cast<PTHREAD_START_ROUTINE>(Update), nullptr, 2);
}

void PluginMain::Stop()
{
	s_Running = false;
	Sleep(250);
}

uint32_t PluginMain::Update(void*)
{
	while (s_Running)
	{
		uint32_t newTitleId = xTools::Xam::GetCurrentTitleId();
		if (newTitleId != s_CurrentTitleId)
			InitNewTitle(newTitleId);
	}
	return 0;
}

void PluginMain::InitNewTitle(uint32_t newTitleId)
{
    s_CurrentTitleId = newTitleId;

    switch (newTitleId)
    {
	case xTools::GAME_DASHBOARD:
		Sleep(3000);
		Dashboard::Init();
        break;
	case xTools::GAME_SONICADVENTURE:
		Sleep(10000);
		SonicAdventure::Sonic::LoadPlugin();
        break;
	case xTools::GAME_CRACKDOWN:
		Sleep(15000);
		Crackdown::_Crackdown::LoadPlugin();
		break;
	case xTools::GAME_COUNTERSTRIKE:
		Sleep(15000);
		CSGO::CounterStrike::LoadPlugin();
		break;
	case xTools::GAME_DEADRISING2:
		Sleep(15000);
		DeadRising2::_DeadRising2::LoadPlugin();
		break;
	case xTools::GAME_ENEMYTERRITORY:
		Sleep(15000);
		EnemyTerritory::_EnemyTerritory::LoadPlugin();
		break;
	case xTools::GAME_SAINTSROW:
		Sleep(15000);
		SaintsRow::_SaintsRow::LoadPlugin();
		break;
	case xTools::GAME_SAINTSROW2:
		Sleep(15000);
		SaintsRow2::_SR2::LoadPlugin();
		break;
	case xTools::GAME_SAINTSROW3:
		Sleep(15000);
		SaintsRow3::SR3::LoadPlugin();
		break;
	case xTools::GAME_SAINTSROWGOH:
		Sleep(15000);
		SaintsRowGOH::SRGatOuttaHell::LoadPlugin();
		break;
	case xTools::GAME_SLEEPINGDOGS:
		Sleep(15000);
		SleepingDogs::_SleepingDogs::LoadPlugin();
		break;
	case xTools::GAME_SONICGENERATIONS:
		Sleep(15000);
		SonicGenerations::_SonicGenerations::LoadPlugin();
		break;
	case xTools::GAME_THECLUB:
		Sleep(15000);
		TheClub::_TheClub::LoadPlugin();
		break;
    default:
        break;
    }
}

BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, void* pReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
		PluginMain::Start();

	if (dwReason == DLL_PROCESS_DETACH)
		PluginMain::Stop();

	return TRUE;
}
