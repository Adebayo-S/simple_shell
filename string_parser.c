#include <stdio.h>
#include "shell.h"

/**
 * get_toks - get tokens from input
 *
 * @args: input string.
 * @delim: delimiter.
 * Return: a vector of the splited input strings.
 */
char **get_toks(char *args, char *delimiter)
{
	int i = 0;
	char *token;
	char **output = malloc(MAXARGS * sizeof(char *));
	if (output == NULL)
		exit(EXIT_FAILURE);

	token = strtok(args, delimiter);
	while (token != NULL)
	{
		output[i] = token;
		i++;
		if (i == MAXARGS)
			output = _realloc(output, i, i * sizeof(char *));
			if (output == NULL)
				exit(EXIT_FAILURE);
		token = strtok(NULL, delimiter);
	}
	output[i] = NULL;

	return (output);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}

/**
 * str_reverse - reverses a string.
 * @s: input string.
 * Return: no return.
 */
void str_reverse(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}

/**
 * _strcmp - comparing strings
 *
 * @str_a: first string to compare
 * @str_b: second string to compare
 *
 * Return: Always 0.
 */
int _strcmp(char *str_a, char *str_b)
{
	int i;

	for (i = 0; str_a[i] != '\0' && str_b[i] != '\0'; i++)
	{
		if (str_a[i] != str_b[i])
			return (str_a[i] - str_b[i]);
	}
	return (0);
}

/**
 * *_strcat - concatenates two strings
 * @dest: pointer destination
 * @src: pointer source
 * Return: address of dest
 */

char *_strcat(char *dest, char *src)
{
	int a = -1, i;
	for (i = 0; dest[i] != '\0'; i++)
	;

	do {
		a++;
		dest[i] = src[a];
		i++;
	} while (src[a] != '\0');

	return (dest);
}

/**
 * _strlen - determine the length of a string
 * @s: pointer to the string to check
 * Return: length of the string check
*/
int _strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;

	return (i);
}

/**
 * _strdup - Returns a pointer to a newly-allocated space in memory
 *           containing a copy of the string given as parameter.
 * @str: The string to be copied.
 *
 * Return: If str == NULL or insufficient memory is available - NULL.
 *         Otherwise - a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
	unsigned int i;
	unsigned int strlen;
	char *cpy_str;

	if (str == NULL)
		return (NULL);

	for (strlen = 0; str[strlen] != '\0'; strlen++)
		;

	cpy_str = malloc((strlen + 1) * sizeof(char));

	if (cpy_str == NULL)
		return (NULL);

	for (i = 0; i < strlen; i++)
	{
		cpy_str[i] = str[i];
	}

	cpy_str[strlen] = '\0';

	return (cpy_str);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */

int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';

			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;

			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}
