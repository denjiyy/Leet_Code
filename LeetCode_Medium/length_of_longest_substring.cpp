#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::string;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.size();
            int maxLength = 0;
            int start = 0;
            std::unordered_map<char, int> charIndex;

            for (int end = 0; end < n; end++) {
                if (charIndex.find(s[end]) != charIndex.end()) {
                    start = std::max(start, charIndex[s[end]] + 1);
                }
                charIndex[s[end]] = end;
                maxLength = std::max(maxLength, end - start + 1);
            }
            return maxLength;
        }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(s);
    std::cout << "Length of longest substring without repeating characters: " << result << std::endl;
    return 0;
}
