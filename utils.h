#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <vector>





namespace utils
{
	namespace console
	{
		void Init(std::string ConsoleName);
		void Release();
	}
	namespace convert
	{
		std::string Array2String(uint8_t ArrayByte[], size_t Size);
	}

}