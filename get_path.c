#include "main.h"
/**
 * get_path - get's the path of the written command
 * @command: command to search for it's path
 * Return: path of command
 */
char *get_path(char *command)
{
	char *path, *path_cp, *token, *full_path;
	int len, dir_ln;
	struct stat buff;

	path = getenv("PATH");
	if (path)
	{
		path_cp = strdup(path);
		len = strlen(command);
		token = strtok(path_cp, ":");
		while (token != NULL)
		{
			dir_ln = strlen(token);
			full_path = malloc(len + dir_ln + 2);
			strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, command);
			strcat(full_path, "\0");

			if (stat(full_path, &buff) == 0)
			{
				free(path_cp);
				return (full_path);
			}
			else
			{
				free(full_path);
				token = strtok(NULL, ":");
			}
		}
		free(path_cp);
		if (stat(command, &buff) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
