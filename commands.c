#include "main.h"

/**
 * command - parses commands
 * @string: user input
 * @s: path
 * @num: command sent count
 * Return: void
 */

int command(char **string, char **s, int num)
{
  int i = 0, x = 0;
  char *b = NULL;

if (_strcmp(string[0], "exit") == 0)
{
fflush(stdout);
x = 1;
}
else if (_strcmp(string[0], "env") == 0)
{
if (!environ)
{
x = 0;
}
else
{
while (environ[i])
{
if (environ[i] != NULL)
{
_printf("%s\n", environ[i]);
exit_status = 0;
i++;
}
x = 0;
}
}
exit_status = 0;
}
else
{
b = whichc(string, s, num);
if (b != NULL)
{
x = _execve(b, string);
}
free(b);
b = NULL;
}
return (x);
}

/**
 * spath - tokenizes the path
 *
 * Return: char**
 */

char **spath()
{
char **string = NULL;
char *path = NULL;

path = getpath();

string = parse(path);

return (string);
}

/**
 * whichc - finds where a command is
 * @string: user input
 * @s: path
 * @num: command sent num
 * Return: where command is
 */

char *whichc(char **string, char **s, int num)
{
int i = 0;
char *r = NULL;
char *comb2 = NULL;
int x = 0;

while (_strchr(string[i], '/', x) == 1)
{
if (_strchr(string[i], '/', x + 1) == -1)
{
_printf("%s: %d: %s: Permission denied\n", "./hsh", num, string[0]);
exit_status = 126;
return (r);
}
x++;
}

comb2 = _strdup(string[i]);

r = ret(r, comb2, s, string);

if (r == NULL)
{
_printf("%s: %d: %s: not found\n", "./hsh", num, string[0]);
exit_status = 127;
return (r);
}
return (r);
}

/**
 * ret - piece of whichc
 * @r: return val
 * @comb2: combination string
 * @s: user input
 * @string: path
 * Return: r
 */

char *ret(char *r, char *comb2, char **s, char **string)
{
int i = 0;
char *comb_1 = NULL;

for (i = 0; s[i] != NULL; i++)
{

if (comb2 == NULL)
{
comb_1 = str_concat(s[i], "/");
comb2 = str_concat(comb_1, string[0]);

free(comb_1);
comb_1 = NULL;
}

if (access(comb2, F_OK) == 0)
{
r = _strdup(comb2);
free(comb2);
comb2 = NULL;
break;
}
else
{
free(comb2);
comb2 = NULL;
}
}

return (r);
}
