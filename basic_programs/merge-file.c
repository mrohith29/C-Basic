#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *f1, *f2, *f3;
	char ch;
	f1 = fopen("hello.txt", "r");
	f3 = fopen("merged.txt", "w");
	if(f1 != NULL){
		while((ch=getc(f1))!=EOF){
			putc(ch, f3);
		}
	}
	fclose(f1);
	f2 = fopen("hello.txt", "r");
	if(f2 != NULL){
		while((ch=getc(f2))!=EOF){
			putc(ch, f3);
		}
	}
	fclose(f2);
	fclose(f3);
	f3 = fopen("merged.txt", "r");
	if(f3 != NULL){
		while((ch=getc(f3))!=EOF){
			printf("%c", ch);
		}
	}
	fclose(f3);
	return 0;
}