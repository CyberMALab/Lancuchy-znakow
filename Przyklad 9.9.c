#include <stdio.h>
#include <string.h>

int main() {
	
	char a[25]="Hello ";
	char b[25]="World!";
	char c[25];
	char d[25];
	strcpy(d,a);
	strcat(a,b);
	strcpy(c,a);
	if(strcmp(a,c)==0)
	{
		printf("Napis \"%s\" oraz \"%s\" sa takie same!\"\n",a,c);
	}
	else
	{
		printf("Napis \"%s\" oraz \"%s\" nie sa takie same!\"\n",a,c);
	}
	printf("a[]=\"%s\" dlugosc: %d\n",a,strlen(a));
	printf("b[]=\"%s\" dlugosc: %d\n",b,strlen(b));
	printf("c[]=\"%s\" dlugosc: %d\n",c,strlen(c));
	printf("d[]=\"%s\" dlugosc: %d\n",d,strlen(d));
	return 0;
}

