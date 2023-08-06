#include <stdio.h>

void merge_sort(int arr[], int n){
    if(n<2)
        return;
    int mid = n / 2;
}

int main()
{
    int arr[100] = {12, 3, 4, 2, 1, 10};
    merge_sort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
}