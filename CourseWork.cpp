#include <iostream>
#include <string>
#include <locale>
#include <io.h>
#include <fcntl.h>

using namespace std;

const wstring RESET = L"\033[0m";
const wstring RED = L"\033[31m";
const wstring GREEN = L"\033[32m";
const wstring CYAN = L"\033[36m";
const wstring YELLOW = L"\033[33m";
const wstring MAGENTA = L"\033[35m";
const wstring BOLD = L"\033[1m";


const wstring LATIN_UPPER = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const wstring LATIN_LOWER = L"abcdefghijklmnopqrstuvwxyz";

const wstring RUSSIAN_UPPER = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
const wstring RUSSIAN_LOWER = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

const wstring UKRAINIAN_UPPER = L"АґҐБВГДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
const wstring UKRAINIAN_LOWER = L"ґґабвгдеєжзиіїйклмнопрстуфхцчшщьюя";

pair<wstring, wstring> chooseAlphabet() {
    int langChoice;
    wcout << YELLOW << L"Choose language alphabet:\n"
        << L"1. Ukrainian (А-Я, Ґ, Є, І, Ї)\n"
        << L"2. Russian (А-Я)\n"
        << L"3. Latin (A-Z)\n" << RESET;
    wcout << BOLD << L"Option: " << RESET;
    wcin >> langChoice;
    wcin.ignore();

    switch (langChoice) {
    case 1: return { UKRAINIAN_UPPER, UKRAINIAN_LOWER };
    case 2: return { RUSSIAN_UPPER, RUSSIAN_LOWER };
    case 3: return { LATIN_UPPER, LATIN_LOWER };
    default:
        wcout << RED << L"Invalid choice. Defaulting to Ukrainian.\n" << RESET;
        return { UKRAINIAN_UPPER, UKRAINIAN_LOWER };
    }
}

wstring caesarCipher(const wstring& text, int startKey, int multiplier, int divisor,
    const pair<wstring, wstring>& alphabets) {
    wstring result = L"";
    int key = startKey;
    int N = alphabets.first.size();

    for (wchar_t ch : text) {
        size_t index = alphabets.first.find(ch);
        bool isUpper = true;
        if (index == wstring::npos) {
            index = alphabets.second.find(ch);
            isUpper = false;
        }

        if (index != wstring::npos) {
            int shift = (key * multiplier) / divisor;
            int newIndex = (index + shift) % N;
            result += isUpper ? alphabets.first[newIndex] : alphabets.second[newIndex];
            key++;
        }
        else {
            result += ch;
        }
    }

    return result;
}

wstring caesarDecipher(const wstring& text, int startKey, int multiplier, int divisor,
    const pair<wstring, wstring>& alphabets) {
    wstring result = L"";
    int key = startKey;
    int N = alphabets.first.size();

    for (wchar_t ch : text) {
        size_t index = alphabets.first.find(ch);
        bool isUpper = true;
        if (index == wstring::npos) {
            index = alphabets.second.find(ch);
            isUpper = false;
        }

        if (index != wstring::npos) {
            int shift = (key * multiplier) / divisor;
            int newIndex = (index + N - (shift % N)) % N;
            result += isUpper ? alphabets.first[newIndex] : alphabets.second[newIndex];
            key++;
        }
        else {
            result += ch;
        }
    }

    return result;
}

void printLine(wchar_t ch = L'=', int length = 30) {
    for (int i = 0; i < length; i++) wcout << ch;
    wcout << endl;
}

void printMenu() {
    printLine();
    wcout << BOLD << CYAN << L"        CAESAR CIPHER" << RESET << endl;
    printLine();
    wcout << YELLOW << L"1." << RESET << L" " << GREEN << L"Encrypt phrase" << RESET << endl;
    wcout << YELLOW << L"2." << RESET << L" " << GREEN << L"Decrypt phrase" << RESET << endl;
    wcout << YELLOW << L"3." << RESET << L" " << RED << L"Exit" << RESET << endl;
    printLine();
    wcout << BOLD << L"Choose option: " << RESET;
}

int main() {
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
#endif

    locale::global(locale(""));

    while (true) {
        printMenu();
        int choice;
        wcin >> choice;
        wcin.ignore();

        if (choice == 1 || choice == 2) {
            wstring text;
            int startKey, multiplier, divisor;

            auto alphabets = chooseAlphabet();

            wcout << MAGENTA << L"Input Text: " << RESET;
            getline(wcin, text);
            wcout << MAGENTA << L"Input start key: " << RESET;
            wcin >> startKey;
            wcout << MAGENTA << L"Input multiplier: " << RESET;
            wcin >> multiplier;
            wcout << MAGENTA << L"Input divisor: " << RESET;
            wcin >> divisor;
            wcin.ignore();

            if (choice == 1) {
                wstring encrypted = caesarCipher(text, startKey, multiplier, divisor, alphabets);
                wcout << GREEN << L"\nEncrypted text: " << BOLD << encrypted << RESET << L"\n\n";
            }
            else {
                wstring decrypted = caesarDecipher(text, startKey, multiplier, divisor, alphabets);
                wcout << GREEN << L"\nDecrypted text: " << BOLD << decrypted << RESET << L"\n\n";
            }
        }
        else if (choice == 3) {
            wcout << RED << L"\nExiting program. Goodbye! :)" << RESET << endl;
            break;
        }
        else {
            wcout << RED << L"Invalid choice, please try again." << RESET << endl << endl;
        }
    }

    return 0;
}
