#include <iostream>
#include <random>
#include <string>

using namespace std;

int customHash(const string& message) {
    hash<string> hasher;
    size_t seed = hasher(message);
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(0, 65535);
    return distribution(generator);
}

int main() {
    string message, receivedMessage;
    cout << "Enter the message: ";
    getline(cin, message);

    int hashValue = customHash(message);
    cout << "Original Message: " << message << endl;
    cout << "Hash value: " << hashValue << endl;

    cout << "Enter the received message: ";
    getline(cin, receivedMessage);

    int receivedHashValue = customHash(receivedMessage);
    cout << "Received Message: " << receivedMessage << endl;
    cout << "Received Hash value: " << receivedHashValue << endl;

    if (receivedHashValue == hashValue) {
        cout << "Integrity: The message has not been modified." << endl;
    } else {
        cout << "Integrity: The message has been modified." << endl;
    }

    return 0;
}
