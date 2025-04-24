#include<stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = searchInsert(nums, size, target);
    printf("The target %d should be inserted at index %d\n", target, result);
    return 0;
}
