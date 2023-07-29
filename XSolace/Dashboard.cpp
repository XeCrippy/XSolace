#include "stdafx.h"

XINPUT_STATE state;

void MsgBox() {

    const wchar_t* buttonLabels[] = { L"Change Power LED", L"Reboot", L"Close"};
    xTools::Xam::ShowMessageBox(
        L"Dashboard Testing",
        L"Testing",
        buttonLabels,
        ARRAYSIZE(buttonLabels)
    );
}

void Dashboard::Init()
{
    xTools::Xam::XNotify("xSolace 360 : Dashboard Loaded");

    while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_DASHBOARD) {

        XInputGetState(0, &state);
        bool hasToggled = false;

        if (XInputGetState(0, &state) == ERROR_SUCCESS) {

            if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

                MsgBox();
                hasToggled = true;
            }
        }
        if (hasToggled) Sleep(250);
    }
}
