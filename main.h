#ifndef _MAIN_H_
#define _MAIN_H_

/* includes libraries */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* Global var */

int exit_status;

extern char **environ;

/* Prototypes */

void loop(char **s);
void loop_2(int gline, char **s, char *buff, char *copy);
void loop_3(char **s, int gline, char *buff, char **string, char *copy);
void flagcheck(char *buff, char *copy);
int command(char **string, char **s, int num);
int _execve(char *s, char **string);
char *ret(char *r, char *comb2, char **s, char **string);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strlen(char *s);
char *_strstr(char *hay, char *needle);
char *str_concat(char *s1, char *s2);
int _strchr(char *s, char c, int i);
void freemem(char **s);

char *getpath();
char **spath();
char **parse(char *s);
char *whichc(char **string, char **s, int num);

int probandofork(void);
int _fork(void);

/* printf */

int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list c);
int print_s(va_list s);
int print_di(va_list di);
int (*get_print_func(const char *format))(va_list);
typedef struct printformat
{
char *theC;
int (*z)(va_list);
} form;

/* error handle and Printer */

void print_error(char *line, int c, char **argv);

/* Command parser and extractor */

int path_cmd(char **line);
int check_cmd(char **cmd, char *input, int c, char **argv);

#endif
