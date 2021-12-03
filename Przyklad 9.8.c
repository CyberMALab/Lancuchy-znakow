#include <stdio.h>
#include <ctype.h>

int main() {
	
	char a;
	printf("Podaj znak z klawiatury:");
	scanf(" %c", &a);
	if(isalpha(a))
	{
		printf("Znak jest litera\n");
		if(islower(a))
		{
			printf("Zamieniam znak na wielka litere\n");
			a=toupper(a);
		}
		else
		{
			printf("Zamieniam znak na mala litere\n");
			a=tolower(a);
		}
	
	}
	if(isdigit(a))
	{
		printf("Znak jest cyfra\n");
	}
	printf("Znak po zmianach : %c",a);
	return 0;
}

