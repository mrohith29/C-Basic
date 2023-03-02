#include <stdio.h>
#include <stdlib.h>

int isprime(int num){
	if(num <= 1){
		return 0;
	}
	else{
		for(int i = 2; i<num;i++){
			if(num % i == 0){
				return 0;
			}
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	if(argc < 2){
		printf("<Program> <X> <Y>");
		exit(0);
	}
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	for(int i = x;i<=y;i++){
		if(isprime(i)){
			printf("%d ", i);
		}
	}
	return 0;
}