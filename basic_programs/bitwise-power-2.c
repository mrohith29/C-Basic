#include <stdio.h>

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Using bitwise operator
    if (num && !(num & (num - 1)))
        printf("%d is a power of 2\n", num);
    else
        printf("%d is not a power of 2\n", num);

    // Using ternary operator
    (num && !(num & (num - 1))) ? printf("%d is a power of 2\n", num) : printf("%d is not a power of 2\n", num);

    return 0;
}
