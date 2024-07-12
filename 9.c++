#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDifference(const vector<int>& arr) {
    if (arr.size() < 2) {
        cout << "Array must contain at least two elements." << endl;
        return 0;
    }

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    return maxVal - minVal;
}

int main() {
    vector<int> numbers = {2, 3, 10, 6, 4, 8, 1};

    cout << "Array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    int res = maxDifference(numbers);

    cout << "Maximum difference between any two elements in the array is " << res << endl;

    return 0;
}