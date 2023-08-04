#include "stdafx.h"

XINPUT_STATE state;

const wchar_t* MainPage() {
    std::wstring newLine = L"\r\n";
    std::wstring mainPage;
    mainPage += L"Current Games :";
    mainPage += newLine;
    mainPage += L"[*] Crackdown";
    mainPage += newLine;
    mainPage += L"[*] Counter Strike : GO";
    mainPage += newLine;
    mainPage += L"[*] Enemy Territory : Quake Wars";
    mainPage += newLine;
    mainPage += L"[*] Saints Row";
    mainPage += newLine;
    mainPage += L"[*] Saints Row 2";
    mainPage += newLine;
    mainPage += L"[*] Saints Row The Third";
    mainPage += newLine;
    mainPage += L"[*] Saints Row Gat Outta Hell";
    mainPage += newLine;
    mainPage += L"[*] Sleeping Dogs";
    mainPage += newLine;
    mainPage += L"[*] Sonic Adventure";
    mainPage += newLine;
    mainPage += L"[*] The Club";
    mainPage += newLine + newLine;
    mainPage += L"Author : XeCrippy";
    return mainPage.c_str();
}

void MsgBox() {

    const wchar_t* buttonLabels[] = {L"Continue", L"Reboot Console", L"Close"};
    uint32_t buttonPressedIndex = 0;
    uint32_t result = xTools::Xam::ShowMessageBox(
        L"xSolace 360 Multi-Game Plugin",
        MainPage(),
        buttonLabels,
        ARRAYSIZE(buttonLabels),
        &buttonPressedIndex,
        XMB_ALERTICON
    );

    if (result == ERROR_SUCCESS) {

        switch (buttonPressedIndex) {
        case 1:
            xTools::Xam::Reboot();
            break;
        default:
            break;
        }
    }
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
