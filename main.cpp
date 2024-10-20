#include <iostream>
#include "modAlphaCipher.h"
#include <locale>
using namespace std;
bool isValid(const wstring& s) {
    for (wchar_t i:s) {
        if (!(i >= L'А' && i <= L'Я') || !iswupper(i)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv)
{
    setlocale(LC_ALL, "");
    wstring key;
    wstring text;
    unsigned int op;
    wcout << L"Шифровальщик готов. Введите ключ: ";
    wcin >> key;
    if (!isValid(key)) {
        wcerr << L"Неверный формат ключа\n";
        return 1;
    }
    wcout << L"Ключ установлен\n";
    modAlphaCipher cipher(key);
    do {
        wcout << L"Шифровальщик готов. Введите номер операции (0-выход, 1-зашифровать, 2-расшифровать): ";
        wcin >> op;
        if (op > 2) {
            wcout << L"Неверный номер операции\n";
        } else if (op > 0) {
            wcout << L"Шифровальщик готов. Введите текст: ";
            wcin >> text;
            if (isValid(text)) {
                if (op == 1) {
                    wcout << cipher.encrypt(text) << endl;
                } else {
                    wcout << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << L"Неверный формат текста\n";
            }
        }
    } while (op != 0);
    return 0;
}
