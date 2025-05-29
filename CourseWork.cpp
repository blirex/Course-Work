#include <iostream>
#include <string>
using namespace std;


const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string CYAN = "\033[36m";
const string YELLOW = "\033[33m";
const string MAGENTA = "\033[35m";
const string BOLD = "\033[1m";

string caesarCipher(const string& text, int startKey, int multiplier, int divisor) {
    string encryptedText = "";
    int key = startKey;

    for (char charValue : text) {
        if (isalpha(charValue)) {
            int shift = (key * multiplier) / divisor;
            if (islower(charValue)) {
                charValue = ((charValue - 'a' + shift) % 26) + 'a';
            }
            else {
                charValue = ((charValue - 'A' + shift) % 26) + 'A';
            }
        }
        encryptedText += charValue;
        key++;
    }
    return encryptedText;
}

string caesarDecipher(const string& text, int startKey, int multiplier, int divisor) {
    string decryptedText = "";
    int key = startKey;

    for (char charValue : text) {
        if (isalpha(charValue)) {
            int shift = (key * multiplier) / divisor;
            if (islower(charValue)) {
                charValue = ((charValue - 'a' - shift + 26) % 26) + 'a';
            }
            else {
                charValue = ((charValue - 'A' - shift + 26) % 26) + 'A';
            }
        }
        decryptedText += charValue;
        key++;
    }
    return decryptedText;
}

void printLine(char ch = '=', int length = 30) {
    for (int i = 0; i < length; i++) cout << ch;
    cout << endl;
}

void printMenu() {
    printLine();
    cout << BOLD << CYAN << "        CAESAR CIPHER" << RESET << endl;
    printLine();
    cout << YELLOW << "1." << RESET << " " << GREEN << "Encrypt phrase" << RESET << endl;
    cout << YELLOW << "2." << RESET << " " << GREEN << "Decrypt phrase" << RESET << endl;
    cout << YELLOW << "3." << RESET << " " << RED << "Exit" << RESET << endl;
    printLine();
    cout << BOLD << "Choose option: " << RESET;
}

int main() {
    while (true) {
        printMenu();
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string text;
            int startKey, multiplier, divisor;

            cout << MAGENTA << "Input Text: " << RESET;
            getline(cin, text);
            cout << MAGENTA << "Input start key: " << RESET;
            cin >> startKey;
            cout << MAGENTA << "Input multiplier: " << RESET;
            cin >> multiplier;
            cout << MAGENTA << "Input divisor: " << RESET;
            cin >> divisor;
            cin.ignore();

            string encrypted = caesarCipher(text, startKey, multiplier, divisor);

            cout << GREEN << "\nEncrypted text: " << BOLD << encrypted << RESET << "\n\n";
        }
        else if (choice == 2) {
            string text;
            int startKey, multiplier, divisor;

            cout << MAGENTA << "Input Encrypted Text: " << RESET;
            getline(cin, text);
            cout << MAGENTA << "Input start key: " << RESET;
            cin >> startKey;
            cout << MAGENTA << "Input multiplier: " << RESET;
            cin >> multiplier;
            cout << MAGENTA << "Input divisor: " << RESET;
            cin >> divisor;
            cin.ignore();

            string decrypted = caesarDecipher(text, startKey, multiplier, divisor);

            cout << GREEN << "\nDecrypted text: " << BOLD << decrypted << RESET << "\n\n";
        }
        else if (choice == 3) {
            cout << RED << "\nExiting program. Goodbye! :)" << RESET << endl;
            break;
        }
        else {
            cout << RED << "Invalid choice, please try again." << RESET << endl << endl;
        }
    }

    return 0;
}
