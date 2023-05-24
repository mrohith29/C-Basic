#include <stdio.h>

// Function to convert decimal to binary
void decToBin(int num) {
    int binary[32], i = 0;

    // Convert decimal to binary
    while (num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }

    // Print the binary number in reverse order
    printf("The binary equivalent is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Call the decToBin function
    decToBin(num);

    return 0;
}
