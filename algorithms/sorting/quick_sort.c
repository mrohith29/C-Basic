#include <stdio.h>
#define MAX_SIZE 10

void quick_sort(int arr[], int left, int right) {
  if (left < right) {
    int mid = arr[(left + right) / 2];
    int i = left;
    int j = right;
    while (1) {
      while (arr[i] < mid) {
        i++;
      }
      while (mid < arr[j]) {
        j--;
      }
      if (i >= j) {
        break;
      }
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    quick_sort(arr, left, j);
    quick_sort(arr, j + 1, right);
  }
}

int main() {
  int n;
  int arr[MAX_SIZE];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  quick_sort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
