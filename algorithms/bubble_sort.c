/*
 * Bubble sort in c
 *
 * --Introduction--
 *  Bubble sort is a simple sorting algorithm that repeatedly steps through the
 * list to be sorted, compares each pair of adjacent items and swaps them if
 * they are in the wrong order. The pass through the list is repeated until no
 * swaps are needed, which indicates that the list is sorted. The algorithm,
 * which is a comparison sort, is named for the way smaller or larger elements
 * "bubble" to the top of the list. Although the algorithm is simple, it is too
 * slow and impractical for most problems even when compared to insertion sort.
 *
 * --Algorithm--
 *  Bubble sort works by repeatedly comparing the adjacent elements of an array
 * and swapping them if they are out of order. The algorithm consists of a loop
 * over the elements of the array. In each iteration, the algorithm compares
 * each pair of adjacent elements. If the elements are not in order, they are
 * swapped. Because each pass through the array places the next largest value in
 * its proper place, a sorting algorithm may stop early if it detects that the
 * array has become sorted.
 *
 * --Time Complexity--
 *  Worst Case: O(n^2)
 *  Average Case: O(n^2)
 *  Best Case: O(n)
 *  Auxiliary Space: O(1)
 *
 * --References--
 *  https://en.wikipedia.org/wiki/Bubble_sort
 *  http://www.geeksforgeeks.org/bubble-sort/
 * */

#include <stdio.h>
#define MAX_SIZE 20

void bubble_sort(int arr[], int n) {
  // Loop to access each array element
  for (int i = 0; i < n; i++) {
    // Loop to compare array elements that are next to each other
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {

        // Swapping if elements are not in the intended order
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int n;
  int arr[MAX_SIZE];
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  bubble_sort(arr, n);
  printf("Sorted array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
