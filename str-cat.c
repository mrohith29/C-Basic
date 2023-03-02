#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char str1[100], str2[100];
	scanf("%s %s", str1, str2);
	strcat(str1, " ");
	strcat(str1, str2);
	printf("%s", str1);
	return 0;
}