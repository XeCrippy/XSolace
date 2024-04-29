#pragma once
#include "stdafx.h"

namespace Crackdown {
	class _Crackdown {
	public:
		void LoadPlugin();

	private:
        bool afterlights;
        bool drawOutlines;
        bool god;
        bool graphs;
        bool infAmmo;
        bool showFps;
        bool sun;
        bool togglevsync;
        bool widescreen;

        static const uint32_t ammo = 0x82398630;
        static const uint32_t ammo_off = 0x7D6A5850;
        static const uint32_t ammo_on = 0x396B0000;
        static const uint32_t downscaleafterlight = 0x82C3B894; // uint
        static const uint32_t fastrender = 0x8325DFCB; // byte
        static const uint32_t godMode = 0x822D2D5C;
        static const uint32_t godMode_off = 0xEC0D6028;
        static const uint32_t  hideskinnedclumps = 0x8325E0DC; // byte
        static const uint32_t outlinemode = 0x8325FBC4; // byte
        static const uint32_t perfgraph = 0x8325FFDA; // byte
        static const uint32_t ppptool = 0x8325E0A2; // byte
        static const uint32_t setfps = 0x82C3B864; // uint
        static const uint32_t _showFps = 0x832601C8; // uint
        static const uint32_t showgputiming = 0x8325FFD9; // byte
        static const uint32_t  spawntiming = 0x8325F99C; // byte
        static const uint32_t toggleafterlights = 0x82C3B8DC; // byte
        static const uint32_t  togglealphapass = 0x82C3B8DA; // byte
        static const uint32_t togglebloom = 0x82C3B8DE; // byte       
        static const uint32_t togglehudinscreenshots = 0x8325DFF8; // byte
        static const uint32_t toggleopaquepass = 0x82C3B8D9; // byte
        static const uint32_t  toggleoutlines = 0x82C3B8DB; // byte
        static const uint32_t toggleparticleafterlights = 0x82C3B8E0; // byte
        static const uint32_t  toggleraycastoptimizations = 0x82C3B8E7; // byte
        static const uint32_t  togglesun = 0x82C3B8E3; // byte
        static const uint32_t  togglewatere3hack = 0x8325DFFC; // byte
        static const  uint32_t togglewaterpass = 0x82C3B8E5; // byte
        static const uint32_t vlock = 0x8325DFC5; // byte
        static const uint32_t vsync = 0x82C3B902; // byte

        static const uint8_t byte_off = 0x0;
        static const  uint8_t byte_on = 0x1;
        static const uint32_t outlineMode = 0x2;
        static const uint32_t dword_off = 0x0;
        static const uint32_t dword_on = 0x1;
        static const  uint32_t nop = 0x60000000;

        const wchar_t* MainPage();

        static void(*NoClip)();
        static void(*WideScreen)();

        bool Graphs();
        bool Outlines();

        void CrackdownTU6StaticCheats();
        void Fps();
        void GodMode();
        void InfiniteAmmo();
        void MessageBox();
        void ToggleAspectRatio();
        void ToggleNoClip();
	};
}
