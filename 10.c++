#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

bool containsOnlyAlpha(const string& s) {
    for (char ch : s) {
        if (!isalpha(ch)) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;

    cout << "Enter a string to check if it contains only alphabetic characters: ";
    getline(cin, str);

    bool res = containsOnlyAlpha(str);

    if (res) {
        cout << "The string contains only alphabetic characters." << endl;
    } else {
        cout << "The string does not contain only alphabetic characters." << endl;
    }    return 0;
}
