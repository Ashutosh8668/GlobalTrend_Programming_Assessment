#include <iostream>
using namespace std;

int gcd(int x, int y) {
    if (x < 0) x = -x;
    if (y < 0) y = -y;

    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    
    return x;
}

int main() {
    int num1, num2;

    cout << "Enter two numbers to find their GCD: ";
    cin >> num1 >> num2;

    int res = gcd(num1, num2);

    cout << "GCD of " << num1 << " and " << num2 << " is " << res << endl;

    return 0;
}
