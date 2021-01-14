#include <stdio.h>
#include <string.h>

//for loop lowercase
void main ()
{
	int i;
	char str1[26];
	for(i = 0; i < 26; i++)
	{
		char c = 'a' + i;
		str1[i] = c;
	}

//string constant initializer lowercase
char str2[] = "abcdefghijklmnopqrstuvwxyz";

//compare strings -- check if they are equal
if (strcmp(str1, str2) == 0)
	printf("the strings are identical\n");
else
	printf("the strings are different\n");

//change to uppercase
for(int i = 0; i< strlen(str1); i++)
{
	str1[i] -= 32;
}

//compare strings -- check if they are different
if (strcmp(str1, str2) == 0)
        printf("the strings are identical\n");
else
        printf("the strings are different\n");

//lower and upper case string
char str3[52];
strcpy(str3, str1);
strcat(str3, str2);

//print all three strings
printf("String 1 - %s\nString 2 - %s\nString 3 - %s\n", str1, str2, str3);

}
