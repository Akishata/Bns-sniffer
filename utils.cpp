#include "utils.h"

void utils::console::Init(std::string ConsoleName)
{
    AllocConsole();

    freopen_s(reinterpret_cast<_iobuf**>(__acrt_iob_func(0)), ("conin$"), ("r"), __acrt_iob_func(0));
    freopen_s(reinterpret_cast<_iobuf**>(__acrt_iob_func(1)), ("conout$"), ("w"), __acrt_iob_func(1));
    freopen_s(reinterpret_cast<_iobuf**>(__acrt_iob_func(2)), ("conout$"), ("w"), __acrt_iob_func(2));

    SetConsoleTitleA(ConsoleName.c_str());
}

void utils::console::Release()
{
    fclose(__acrt_iob_func(0));
    fclose(__acrt_iob_func(1));
    fclose(__acrt_iob_func(2));

    FreeConsole();
}



std::string utils::convert::Array2String(uint8_t ArrayByte[], size_t Size)
{
    static auto ToHex = [](int Val) -> std::string
    {
        char a[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
        char buff[3] = { a[Val / 16] , a[Val % 16] , 0 };
        return buff;
    };

    std::string s;
    s.reserve(Size);

    for (size_t i = 0; i < Size; i++)
    {
        s += ToHex(ArrayByte[i]) + ' ';
    }

    s.pop_back();
    return s;
}
