#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 0;
    }

    unsigned long long res = 1;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }

    return res;
}

int main() {
    int num;

    cout << "Enter a number to find its factorial: ";
    cin >> num;

    unsigned long long result = factorial(num);

    if (num >= 0) {
        cout << "Factorial of " << num << " is " << result << endl;
    }

    return 0;
}
	