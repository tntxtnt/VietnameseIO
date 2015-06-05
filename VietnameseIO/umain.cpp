//
// encoding: UTF-8 with BOM
// OLD FILE, mix C (use of _setmode) and C++ (operator<<)
//

#include <iostream>
#include <fcntl.h> //_O_WTEXT
#include <io.h>    //_setmode()
#include <string>

int wmain(int argc, wchar_t* argv[])
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT); //needed for input
    // nhớ chuyển font của console sang Consolas (size 16)

    std::wcout << L"Chương trình đọc và xuất chuỗi tiếng Việt\n\n"
        << L"  \"Gõ\" tiếng Việt bằng cách copy chuỗi tiếng Việt ở trình soạn thảo tiếng Việt\n"
        << L"nào đó rồi click phải chuột vào màn hình console\n\n";

    // nhập họ tên
    std::wstring username;
    std::wcout << L"Nhập họ tên của bạn: ";
    std::getline(std::wcin, username);
    std::wcout << L">> Xin chào, " << username << L"!\n\n";

    // nhập giới tính
    wchar_t gender;
    std::wcout << L"Bạn là nam hay nữ:\n a. Nam\n b. Nữ\n";
    std::wcin >> gender;
    std::wcout << L">> Giới tính: ";
    if (gender == L'a') std::wcout << L"Nam\n\n";
    else if (gender == L'b') std::wcout << L"Nữ\n\n";
    else                     std::wcout << L"Không xác định\n\n";

    // nhập tuổi
    int age;
    std::wcout << L"Nhập tuổi của bạn: ";
    std::wcin >> age;
    std::wcout << L">> Năm nay bạn được " << age << L" tuổi\n\n";


    std::wcout << L"Chương trình kết thúc.\n";
}