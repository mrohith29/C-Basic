#include <stdio.h>
#include <stdlib.h>

void bubble(int arr[], int n){
    for(int i = 0; i< n; i++){
        for (int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int arr[100] = {12, 3, 4, 2, 1, 10};
    bubble(arr, 6);
    for(int i = 0; i<6;i++){
        printf("%d ", arr[i]);
    }
}