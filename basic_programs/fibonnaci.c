#include <stdio.h>

// Recursive function to print Fibonacci series
void fibonacci_recursive(int num) {
    static int a = 0, b = 1, sum;
    if (num > 0) {
        sum = a + b;
        a = b;
        b = sum;
        printf("%d ", sum);
        fibonacci_recursive(num - 1);
    }
}

// Non-recursive function to print Fibonacci series
void fibonacci_non_recursive(int num) {
    int a = 0, b = 1, sum;
    printf("%d %d ", a, b);
    for (int i = 3; i <= num; i++) {
        sum = a + b;
        a = b;
        b = sum;
        printf("%d ", sum);
    }
}

int main() {
    int num;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    printf("Fibonacci series using recursive function: ");
    printf("%d %d ", 0, 1);
    fibonacci_recursive(num - 2);
    printf("\nFibonacci series using non-recursive function: ");
    fibonacci_non_recursive(num);
    return 0;
}
