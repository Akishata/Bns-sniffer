#include "main.h"



void InitMain(HMODULE hModule)
{
	utils::console::Init("bns");
	
	while(!vars::game::BaseModule)
		vars::game::BaseModule = reinterpret_cast<uintptr_t>(GetModuleHandleA("Client.exe"));	

	vars::game::PacketFunction = vars::game::BaseModule + 0x561C10;
	hook::Init();

	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD9))
			break;

		Sleep(5);
	}
	hook::Release();
	utils::console::Release();
	FreeLibraryAndExitThread(hModule, 0);
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)InitMain, hModule, 0, nullptr));
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}