#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
void exec(char **words);
char *get_path( char *command);
char **div_words(int nword, char *dm, char *line_ptr, char *lineptr_cp);


#endif
