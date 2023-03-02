#include <stdio.h>
#include <string.h>

int main() {
    char strings[10][50], temp[50];
    int num, i, j;

    printf("Enter the number of strings to be sorted: ");
    scanf("%d", &num);

    printf("Enter %d strings: \n", num);

    // Reading strings from user
    for(i=0; i<num; i++)
        scanf("%s", strings[i]);

    // Sorting the strings in alphabetical order
    for(i=0; i<num-1; i++) {
        for(j=0; j<num-i-1; j++) {
            if(strcmp(strings[i], strings[j]) > 0) {
                strcpy(temp, strings[j]);
                strcpy(strings[j], strings[j+1]);
                strcpy(strings[j+1], temp);
            }
        }
    }

    printf("Strings in alphabetical order: \n");
    // Printing the sorted strings
    for(i=0; i<num; i++)
        printf("%s\n", strings[i]);

    return 0;
}
