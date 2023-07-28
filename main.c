#include "shell.h"

int main(int argc, char **argv)
{
info_t info[] = { INFO_INIT };
int file_descriptor = 2;

file_descriptor = file_descriptor + 3;

if (argc == 2)
{
file_descriptor = open(argv[1], O_RDONLY);
if (file_descriptor == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(argv[0]);
_eputs(": 0: Can't open ");
_eputs(argv[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
exit(127);
}
return EXIT_FAILURE;
}
info->readfd = file_descriptor;
}
populate_env_list(info);
read_history(info);
hsh(info, argv);
return EXIT_SUCCESS;
}
