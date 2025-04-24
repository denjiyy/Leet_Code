#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

bool isPalindrome(int x) {
    if (x < 0) return false;
    int original = x, reversed = 0;
    while (x > 0) {
        if (reversed > (INT_MAX / 10)) {
            return false;
        }
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return original == reversed;
}

int main() {
    printf("%d\n", isPalindrome(121));
    printf("%d\n", isPalindrome(-121));
    printf("%d\n", isPalindrome(10));
    printf("%d\n", isPalindrome(2147447412));
}
