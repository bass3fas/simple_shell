#include "shell.h"
/**
 * prompt - prints prompt shell
 * @av: args
 * @env: environment
 */
void prompt(char **av, char **env)
{
	char *lineptr = NULL;
	size_t n =0;
	int i = 0, status;
	ssize_t num_char;
	char **argv = NULL;
	char *command = NULL;
	pid_t child_pid;

	while (1)
	{
		printf("cisfun$ ");
		num_char = getline(&lineptr, &n, stdin);
		if (num_char == -1)
		{
			free(lineptr);
			printf("\n");
			exit(EXIT_FAILURE);
		}
		while (lineptr[i])
		{
			if (lineptr[i] == '\n')
				lineptr[i] = 0;
			i++;
			}
		argv = words(lineptr, num_char);
		command = get_path(argv[0]);
		child_pid = fork();
		if (child_pid == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
			break;
		}
		else if (child_pid == 0)
		{
			if (execve(command, argv, env) == -1)
				printf("%s: No such file or directory\n",
				       av[0]);
		}
		else
			wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
			break;
	}
}
