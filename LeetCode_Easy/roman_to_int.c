#include<stdio.h>

int romanToInt(char* s) {
    int result = 0;
    int prev_value = 0;
    while (*s) {
        int value = 0;
        switch (*s) {
            case 'I': value = 1; break;
            case 'V': value = 5; break;
            case 'X': value = 10; break;
            case 'L': value = 50; break;
            case 'C': value = 100; break;
            case 'D': value = 500; break;
            case 'M': value = 1000; break;
        }
        if (value > prev_value) {
            result += value - 2 * prev_value;
        } else {
            result += value;
        }
        prev_value = value;
        s++;
    }
    return result;
}

int main() {
    char s[20];
    printf("Enter a Roman numeral: ");
    scanf("%s", s);
    int result = romanToInt(s);
    printf("The integer value is: %d\n", result);
    return 0;
}
