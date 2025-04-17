#include<iostream>
#include <string> 
using namespace std;

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

   
    return decryptedText;
}

int main() {
    cout << "============================" << endl;
    cout << "      Cipher Caesar" << endl;
    cout << "============================" << endl;
    cout << "1. Encrypt phrase: " << endl;
    cout << "2. Decrypt phrase: " << endl;
    cout << "2. Exit" << endl;
    cout << "Choose option: ";

    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string text;
        int startKey, multiplier, divisor;

        cout << "Input Text: ";
        getline(cin, text);
        cout << "Input start key: ";
        cin >> startKey;
        cout << "Input multiplier: ";
        cin >> multiplier;
        cout << "Input divisor: ";
        cin >> divisor;
        cin.ignore();

        string encrypted = caesarCipher(text, startKey, multiplier, divisor);
        cout << "Encrypted text: " << encrypted << endl;
    }
    else if (choice == 2) {
       
    }
    else {
        cout << "Exit..." << endl;
    }

    return 0;
   
}