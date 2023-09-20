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
			char *lineptr = NULL, *lineptr_cp = NULL;
			char *word, **words;
			size_t n = 0;
			ssize_t nread;
			const char *dm = " \n";
			int nword, i;

			printf("shell $ ");
			nread = getline(&lineptr, &n, stdin);
			if (nread == -1 || nread == 0)
			{
				printf("Exit..\n");
				free(lineptr);
				exit(EXIT_SUCCESS);
			}
			lineptr_cp = malloc(sizeof(char) * nread);
			if (lineptr_cp == NULL)
			{
				perror("malloc");
				free(lineptr_cp);
				exit(EXIT_FAILURE);
			}
			strcpy(lineptr_cp, lineptr);
			word = strtok(lineptr, dm);
			for (nword = 1; word != NULL; nword++)
				word = strtok(NULL, dm);
			words = malloc(sizeof(char *) * (nword + 1));
			word = strtok(lineptr_cp, dm);
			for (i = 0; word != NULL; i++)
			{
				words[i] = malloc(sizeof(char) * strlen(word));
				strcpy(words[i], word);
				word = strtok(NULL, dm);
			}
			words[i] = NULL;

			exec(words);


			free(words);
			free(lineptr);
			free(lineptr_cp);

		}
		else
			wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
			break;
	}
	return (0);
}
