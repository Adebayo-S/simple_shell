#include "shell.h"

/**
 * _strcmp - comparing strings
 * @s1 : var pointer
 * @s2 : pointer
 * 
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	//Checking for null and then comparing
	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
		;
		return (s1[i] - s2[i]);
}
