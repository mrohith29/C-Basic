/*
 * <SELECTION SORT>
 *
 * --Introduction--
 *  Selection sort is a sorting algorithm, specifically an in-place comparison
 * sort. It has O(n^2) time complexity, making it inefficient on large lists,
 * and generally performs worse than the similar insertion sort. Selection sort
 * is noted for its simplicity, and it has performance advantages over more
 * complicated algorithms in certain situations, particularly where auxiliary
 * memory is limited.
 *
 * --How it works--
 *  Selection sort works by finding the minimum value in a list and swapping it
 * with the first value in the list. It then starts at the second position,
 * finds the smallest value in the remaining list, and swaps it with the second
 * element. It continues iterating through the list and swapping elements until
 * it reaches the end of the list.
 *
 *  --Time Complexity--
 *  - Worst case performance: O(n^2)
 *  - Best case performance: O(n^2)
 *  - Average case performance: O(n^2)
 *  - Worst case space complexity: O(1)
 *
 * */

#include <stdio.h>
#define SIZE 10

void selection_sort(int arr[], int n) {
  int i, j, min, temp;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[i]) {
        min = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[SIZE];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  selection_sort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
