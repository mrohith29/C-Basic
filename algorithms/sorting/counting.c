#include <stdio.h>

#define RANGE 100

void counting_sort(int arr[], int n){
	int count[RANGE+1] = {0};
	int output[n];
	int i;

	for(i=0;i<n;i++){
		count[arr[i]]++;
	}

	for(i=1;i<=RANGE;i++){
		count[i] += count[i-1];
	}

	for(i=n-1;i>=0;i--){
		output[count[arr[i]] -1] = arr[i];
		count[arr[i]]--;
	}

	for(i=0;i<n;i++){
		arr[i] = output[i];
	}
}

int main() {
  int n = 5;
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  counting_sort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}