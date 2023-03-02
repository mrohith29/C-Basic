#include <stdio.h>
#include <math.h>

int main()
{
	int num,rem,count,sum=0;
	scanf("%d", &num);
	int org = num;
	while(num > 0){
		rem = num % 10;
		count += 1;
		num = num / 10;
	}
	num = org;
	while(num > 0){
		rem = num % 10;
		sum += pow(rem, count);
		num = num / 10;
	}
	if(org == sum){
		printf("Perfect");
	}
	else{
		printf("Not");
	}
	return 0;
}