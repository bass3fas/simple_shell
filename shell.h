#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
void prompt(char **av, char **env);
char **words(char *lineptr, ssize_t nread);
char *get_path(char *command);






#endif
