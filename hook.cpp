#include "hook.h"

char __cdecl hook::game::hookPacket(int a1, unsigned int a2, int a3, int a4, DWORD* a5)
{
	GamePacketFunction ReturnOrig = reinterpret_cast<GamePacketFunction>(vars::game::PacketFunction);

	uint8_t* ArrayPacket = new uint8_t[a3];
	memcpy(ArrayPacket, reinterpret_cast<PVOID>(a2), a3);

	std::cout << utils::convert::Array2String(ArrayPacket, a3) << std::endl;

	delete[] ArrayPacket;


	return ReturnOrig(a1, a2, a3, a4, a5);
}

void hook::Init()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	DetourAttach(&(PVOID&)vars::game::PacketFunction, &hook::game::hookPacket);


	DetourTransactionCommit();
}

void hook::Release()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	DetourDetach(&(PVOID&)vars::game::PacketFunction, &hook::game::hookPacket);


	DetourTransactionCommit();
}
