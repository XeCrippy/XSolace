#include "stdafx.h"
#include "Dashlaunch.h"
#include "Memory.h"

#define LAUNCH_MODULE "launch.xex"

namespace xTools {

	enum {

		DL_ORDINALS_GETOPTVALBYNAME = 9,
		DL_ORDINALS_SETOPTVALBYNAME = 10,
	};

	DLAUNCHGETOPTVALBYNAME Dashlaunch::GetOptionValueByName = nullptr;
	DLAUNCHSETOPTVALBYNAME Dashlaunch::SetOptionValueByName = nullptr;

	HRESULT Dashlaunch::Init()
	{
		GetOptionValueByName = static_cast<DLAUNCHGETOPTVALBYNAME>(Memory::ResolveFunction(LAUNCH_MODULE, DL_ORDINALS_GETOPTVALBYNAME));
		if (GetOptionValueByName == nullptr)
			return E_FAIL;

		SetOptionValueByName = static_cast<DLAUNCHSETOPTVALBYNAME>(Memory::ResolveFunction(LAUNCH_MODULE, DL_ORDINALS_SETOPTVALBYNAME));
		if (SetOptionValueByName == nullptr)
			return E_FAIL;

		return S_OK;
	}
}