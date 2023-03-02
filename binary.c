#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,key,mid,flag=0;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &key);
	int low = 0;
	int high = n-1;
	while(low <= high){
		mid = (low + high) / 2;
		if(key = arr[mid]){
			flag = 1;
			break;
		}
		else if(key > arr[mid]){
			low = mid +1;
		}
		else{
			high = mid - 1;
		}
	}
	if(flag == 1){
		printf("Search found %d at %d position", key, mid+1);
	}
	else{
		printf("%d", mid);
		printf("Search didn't find %d", key);
	}
	return 0;
}