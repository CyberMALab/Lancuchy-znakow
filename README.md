# Tablice znaków
## **Łańcuch znaków**
Tablice znaków, czyli tablica zmiennych typu *char,* w języku C wykorzystywana jest do przechowywania napisów jako zmiennych. Tablica taka jest nazywana łańcuchem. Deklaracja tablicy znaków nie różni się wiele od tablicy innych zmiennych, dochodzi jedynie dodatkowa opcja zainicjowania tablicy. Polega ona na zadeklarowaniu tablicy jak w przykładach (6.1) i (8.4), tyko zamiast otworzenia nawiasu klamrowego wypisujemy napis w cudzysłowie. Taki zapis spowoduje “wgranie” napisu do tablicy wraz ze znakiem pustym ‘\0’ na końcu tablicy.

*Przykład:*

*(9.0)* `char a[] = "ANSI C"; ` 

|A|N|S|I||C|\0|
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |

Warto zauważyć, że jeżeli długość tablicy będzie większa niż podany napis wszystkie nadmiarowe- puste elementy zostaną zakończone znakiem pustym (\0). Wynika to z właściwości zerowania niezainicjowanych elementów tablicy oraz faktem, że znak ten w kodzie ASCII jest właśnie równy 0.

*Przykład:*

*(9.1)* `char a[9] = "ANSI C"; `

|A|N|S|I||C|\0|\0|\0|
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |

## **Kody znaków [ASCII](https://pl.wikipedia.org/wiki/ASCII)**

