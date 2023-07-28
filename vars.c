#include "shell.h"

/**
 * is_chain - test if current char of buffer is a delim chain
 * @info: struct parameter 
 * @buf: Buffer char 
 * @p: Current position of buffer address 
 *
 * Return: If delim chain 1, If other 0 
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - based on last status check will continue chain
  * @info: struct parameter 
 * @buf: Buffer char 
 * @p: Current position of buffer address
 * @i: buffer position starting
 * @len: buffer size
 *
 * Return: type void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - aliases replaced inside string tokenized
 * @info: struct parameter
 *
 * Return: When replaced 1, If other 0
 */
int replace_alias(info_t *info)
{
	int itr;
	list_t *node;
	char *pointer;

	for (itr = 0; itr alias, info->argv[0], '=')
		if (!node)
			return (0);
		free(info->argv[0]);
		pointer = _strchr(node->str, '=');
		if (!pointer)
			return (0);
		pointer = _strdup(pointer + 1);
		if (!pointer)
			return (0);
		info->argv[0] = pointer;
	}
	return (1);
}

/**
 * replace_string - String replacing
 * @old: old or previous string address 
 * @new: The new string
 *
 * Return: When replaced 1, If other 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
