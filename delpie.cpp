#include <iostream>
#include <cmath>

long calculatePower(long x, long y, long P) {
    long result = 0;
    if (y == 1) {
        return x;
    }
    else {
        result = (long)pow(x, y) % P;
        return result;
    }
}

int main() {
    long P, G, x, a, y, b, ka, kb;
    using namespace std;

    cout << "Both the users should be agreed upon the public keys G and P" << endl;
    cout << "Enter value for public key G: ";
    cin >> G;
    cout << "Enter value for public key P: ";
    cin >> P;
    cout << "Enter value for private key a selected by user1: ";
    cin >> a;
    cout << "Enter value for private key b selected by user2: ";
    cin >> b;

    x = calculatePower(G, a, P);
    y = calculatePower(G, b, P);
    ka = calculatePower(y, a, P);
    kb = calculatePower(x, b, P);

    cout << "Secret key for User1 is: " << ka << endl;
    cout << "Secret key for User2 is: " << kb << endl;

    return 0;
}
