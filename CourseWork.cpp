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

int main() {
    cout << "============================" << endl;
    cout << "      Cipher Caesar" << endl;
    cout << "============================" << endl;
    cout << "1. Encrypt phrase: " << endl;
    cout << "2. Exit" << endl;
    cout << "Choose option: ";

    int choice;
    cin >> choice;
    cin.ignore();


   
}