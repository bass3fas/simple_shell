#include "main.h"
/**
 * main - printing prompt
 * Return: 0
 */
int main(void)
{
	while (1)
	{
		pid_t child_pid;
		int status;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			char *lineptr = NULL, **words;
			size_t n = 0;
			ssize_t nread;

			printf("#shell$ ");
			nread = getline(&lineptr, &n, stdin);
			if (nread == -1)
			{
				printf("\n");
				free(lineptr);
				exit(EXIT_FAILURE);
			}

			words = words_div(lineptr, nread);
			exec(words);


			free(words);
			free(lineptr);

		}
		else
			wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
			break;
	}
	return (0);
}
