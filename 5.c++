#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    k = k % size;
    if (k == 0) return;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int steps = 3;

    printArray(arr);
    rotate(arr, steps);
    printArray(arr);

    return 0;
}
