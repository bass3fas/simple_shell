#include "shell.h"
/**
 * prompt - prints prompt shell
 * @av: args
 * @env: environment
 */
void prompt(char **av, char **env)
{
	char *lineptr = NULL, **argv = NULL, *command = NULL;
	size_t n = 0;
	int status;
	ssize_t num_char;
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
