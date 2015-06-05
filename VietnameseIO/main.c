/*
 * encoding: UTF-8 with BOM
 *
 * ISSUE: Really weird bug at fgetws() with stdin, doesn't read the newline character
 *        => getwc(stdin) to ignore it. 
 */

#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
#include <stdio.h>
#include <string.h>

int wmain(int argc, wchar_t* argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT); //needed for output
    _setmode(_fileno(stdin), _O_U16TEXT); //needed for input
    // nhớ chuyển font của console sang Consolas (size 16)

    wprintf(L"%ls%ls%ls", L"Chương trình đọc và xuất chuỗi tiếng Việt\n\n",
        L"  \"Gõ\" tiếng Việt bằng cách copy chuỗi tiếng Việt ở trình soạn thảo tiếng Việt\n",
        L"nào đó rồi click phải chuột vào màn hình console\n\n");

    // nhập họ tên
    wchar_t username[40];
    wprintf(L"Nhập họ tên của bạn: ");
    fgetws(username, 40, stdin);
    username[wcslen(username) - 1] = L'\0';
    getwc(stdin); //comment out this line if fgetws did read the newline character from stdin
    wprintf(L">> Xin chào, %ls!\n\n", username);

    // nhập giới tính
    wchar_t gender;
    wprintf(L"Bạn là nam hay nữ:\n a. Nam\n b. Nữ\n");
    wscanf(L"%lc", &gender);
    wprintf(L">> Giới tính: %ls\n\n", gender == L'a' ? L"Nam" : (gender == L'b' ? L"Nữ" : L"Không xác định"));

    // nhập tuổi
    int age;
    wprintf(L"Nhập tuổi của bạn: ");
    wscanf(L"%d", &age);
    wprintf(L">> Năm nay bạn được %d tuổi\n\n", age);


    // lưu file tiếng Việt (UTF-8 with BOM)
    FILE* fout = _wfopen(L"userinfo-c.txt", L"w, ccs=UTF-8");
    if (!fout) {
        wprintf(L"Không thể tạo file userinfo-c.txt\n");
    } else {
        fwprintf(fout, L"%ls\n%lc\n%d\n", username, gender, age);
        fclose(fout);
    }

    // đọc file tiếng Việt (định dạng UTF-8 with BOM)
    FILE* fin = _wfopen(L"userinfo-c.txt", L"r, ccs=UTF-8");
    if (!fin) {
        wprintf(L"Không thể đọc file userinfo-c.txt\n");
    }
    else {
        fgetws(username, 40, fin);
        username[wcslen(username) - 1] = L'\0'; //now fgetws works fine
        fwscanf(fin, L"%lc", &gender);
        fwscanf(fin, L"%d", &age);

        wprintf(L"Họ tên: %ls\nGiới tính: %ls\nTuổi: %d\n\n", username,
            gender == L'a' ? L"Nam" : (gender == L'b' ? L"Nữ" : L"Không xác định"), age);

        fclose(fin);
    }


    wprintf(L"Chương trình kết thúc.\n");
}