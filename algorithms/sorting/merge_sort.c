#include <stdio.h>
#define MAX_SIZE 10

void merge(int arr[], int left[], int right[], int left_size, int right_size) {
  int i = 0, j = 0, k = 0;

  while (i < left_size && j < right_size) {
    if (left[i] < right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < left_size) {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < right_size) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int size) {
  if (size < 2) {
    return;
  }
  int mid = size / 2;
  int left[mid];
  int right[size - mid];

  for (int i = 0; i < mid; i++) {
    left[i] = arr[i];
  }

  for (int i = mid; i < size; i++) {
    right[i - mid] = arr[i];
  }

  merge_sort(left, mid);
  merge_sort(right, size - mid);
  merge(arr, left, right, mid, size - mid);
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[MAX_SIZE];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  merge_sort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
