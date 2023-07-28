#include "shell.h"

/**
 * _strlen - return string size 
 * @s: check the string size
 *
 * Return: integ the string size
 */
int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcmp - perform lexical graphic compar for 2 strings.
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: -ve when s1 < s2, +ve when s1 > s2, 0 when s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else
		return (s1[i] < s2[i] ? -1 : 1);
}

/**
 * starts_with - haystack check when needle start
 * @haystack: search string
 * @needle: look for substring 
 *
 * Return: upcoming char of haystack address or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	int i = 0;

	while (needle[i] != '\0')
		if (needle[i++] != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
