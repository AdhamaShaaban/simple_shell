#include "shell.h"
/**
list_len - calculates the length of a linked list
@h: pointer to the first node
Return: size of the list
*/
size_t list_len(const list_t *h)
{
size_t count = 0;
while (h)
{
h = h->next;
count++;
}
return (count);
}
/**
list_to_strings - converts a linked list to an array of strings
@head: pointer to the first node
Return: array of strings
*/
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t count = list_len(head);
char **strs;
char *str;
if (!head || count == 0)
return (NULL);
strs = malloc(sizeof(char *) * (count + 1));
if (!strs)
return (NULL);
for (count = 0; node; node = node->next, count++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (size_t i = 0; i < count; i++)
free(strs[i]);
free(strs);
return (NULL);
}
Copy

 str = _strcpy(str, node->str);
 strs[count] = str;
}
strs[count] = NULL;
return (strs);
}
/**
print_list - prints all elements of a linked list
@h: pointer to the first node
Return: size of the list
*/
size_t print_list(const list_t *h)
{
size_t count = 0;
while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
count++;
}
return (count);
}
/**
node_starts_with - finds the node whose string starts with a given prefix
@node: pointer to the head of the list
@prefix: string to match
@c: the next character after prefix to match
Return: matching node or NULL
*/
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *p = NULL;
while (node)
{
p = starts_with(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}
/**
get_node_index - gets the index of a node in the list
@head: pointer to the head of the list
@node: pointer to the node
Return: index of the node or -1
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t index = 0;
while (head)
{
if (head == node)
return (index);
head = head->next;
index++;
}
return (-1);
}
