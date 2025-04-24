#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::string;

class Solution {
    public:
        int myAtoi(string s) {
            int i = 0, sign = 1;
            long long result = 0;

            while (i < s.size() && s[i] == ' ') {
                i++;
            }

            if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
                sign = (s[i] == '-') ? -1 : 1;
                i++;
            }

            while (i < s.size() && isdigit(s[i])) {
                result = result * 10 + (s[i] - '0');
                if (result * sign > INT_MAX) return INT_MAX;
                if (result * sign < INT_MIN) return INT_MIN;
                i++;
            }

            return result * sign;
        }
};

int main() {
    Solution solution;
    string str = "   -42";
    int result = solution.myAtoi(str);
    std::cout << "The converted integer is: " << result << std::endl;
    return 0;
}
