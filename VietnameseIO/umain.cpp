#include <iostream>
#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
#include <string>

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT); //needed for output
    _setmode(_fileno(stdin), _O_U16TEXT);  //needed for input

    std::wcout << L"Chương trình đọc và xuất chuỗi tiếng Việt\n\n";

    std::wstring username;
    std::wcout << L"Nhập họ tên của bạn: ";
    std::getline(std::wcin, username);
    
    std::wcout << L"Xin chào, " << username << L"!\n";

    int gender;
    std::wcout << L"Nhập 1 nếu bạn là nam, nhập 2 nếu bạn là nữ: ";
    std::wcin >> gender;

    std::wcout << L"Giới tính: ";
    if (gender == 1)      std::wcout << L"Nam\n";
    else if (gender == 2) std::wcout << L"Nữ\n";
    else                  std::wcout << L"Không xác định\n";
}