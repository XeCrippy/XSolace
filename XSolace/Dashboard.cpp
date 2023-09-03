#include "stdafx.h"

XINPUT_STATE state;

const wchar_t* MainPage() {
    std::wstring newLine = L"\r\n";
    std::wstring mainPage;
    mainPage += L"Current Games :";
    mainPage += newLine;
    mainPage += L"[*] Crackdown";
    mainPage += newLine;
    mainPage += L"[*] Crysis 2";
    mainPage += newLine;
    mainPage += L"[*] Counter Strike : GO";
    mainPage += newLine;
    mainPage += L"[*] Doom 3 BFG";
    mainPage += newLine;
    mainPage += L"[*] Enemy Territory : Quake Wars";
    mainPage += newLine;
    mainPage += L"[*] Saints Row";
    mainPage += newLine;
    mainPage += L"[*] Saints Row 2";
    mainPage += newLine;
    mainPage += L"[*] Saints Row The Third";
    mainPage += newLine;
    mainPage += L"[*] Saints Row IV";
    mainPage += newLine;
    mainPage += L"[*] Saints Row Gat Outta Hell";
    return mainPage.c_str();
}

const wchar_t* Page2() {
    std::wstring newLine = L"\r\n";
    std::wstring page2;
    page2 += L"[*] Sleeping Dogs";
    page2 += newLine;
    page2 += L"[*] Sonic Adventure";
    page2 += newLine;
    page2 += L"[*] Sonic Generations";
    page2 += newLine;
    page2 += L"[*] The Club";
    page2 += newLine + newLine;
    page2 += L"Author : XeCrippy";
    return page2.c_str();
}

void Dashboard::ShowPage2() {
    const wchar_t* buttonLabels[] = { L"Back", L"Close" };
    uint32_t buttonPressedIndex = 0;

    uint32_t result = xTools::Xam::ShowMessageBox(
        L"xSolace 360 Multi-Game Plugin",
        Page2(),
        buttonLabels,
        ARRAYSIZE(buttonLabels),
        &buttonPressedIndex,
        XMB_ALERTICON
    );

    if (result == ERROR_SUCCESS) {

        switch (buttonPressedIndex) {
        case 0:
            Dashboard::ShowMainPage();
            break;
        case 1:
            break;
        default:
            break;
        }
    }
}

void Dashboard::ShowMainPage() {

    const wchar_t* buttonLabels[] = {L"Next", L"Reboot Console", L"Close"};
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
        case 0:
            Dashboard::ShowPage2();
            break;
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
    xTools::Xam::XNotify("xSolace 360 : Dashboard Loaded. Press LB+RB to view info");

    while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_DASHBOARD) {

        XInputGetState(0, &state);
        bool hasToggled = false;

        if (XInputGetState(0, &state) == ERROR_SUCCESS) {

            if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

                ShowMainPage();
                hasToggled = true;
            }
        }
        if (hasToggled) Sleep(250);
    }
}
