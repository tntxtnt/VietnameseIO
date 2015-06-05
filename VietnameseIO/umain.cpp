//
// encoding: UTF-8 with BOM
// - So in order to print wide string to console output / read input from console we must use _setmode...
// - Use codecvt_utf8 for writing/reading from files
//

#include <iostream>
#include <fcntl.h> //_O_WTEXT
#include <io.h>    //_setmode()
#include <string>
#include <locale>
#include <codecvt> //possible C++11?
#include <fstream>

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
    if      (gender == L'a') std::wcout << L"Nam\n\n";
    else if (gender == L'b') std::wcout << L"Nữ\n\n";
    else                     std::wcout << L"Không xác định\n\n";

    // nhập tuổi
    int age;
    std::wcout << L"Nhập tuổi của bạn: ";
    std::wcin >> age;
    std::wcout << L">> Năm nay bạn được " << age << L" tuổi\n\n";


    // lưu file tiếng Việt (UTF-8 without BOM)
    std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);  // UTF-8
    std::wofstream fout(L"userinfo-c++.txt");
    if (!fout) {
        std::wcout << L"Không thể tạo file userinfo-c++.txt\n";
    } else {
        fout.imbue(loc);
        fout << username << L"\n" << gender << L"\n" << age << L"\n";
        fout.close();
    }
    
    // đọc file tiếng Việt (định dạng UTF-8 without BOM)
    std::wifstream fin(L"userinfo-c++.txt");
    if (!fin) {
        std::wcout << L"Không thể đọc file userinfo-c++.txt\n";
    } else {
        fin.imbue(loc);
        std::getline(fin, username);
        fin >> gender >> age;

        std::wcout << L"Họ tên: " << username << L"\nGiới tính: " 
                   << (gender == L'a' ? L"Nam" : (gender == L'b' ? L"Nữ" : L"Không xác định"))
                   << L"\nTuổi: " << age << L"\n\n";

        fin.close();
    }


    std::wcout << L"Chương trình kết thúc.\n";
}