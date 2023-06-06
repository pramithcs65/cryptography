#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string performEncryption(const string& input, int key1, int key2) {
    string encrypted;
    for (char ch : input) {
        if (isalpha(ch)) {
            char encryptedChar = ((ch - 'A') * key1 + key2) % 26 + 'A';
            encrypted += encryptedChar;
        } else {
            encrypted += ch;
        }
    }
    return encrypted;
}

string performDecryption(const string& input, int key1, int key2) {
    int inverseKey1 = -1;
    for (int i = 0; i < 26; ++i) {
        if ((key1 * i) % 26 == 1) {
            inverseKey1 = i;
            break;
        }
    }

    if (inverseKey1 == -1) {
        cout << "Invalid value of 'key1'. It must be coprime with 26." << endl;
        return "";
    }

    string decrypted;
    for (char ch : input) {
        if (isalpha(ch)) {
            char decryptedChar = ((ch - 'A' - key2 + 26) * inverseKey1) % 26 + 'A';
            decrypted += decryptedChar;
        } else {
            decrypted += ch;
        }
    }
    return decrypted;
}

int main() {
    string input;
    int key1, key2;
    cout << "Enter the input: ";
    getline(cin, input);
    cout << "Enter the value of 'key1': ";
    cin >> key1;
    cout << "Enter the value of 'key2': ";
    cin >> key2;
    string encrypted = performEncryption(input, key1, key2);
    cout << "Encrypted: " << encrypted << endl;
    string decrypted = performDecryption(encrypted, key1, key2);
    cout << "Decrypted: " << decrypted << endl;
    return 0;
}
