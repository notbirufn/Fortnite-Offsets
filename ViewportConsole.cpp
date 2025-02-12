static inline void InitializeViewportConsole()
{
    uintptr_t GEngine = *reinterpret_cast<uintptr_t*>(uintptr_t(GetModuleHandle(NULL)) + 0x161D6FA8);

    if (GEngine == 0)
        return;

    uintptr_t ConsoleClass = *reinterpret_cast<uintptr_t*>(GEngine + 0xf0); // UEngine::ConsoleClass

    if (ConsoleClass == 0)
        return;

    uintptr_t GameViewport = *reinterpret_cast<uintptr_t*>(GEngine + 0xa20); // UEngine::GameViewport

    if (GameViewport == 0)
        return;

    uintptr_t(*NewObject)(uintptr_t, uintptr_t, int) = reinterpret_cast<decltype(NewObject)>(uintptr_t(GetModuleHandle(NULL)) + 0x1E6E40C);

    if (NewObject == 0)
        return;

    uintptr_t ViewportConsole = NewObject(GameViewport, ConsoleClass, 0);

    if (ViewportConsole == 0)
        return;

    *reinterpret_cast<uintptr_t*>(GameViewport + 0x40) = ViewportConsole; // UGameViewportClient::ViewportConsole
}
