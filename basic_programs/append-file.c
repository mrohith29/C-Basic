#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *f;
	char ch;
	f = fopen("hello.txt", "a+");
	if(f != NULL){
		fprintf(f, "%s\n", "NoobScience");
	}
	fclose(f);
	f = fopen("hello.txt", "r");
	if(f != NULL){
		while((ch=getc(f))!=EOF){
			printf("%c", ch);
		}
	}
	fclose(f);
	return 0;
}