#pragma once
#include <Windows.h>
#include <iostream>
#include "vars.h"
#include "utils.h"

#include "detours.h"
#pragma comment(lib, "detours.lib")

typedef char(__cdecl* GamePacketFunction)(int a1, unsigned int a2, int a3, int a4, DWORD* a5);



namespace hook
{
	void Init();
	void Release();

	namespace game
	{
		char __cdecl  hookPacket(int a1, unsigned int a2, int a3, int a4, DWORD* a5);
	}
}