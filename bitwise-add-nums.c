#include <stdio.h>

int add(int x, int y){
	while(y != 0){
		int carry = x & y;
		x = x ^ y;
		y = carry << 1;
	}
}

int main(){

	return 0;
}
