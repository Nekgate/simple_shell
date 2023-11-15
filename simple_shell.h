#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int __printenv(void);
char *__mystrdup(char *string);
int readcmd(char *s, size_t __attribute__((unused))file_stream);
char *__mygetpath(char *cmd);
char *__mystrcat(char *dest, char *src);
int __mystrcmp(char *str1, char *str2);
char *__mystrcpy(char *dest, char *src);
int __mystrlen(char *s);
void print_not_found(char *cmd);
int call_command(char *cmd_arr[]);
char *__mygetenv(char *var);
int __mystrncmp(char *s1, char *s2, int n);
int handle_command_separator(char *cmd);
int myunsetenv(char *variable);
int mysetenv(char *variable, char *value, int overwrite);
int contains_commands_separator(char *cmd);
int readcmd_with_separator(char *s, size_t __attribute__((unused))file_stream);
#endif
