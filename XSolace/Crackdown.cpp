#include "stdafx.h"
#include "Crackdown.h"

namespace Crackdown {

	namespace vars {

        bool afterlights = false;
        bool drawOutlines = false;
        bool god = false;
        bool graphs = false;
        bool infAmmo = false;
        bool showFps = false;
        bool sun = false;
        bool togglevsync = false;
        bool widescreen = false;

        uint32_t ammo = 0x82398630;
        uint32_t ammo_off = 0x7D6A5850;
        uint32_t ammo_on = 0x396B0000;
        uint32_t downscaleafterlight = 0x82C3B894; // uint
        uint32_t fastrender = 0x8325DFCB; // byte
        uint32_t godMode = 0x822D2D5C;
        uint32_t godMode_off = 0xEC0D6028;
        uint32_t  hideskinnedclumps = 0x8325E0DC; // byte
        uint32_t outlinemode = 0x8325FBC4; // byte
        uint32_t perfgraph = 0x8325FFDA; // byte
        uint32_t ppptool = 0x8325E0A2; // byte
        uint32_t setfps = 0x82C3B864; // uint
        uint32_t _showFps = 0x832601C8; // uint
        uint32_t showgputiming = 0x8325FFD9; // byte
        uint32_t  spawntiming = 0x8325F99C; // byte
        uint32_t toggleafterlights = 0x82C3B8DC; // byte
        uint32_t  togglealphapass = 0x82C3B8DA; // byte
        uint32_t togglebloom = 0x82C3B8DE; // byte       
        uint32_t togglehudinscreenshots = 0x8325DFF8; // byte
        uint32_t toggleopaquepass = 0x82C3B8D9; // byte
        uint32_t  toggleoutlines = 0x82C3B8DB; // byte
        uint32_t toggleparticleafterlights = 0x82C3B8E0; // byte
        uint32_t  toggleraycastoptimizations = 0x82C3B8E7; // byte
        uint32_t  togglesun = 0x82C3B8E3; // byte
        uint32_t  togglewatere3hack = 0x8325DFFC; // byte
        uint32_t togglewaterpass = 0x82C3B8E5; // byte
        uint32_t vlock = 0x8325DFC5; // byte
        uint32_t vsync = 0x82C3B902; // byte

        uint8_t byte_off = 0x0;
        uint8_t byte_on = 0x1;
        uint32_t outlineMode = 0x2;
        uint32_t dword_off = 0x0;
        uint32_t dword_on = 0x1;
        uint32_t nop = 0x60000000;
	}

    namespace gameFuncs {

        void(*NoClip)() = reinterpret_cast<void(*)()>(0x822C1FF8);
        void(*WideScreen)() = (void(*)())(0x8257A4D8);
    }

    namespace funcs {

        void Fps() {
            xTools::WriteUInt32(vars::_showFps, vars::dword_on);
            xTools::WriteUInt8(vars::showgputiming, vars::byte_on);
        }

        void GodMode() {
            xTools::WriteUInt32(vars::godMode, vars::nop);
        }

        bool Graphs() {
            if (!vars::graphs) {
                xTools::WriteUInt8(vars::perfgraph, vars::byte_on);
                xTools::Xam::PulseController();
                vars::graphs = true;
            }
            else {
                xTools::WriteUInt8(vars::perfgraph, vars::byte_off);
                xTools::Xam::PulseController();
                vars::graphs = false;
            }
            return vars::graphs;
        }

        void InfiniteAmmo() {
            xTools::WriteUInt32(vars::ammo, vars::ammo_on);
        }

        bool Outlines() {
            if (!vars::drawOutlines) {
                xTools::WriteUInt32(vars::outlinemode, vars::outlineMode);
                xTools::Xam::PulseController();
                vars::drawOutlines = true;
            }
            else {
                xTools::WriteUInt32(vars::outlinemode, vars::dword_off);
                xTools::Xam::PulseController();
                vars::drawOutlines = false;
            }
            return vars::drawOutlines;
        }

        void ToggleAspectRatio() {
            gameFuncs::WideScreen();
            xTools::Xam::PulseController();
        }

        void ToggleNoClip() {
            gameFuncs::NoClip();
            xTools::Xam::PulseController();
        }

        void CrackdownTU6StaticCheats() {

            GodMode();
            Fps();
            InfiniteAmmo();
            xTools::WriteUInt8(vars::vsync, vars::byte_off);
            xTools::WriteUInt8(vars::spawntiming, vars::byte_off);
            xTools::WriteUInt8(vars::toggleafterlights, vars::byte_off);
            xTools::WriteUInt8(vars::togglebloom, vars::byte_off);
        }
    }

    namespace msgBox {

        const wchar_t* MainPage() {
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
    }

    void MessageBox() {

        xTools::Xam::ShowMessageBox(
            msgBox::Title,
            msgBox::MainPage(),
            msgBox::buttonLabels,
            ARRAYSIZE(msgBox::buttonLabels),
            nullptr,
            XMB_ALERTICON
        );
    }

    void _Crackdown::LoadPlugin() {

        XINPUT_STATE state = { 0 };
        ZeroMemory(&state, sizeof(state));
        funcs::CrackdownTU6StaticCheats();
        MessageBox();

        while (xTools::Xam::GetCurrentTitleId() == xTools::GAME_CRACKDOWN) {

            bool hasToggled = false;
            XInputGetState(0, &state);

            if (XInputGetState(0, &state) == ERROR_SUCCESS) {

                if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {

                    MessageBox();
                    hasToggled = true;
                }
                if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {

                    funcs::Outlines();
                    hasToggled = true;
                }
                if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {

                    funcs::ToggleAspectRatio();
                    hasToggled = true;
                }
                if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {

                    funcs::Graphs();
                    hasToggled = true;
                }
                if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

                    funcs::ToggleNoClip();
                    hasToggled = true;
                }
            }
            if (hasToggled) Sleep(500);
        }
    }
}