#include <Windows.h>
#include <stdexcept>

template<typename T>
T resolveApi(const char* moduleName, const char* procName) {
    HMODULE hModule = LoadLibraryA(moduleName);
    if (!hModule) {
        throw std::runtime_error("Failed to load module");
    }

    FARPROC procAddr = GetProcAddress(hModule, procName);
    if (!procAddr) {
        throw std::runtime_error("Failed to get address of function");
    }

    return reinterpret_cast<T>(procAddr);
}

#define WinApi(moduleName, api) resolveApi<decltype(&api)>(moduleName, #api)
