#include "shell.h"

/**
 * my_memset - Fill memory with a constant byte
 * @s: Pointer to the memory area
 * @b: Byte to fill the memory with
 * @n: Number of bytes to fill
 * Return: Pointer to the memory area (s)
 */
char *my_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return s;
}

/**
 * my_free - Release memory allocated for strings
 * @pp: Pointer to a string from Strings
 */
void my_free(char **pp)
{
char **a = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}

/**
 * my_realloc - Reallocate memory block
 * @ptr: Pointer to the old memory block
 * @old_size: Size of the old memory block in bytes
 * @new_size: Size of the new memory block in bytes
 *
 * Return: Pointer to the old memory block.
 */
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return malloc(new_size);
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return ptr;

p = malloc(new_size);
if (!p)
return NULL;

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
