#include <iostream>
#include <utility> 
 
using namespace std;

pair<int, pair<int, int> > calculateExtendedEuclidean(int num1, int num2) 
{
    int x = 1, y = 0;
    int lastX = 0, lastY = 1;
    int quotient, remainder, tempX, tempY;
    while (num1 != 0) 
    {
        quotient = num2 / num1;
        remainder = num2 % num1;
        tempX = lastX - quotient * x;
        tempY = lastY - quotient * y;
        lastX = x; 
        lastY = y;
        x = tempX; 
        y = tempY;
        num2 = num1; 
        num1 = remainder;
    }
    return make_pair(num2, make_pair(lastX, lastY));
}
 
int calculateModularInverse(int num, int mod) 
{
    return (calculateExtendedEuclidean(num, mod).second.first + mod) % mod;
}
 
int main()
{
    int num, mod;
    cout << "Enter a number to find its modular multiplicative inverse: ";
    cin >> num;
    cout << "Enter the modular value: ";
    cin >> mod;
    cout << "The modular multiplicative inverse is: " << calculateModularInverse(num, mod) << endl;
    return 0;
}
