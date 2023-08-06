#include <stdio.h>

void selection(int arr [], int n){
    for (int i = 0; i < n;i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[100] = {12, 3, 4, 2, 1, 10};
    selection(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
}