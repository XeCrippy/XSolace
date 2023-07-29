#include "stdafx.h"
#include "Memory.h"


// Import from xboxkrnl.exe
extern "C"
{
    DWORD __stdcall ExCreateThread(
        HANDLE* pHandle,
        DWORD dwStackSize,
        DWORD* pThreadId,
        void* apiThreadStartup,
        PTHREAD_START_ROUTINE pStartAddress,
        void* pParameter,
        DWORD dwCreationFlagsMod
    );
}

namespace xTools {

    void* Memory::ResolveFunction(const std::string& moduleName, uint32_t ordinal)
    {
        HMODULE hModule = GetModuleHandle(moduleName.c_str());

        return (hModule == NULL) ? NULL : GetProcAddress(hModule, reinterpret_cast<const char*>(ordinal));
    }

    void Memory::Thread(PTHREAD_START_ROUTINE pStartAddress, void* pArgs)
    {
        CreateThread(nullptr, 0, pStartAddress, pArgs, 0, nullptr);
    }

    void Memory::ThreadEx(PTHREAD_START_ROUTINE pStartAddress, void* pArgs, uint32_t creationFlags)
    {
        ExCreateThread(nullptr, 0, nullptr, nullptr, pStartAddress, pArgs, creationFlags);
    }

    float ReadFloat(uint32_t Address) {
        return *(float*)Address;
    }

    uint8_t ReadUInt8(uint32_t Address) {
        return *(uint8_t*)Address;
    }

    uint16_t ReadUInt16(uint32_t Address) {
        return *(uint16_t*)Address;
    }

    uint32_t ReadUInt32(uint32_t Address) {
        return *(uint32_t*)Address;
    }

    uint64_t ReadUInt64(uint32_t Address) {
        return *(uint64_t*)Address;
    }

    void WriteFloat(uint32_t Address, float Value) {
        *(float*)Address = Value;
    }

    void WriteUInt8(uint32_t Address, uint8_t Value) {
        *(uint8_t*)Address = Value;
    }

    void WriteUInt16(uint32_t Address, uint16_t Value) {
        *(uint16_t*)Address = Value;
    }

    void WriteUInt32(uint32_t Address, uint32_t Value) {
        *(uint32_t*)Address = Value;
    }

    void WriteUInt64(uint32_t Address, uint64_t Value) {
        *(uint64_t*)Address = Value;
    }
}