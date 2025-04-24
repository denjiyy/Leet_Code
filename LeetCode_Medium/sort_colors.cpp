#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using std::string;
using std::vector;

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int zeroIndex = 0, twoIndex = nums.size() - 1;
            for (int i = 0; i <= twoIndex; ) {
                if (nums[i] == 0) {
                    std::swap(nums[i], nums[zeroIndex]);
                    zeroIndex++;
                    i++;
                } else if (nums[i] == 2) {
                    std::swap(nums[i], nums[twoIndex]);
                    twoIndex--;
                } else {
                    i++;
                }
            }
        }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    solution.sortColors(nums);
    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}
