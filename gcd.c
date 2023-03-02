#include <stdio.h>

// Recursive function to find GCD
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd_recursive(b, a % b);
    }
}

// Non-recursive function to find GCD
int gcd_non_recursive(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("GCD using recursive function: %d\n", gcd_recursive(num1, num2));
    printf("GCD using non-recursive function: %d\n", gcd_non_recursive(num1, num2));
    return 0;
}
