#include "stdafx.h"
#include "Crackdown.h"

namespace Crackdown {

    void(*_Crackdown::NoClip)() = reinterpret_cast<void(*)()>(0x822C1FF8);
    void(*_Crackdown::WideScreen)() = (void(*)())(0x8257A4D8);

    void _Crackdown::Fps() {
        xTools::Memory::WriteUInt32(_showFps, dword_on);
        xTools::Memory::WriteUInt8(showgputiming, byte_on);
    }

    void _Crackdown::GodMode() {
        xTools::Memory::WriteUInt32(godMode, nop);
    }

    bool _Crackdown::Graphs() {
        if (!graphs) {
            xTools::Memory::WriteUInt8(perfgraph, byte_on);
            xTools::Xam::PulseController();
            graphs = true;
        }
        else {
            xTools::Memory::WriteUInt8(perfgraph, byte_off);
            xTools::Xam::PulseController();
            graphs = false;
        }
        return graphs;
    }

    void _Crackdown::InfiniteAmmo() {
        xTools::Memory::WriteUInt32(ammo, ammo_on);
    }

    bool _Crackdown::Outlines() {
        if (!drawOutlines) {
            xTools::Memory::WriteUInt32(outlinemode, outlineMode);
            xTools::Xam::PulseController();
            drawOutlines = true;
        }
        else {
            xTools::Memory::WriteUInt32(outlinemode, dword_off);
            xTools::Xam::PulseController();
            drawOutlines = false;
        }
        return drawOutlines;
    }

    void _Crackdown::ToggleAspectRatio() {
        WideScreen();
        xTools::Xam::PulseController();
    }

    void _Crackdown::ToggleNoClip() {
        NoClip();
        xTools::Xam::PulseController();
    }

    void _Crackdown::CrackdownTU6StaticCheats() {
        GodMode();
        Fps();
        InfiniteAmmo();
        xTools::Memory::WriteUInt8(vsync, byte_off);
        xTools::Memory::WriteUInt8(spawntiming, byte_off);
        xTools::Memory::WriteUInt8(toggleafterlights, byte_off);
        xTools::Memory::WriteUInt8(togglebloom, byte_off);
    }

    const wchar_t* _Crackdown::MainPage() {
        std::wstring newLine = L"\r\n";
        std::wstring Page2;
        Page2 += L"Fly Mode = DPAD_LEFT+A";
        Page2 += newLine;
        Page2 += L"Toggle Outlines = DPAD_LEFT+X";
        Page2 += newLine;
        Page2 += L"Toggle Aspect Ratio = DPAD_LEFT+B";
        Page2 += newLine;
        Page2 += L"Show Graphs = DPAD_LEFT+Y";
        Page2 += newLine + newLine;
        Page2 += L"[*] I have had to make some changes to the Crackdown 1 & 2 trainers to avoid crashing issues. Most cheats are set statically on load now.";
        return Page2.c_str();
    }

    const wchar_t* Title = L"Crackdown TU6 Trainer";

    const wchar_t* buttonLabels[] = { L"Continue" };

    void _Crackdown::MessageBox() {

        xTools::Xam::ShowMessageBox(
            Title,
            MainPage(),
            buttonLabels,
            ARRAYSIZE(buttonLabels),
            nullptr,
            XMB_ALERTICON
        );
    }

    void _Crackdown::LoadPlugin() {

        XINPUT_STATE state = { 0 };
        ZeroMemory(&state, sizeof(state));
        CrackdownTU6StaticCheats();
        MessageBox();

        while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_CRACKDOWN) {

            bool hasToggled = false;
            XInputGetState(0, &state);

            if (XInputGetState(0, &state) == ERROR_SUCCESS) {

                if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

                    Outlines();
                    hasToggled = true;
                }
                if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

                    ToggleAspectRatio();
                    hasToggled = true;
                }
                if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

                    Graphs();
                    hasToggled = true;
                }
                if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

                    ToggleNoClip();
                    hasToggled = true;
                }
            }
            if (hasToggled) Sleep(500);
        }
    }
}
