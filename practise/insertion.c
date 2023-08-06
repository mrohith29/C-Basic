#include <stdio.h>

void insertion(int arr[], int n){
    for (int i = 0; i < n; i++){
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

int main()
{
    int arr[100] = {12, 3, 4, 2, 1, 10};
    insertion(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
}