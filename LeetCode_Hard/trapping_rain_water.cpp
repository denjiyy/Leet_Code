#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using std::string;
using std::vector;

class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            if (n == 0) return 0;

            vector<int> leftMax(n);
            vector<int> rightMax(n);

            leftMax[0] = height[0];
            for (int i = 1; i < n; ++i) {
                leftMax[i] = std::max(leftMax[i - 1], height[i]);
            }

            rightMax[n - 1] = height[n - 1];
            for (int i = n - 2; i >= 0; --i) {
                rightMax[i] = std::max(rightMax[i + 1], height[i]);
            }

            int waterTrapped = 0;
            for (int i = 0; i < n; ++i) {
                waterTrapped += std::min(leftMax[i], rightMax[i]) - height[i];
            }

            return waterTrapped;
        }
};

int main() {
    Solution solution;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = solution.trap(height);
    std::cout << "Water trapped: " << result << std::endl;
    return 0;
}
