#include "main.h"

/**
 * _execve - execite fork
 * @s: path
 * @string: user input
 * Return: - pass or fail var
 */

int _execve(char *s, char **string)
{
pid_t chipid;
int status;

chipid = fork();

if (chipid == -1)
{
}
else if (chipid >  0)
{
wait(&status);
}
else if (chipid == 0)
{
if (s != NULL && string != NULL)
{
execve(s, string, environ);
}
}

if (WIFEXITED(status))
{
exit_status = WEXITSTATUS(status);
}
if (chipid != 0)
{
fflush(NULL);
}

return (0);
}
