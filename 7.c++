#include <iostream>
using namespace std;

int sumOfDigits(int num) {
    int sum = 0;

    if (num < 0) {
        num = -num;
    }

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int main() {
    int n;

    cout << "Enter a number to compute the sum of its digits: ";
    cin >> n;

    int res = sumOfDigits(n);

    cout << "Sum of the digits of " << n << " is " << res << endl;

    return 0;
}