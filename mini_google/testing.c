#include <stdio.h>
#include <stdlib.h>
void main()
{
	FILE *f;
	char c;
	int k;
	f=fopen("file:///C:/Users/snehi/Documents/CSPP2/C_language/mini_google/test2.html","r");
	fseek(f,0,SEEK_END);
	k = ftell(f);
	printf("%d",k);
	fseek(f,0,SEEK_SET);
	while((c=fgetc(f))!=EOF)
	{
		printf("hey\n");
		printf("%c",c);
	}

}