#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Buffer sizes for read/write */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Command chaining types */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* Convert_number options */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* Use system getline() flag */
#define USE_GETLINE 0
#define USE_STRTOK 0

/* History file settings */
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - Linked singly list for strings
 * @num: Number of field
 * @str: A string
 * @next: Points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Contains pseudo-arguments to pass into a function,
 * allowing a uniform prototype for function pointer struct
 * @arg: A string generated from getline containing arguments
 * @fname: The program filename
 * @env_changed: Flag, set to 1 if environ was changed
 * @status: The return status of the last exec'd command
 * @cmd_buf: Address of pointer to cmd_buf, set to 1 if chaining
 * @cmd_buf_type: CMD_type, ||, &&, ;
 * @readfd: The file descriptor from which to read line input
 * @histcount: The history line number count
 * @env: Linked list, a local copy of environ
 * @argv: An array of strings generated from arg
 * @path: A string path for the current command
 * @argc: The argument count
 * @line_count: The error count
 * @err_num: The error code for exit()s
 * @linecount_flag: If set, count this line of input
 * @environ: Custom modified copy of environ from LL env
 * @history: The history node
 * @alias: The alias node
 */
typedef struct passinfo
{
	char **argv;
	char *arg;
	int argc;
	unsigned int line_count;
	char *path;
	int linecount_flag;
	char *fname;
	int err_num;
	list_t *history;
	list_t *alias;
	list_t *env;
	char **environ;
	int status;
	int env_changed;

	char **cmd_buf; /* cmd pointer; buffer chain, to manage memory */
	int cmd_buf_type; /* CMD_type, ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - Inside it related function & builtin string
 * @type: Builtin flag command 
 * @func: Function pointer
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* Function prototypes */

/* toem_shloop.c */
void fork_cmd(info_t *);
void find_cmd(info_t *);
int find_builtin(info_t *);
int hsh(info_t *, char **);

/* toem_parser.c */
char *find_path(info_t *, char *, char *);
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
int _putfd(char c, int fd);
int _eputchar(char);
int _putsfd(char *str, int fd);
void _eputs(char *);

/* toem_string.c */
int _strcmp(char *, char *);
int _strlen(char *);
char *_strcat(char *, char *);
char *starts_with(const char *, const char *);

/* toem_string1.c */
char *_strdup(const char *);
char *_strcpy(char *, char *);
int _putchar(char);
void _puts(char *);

/* toem_exits.c */
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char *_strncpy(char *, char *, int);

/* toem_tokenizer.c */
char **strtow2(char *, char);
char **strtow(char *, char *);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int _isalpha(int);
int interactive(info_t *);
int is_delim(char, char *);
int _atoi(char *);

/* toem_errors1.c */
int print_d(int, int);
void remove_comments(char *);
int _erratoi(char *);
void print_error(info_t *, char *);
char *convert_number(long int, int, int);

/* toem_builtin.c */
int _mycd(info_t *);
int _myexit(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myalias(info_t *);
int _myhistory(info_t *);

/* toem_getline.c */
int _getline(info_t *, char **, size_t *);
ssize_t get_input(info_t *);
void sigintHandler(int);

/* toem_getinfo.c */
void free_info(info_t *, int);
void set_info(info_t *, char **);
void clear_info(info_t *);

/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myunsetenv(info_t *);
int _mysetenv(info_t *);
int _myenv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */
char **get_environ(info_t *);
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);

/* toem_history.c */
int renumber_history(info_t *info);
int write_history(info_t *info);
char *get_history_file(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);

/* toem_lists.c */
void free_list(list_t **);
list_t *add_node_end(list_t **, const char *, int);
int delete_node_at_index(list_t **, unsigned int);
list_t *add_node(list_t **, const char *, int);
size_t print_list_str(const list_t *);

/* toem_lists1.c */
size_t print_list(const list_t *);
char **list_to_strings(list_t *);
size_t list_len(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int is_chain(info_t *, char *, size_t *);
int replace_alias(info_t *);
int replace_string(char **, char *);

#endif