![ASCII](https://e7.pngegg.com/pngimages/250/319/png-clipart-ascii-character-encoding-value-binary-code-miscellaneous-angle.png)

W każdym języku programowania wszystko jest przechowywane jako ciąg zer i jedynek, również znaki. Wynika z tego, że każdy znak ma swój numer, tylko jest on interpretowany w odpowiedni sposób przy wyświetlaniu. Inne operacje wykonywane na znakach są wykonywane jednak pod względem technicznym jako liczby. Takie przypisanie znakowi jego numeru jest nazywane formatem zapisu znaków. W języku C domyślnie używane są znaki w formacie ASCII. Wynika z tego, że znak ‘a’ przechowywany w zmiennej typu *char* jest w praktyce liczbą całkowitą równą 97. Mając tą wiedzę, operacje możemy tworzyć ciekawe rozwiązania korzystając ze zmiennych typu znakowego jako zmiennych typu całkowitego.

*Przykład (9.2) wypisywanie kodów ASCII z przedziału 32-126*

``` 
#include <stdio.h> 

int main() { 
 for (int n =32; n<127;n++){ 
     printf("Code: %3d; char:%c\n", n, n); 
 } 
 return 0; 
}

```

## **Operacje wejścia/wyjścia na łańcuchach znaków**
Istnieje kilka sposobów, aby taki napis wczytać od użytkownika i w sposób szybki i intuicyjny zapisać go jako łańcuch. Pierwszym z nich jest użycie specjalnego kodu formatującego odpowiadającemu łańcuchowi „%s” oraz funkcji *scanf.* Pamiętamy, że funkcja *scanf* przyjmuje za parametr adres zmiennej, w której chcemy zapisać daną. Nie inaczej jest w przypadku łańcucha znaków, tylko w tym przypadku musimy wskazać adres pierwszego elementu tablicy, do której chcemy zapisać łańcuch. Można to uzyskać tak jak na przykładzie (7.3). Istnieje jednak jedna pewna właściwość tablic, której kwestia nie była poruszania wcześniej, i która będzie rozwinięta bardziej w rozdziale o wskaźnikach. Właściwość ta polega na tym, że nazwa tablicy (bez nawiasów kwadratowych), jest równoznaczna ze wskazaniem adresu pierwszego elementu tablicy, zatem ten sam efekt co w  (7.3) można uzyskać poprzez zapis (7.4). Innym sposobem jest użycie funkcji *gets.* Funkcja *gets* za argument przyjmuje wskaźnik na pierwszy element ciągu znaków (7.5). Te funkcje różnią się w działaniu. Pierwsza pobierze ciąg znaków do momentu napotkania pierwszego znaku spacji, natomiast funkcja *gets* pobierze cały ciąg znaków razem z występującymi spacjami.

*Przykłady wczytywanie łańcucha znaków.*

*(9.3)* `scanf(" %s",&napis[0]); `

*(9.4)* ` scanf(" %s",napis); `

*(9.5)* `gets(napis);`


Łańcuch znaków można wypisać za pomocą funkcji *printf* za pomocą dwóch sposobów. Pierwszym z nich jest wypisanie łańcucha z użyciem kodu formatującego „%s”.  Używa się go wewnątrz tekstu sterującego funkcji *printf,* jednak w tym wypadku podajemy również wskaźnik na pierwszy element tablicy znaków (7.5), tak jak jest to w przypadku *scanf*. Drugim sposobem jest użycie łańcucha znaków jako kodu formatującego funkcji *printf.* W tym celu w miejscu argumentu podaje się wskaźnik na pierwszy element łańcucha znaków (7.6).

*Przykłady wypisania łańcucha znaków za pomocą printf.*

*(9.6)* `printf(" %s",napis); `

*(9.7)* `printf(napis);`

## **Przydatne funkcje z bibliotek *string.h* oraz *ctype.h***
W kontekście łańcuchów znaków i operacjach na nich istotne jest wspomnienie o dwóch bardzo przydatnych bibliotekach. Pierwszą z nich jest biblioteka *ctype.h,* służąca do* obsługi znaków. Drugą natomiast *string.h*, które służby do obsługi całych łańcuchów znaków.

Przydatne funkcje z biblioteki *ctype.h*
|funkcja|Opis|Zwracana wartość|
| :- | :- | :- |
|`int isalnum(int c) `|Czy znak jest literą lub cyfrą?|Jeżeli tak zwraca 1, jeżeli nie zwraca 0.|
|`int isalpha(int c) `|Czy znak jest literą?|Jeżeli tak zwraca 1, jeżeli nie zwraca 0.|
|`int iscntrl(int c) `|Czy znak jest znakiem sterującym?|Jeżeli tak zwraca 1, jeżeli nie zwraca 0.|
|`int isdigit(int c) `|Czy znak jest cyfrą?|Jeżeli tak zwraca 1, jeżeli nie zwraca 0.|
|`int islower(int c) `|Czy znak jest małą literą?|Jeżeli tak zwraca 1, jeżeli nie zwraca 0.|
|`int isupper(int c) `|Czy znak jest wielką literą?|Jeżeli tak zwraca 1, jeżeli nie zwraca 0.|
|`int isprint(int c) `|Czy znak jest znakiem drukowalnym?|Jeżeli tak zwraca 1, jeżeli nie zwraca 0.|
|`int isspace(int c) `|Czy znak jest znakiem separującym?|Jeżeli tak zwraca 1, jeżeli nie zwraca 0.|
|`int toupper(int c) `|Zmienia znak na wielką literę|Zwraca kod ASCII znaku |
|`int tolower(int c) `|Zmienia znak na małą literę|Zwraca kod ASCII znaku|

*Przykład (9.8) użycie funkcji z biblioteki ctype.h*
```
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

```


Przydatne funkcje z biblioteki *string.h*

|funkcja|Opis|Zwracana wartość|
| :- | :- | :- |
|`char* strcat(char* a, const char* b)`|Scala łańcuch **a** z łańcuchem **b** w jeden i zapisuje wartość scalenia w łańcuchu **a**|Zwraca wskaźnik na łańcuch **a**|
|`size_t strlen(const char* a)`|Sprawdza długość łańcucha **a**|Zwraca długość łańcucha **a**|
|`char* strcpy(char* a, const char* b)`|Kopiuje łańcuch **b** z do łańcucha **a**|Zwraca wskaźnik na łańcuch **a**|
|`int strcmp(const char* a, const char* b)`|Porównuje łańcuch **a** z łańcuchem **b.**|Zwraca wartość 0, kiedy obydwa łańcuchy są takie same lub różną od 0, kiedy są różne.|

*Przykład (9.9) użycie funkcji z biblioteki string.h*

```
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

```

## **Zadania do samodzielnego wykonania:**
1. Napisz program, który poprosi użytkownika o imię, a następnie wypisze to imię tak, aby tyko pierwsza litera była wielka
   1. Przy użyciu biblioteki ctype.h
   1. Bez użycia biblioteki ctype.h (używając kodów znaków ASCII)
1. Napisz program zliczający liczbę poszczególnych liter w ciągu znaków podanym przez użytkownika. Program wyświetla liczbę wystąpień znaków które przynajmniej raz wystąpiły w podanym tekście.
1. Napisz program, który sprawdza czy dwa wyrazy podane przez użytkownika są nawzajem anagramem.
1. Napisz program, który sprawdzi czy podany przez użytkownika ciąg znaków jest liczbą całkowitą (użyj kodów znaków ASCII), a następnie przekonwertuje ciąg znaków w liczbę tylu *int*.
1. Zaimplementuj program z menu szyfrujący oraz deszyfrujący szyfrem cezara. 
   1. Szyfr cezara polega na przestawieniu każdej litery alfabetu o trzy litery w przód (np. a->c). 
   1. Wprowadź opcję dodania klucza szyfrującego, który wskazywać będzie o ile liter alfabetu dana liczba będzie przesuwana (np. klucz: 123 słowo: abcbd zaszyfrowane: bdfcf).
1. Napisz program, który sprawdza czy dwie podane przez użytkownika liczby są lustrzane (np. 41 i 14).
1. Napisz program, który zamienia zmienną typu *int* na łańcuch znaków, tworzący tą liczbę (przy użyciu tablicy kodów ASCII).
1. Napisz program, który sprawdza czy liczba podana przez użytkownika jest doskonała I rzędu lub doskonała II rzędu. Liczba doskonała I rzędu to taka której suma cyfr jest równa liczbie, natomiast doskonała II rzędu to iloczyn cyfr jest równy liczbie.


***
[Poprzednia część](https://github.com/CyberMALab/Tablice-jednowymiarowe-statyczne.git) | [Spis treści](https://github.com/CyberMALab/Wprowadzenie-do-programowania-w-j-zyku-ANSI-C.git) | [Następna część](https://github.com/CyberMALab/Tablice-wielowymiarowe-statyczne.git)
***
&copy; Cyberspace Modelling and Analysis Laboratory

