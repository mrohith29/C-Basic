/*
 * Insertion sort is a simple sorting algorithm that works the way we sort
 * playing cards in our hands. In this, first, we assume that the first element
 * is already sorted. Then we select an element from the unsorted subarray and
 * find its correct position in the sorted subarray. We do this until there are
 * no elements left in the unsorted subarray. The worst case time complexity of
 * insertion sort is O(n^2) and the best case time complexity is O(n). The space
 * complexity of insertion sort is O(1).
 * */

#include <stdio.h>
#define MAX_SIZE 10

void insertion_sort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n; i++) {
    j = i;
    while (j > 0 && arr[j] < arr[j - 1]) {
      temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
      j--;
    }
  }
}
