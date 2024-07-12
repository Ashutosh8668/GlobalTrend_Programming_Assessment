#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;
    int maxLen = 0, start = 0;

    for (int end = 0; end < s.length(); ++end) {
        if (charIndex.find(s[end]) != charIndex.end()) {
            start = max(start, charIndex[s[end]] + 1);
        }
        charIndex[s[end]] = end;
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters in \"" << s << "\": " << lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << "Length of longest substring without repeating characters in \"" << s << "\": " << lengthOfLongestSubstring(s) << endl;

    s = "pwwkew";
    cout << "Length of longest substring without repeating characters in \"" << s << "\": " << lengthOfLongestSubstring(s) << endl;

    s = "";
    cout << "Length of longest substring without repeating characters in \"" << s << "\": " << lengthOfLongestSubstring(s) << endl;

    s = "abcdefg";
    cout << "Length of longest substring without repeating characters in \"" << s << "\": " << lengthOfLongestSubstring(s) << endl;

    return 0;
}

