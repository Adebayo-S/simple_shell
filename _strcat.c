#include "shell.h"
/**
 * *_strcat - concatenates two strings
 * @dest: pointer destination
 * @src: pointer source
 * Return: pointer to string dest
*/

char *_strcat(char *dest, char *src)
{
int a = 0, i;

for (i = 0; dest[i] != '\0'; i++)
	;
while (src[a] != '\0')
{
	dest[a + i] = src[a];
	a++
}
return (dest);
}
