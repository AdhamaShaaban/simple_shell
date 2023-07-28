#include "shell.h"

/**
 **_strncpy - String copies
 *@dest: String copied to destination
 *@src: String source
 *@n: num of copied characters
 *Return: String concatenat
 */
char *_strncpy(char *destination, const char *source, int num_of_chars)
{
	int i, j;
	char *str_ptr = destination;

	i = 0;
	while (source[i] != '\0' && i < num_of_chars - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < num_of_chars)
	{
		j = i;
		while (j < num_of_chars)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (str_ptr);
}

/**
 **_strncat - dual string concat
 *@dest: 1st string
 *@src: 2nd string
 *@n: Num of bytes to be used in max
 *Return: String concatenat
 */
char *_strncat(char *destination, const char *source, int num_of_chars)
{
	int i, j;
	char *str_ptr = destination;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (source[j] != '\0' && j < num_of_chars)
	{
		destination[i] = source[j];
		i++;
		j++;
	}
	if (j < num_of_chars)
		destination[i] = '\0';
	return (str_ptr);
}

/**
 **_strchr - find a string charact
 *@s: parse the string
 *@c: char looking for
 *Return: (s) pointer to area of the memory s
 */
char *_strchr(char *str, char character)
{
	do {
		if (*str == character)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
