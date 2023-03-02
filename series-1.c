#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int num){
	if(num <= 0){
		return 1;
	}
	return num * factorial(num - 1);
}

int main(int argc, char const *argv[])
{
	if(argc<2){
		printf("<Program> <x>");
		exit(0);
	}
	int sum = 1;
	int x = atoi(argv[1]);
	for(int i=1;i<=x;i++){
		sum = sum + (-1) * pow(-1, i)*(pow(x, i) / factorial(i));
		printf("%d\n", (-1) * pow(-1, i)*(pow(x, i) / factorial(i))); 
	}
	printf("%d", sum);
	return 0;
}