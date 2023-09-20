#include "main.h"
/**
 * main - printing prompt
 * Return: 0
 */
int main(void)
{
	char *lineptr = NULL, *lineptr_cp = NULL, *word, **words;
	size_t n = 0;
	ssize_t nread;
	const char *dm = " \n";
	int nword, i;


		printf("shell $ ");
		nread = getline(&lineptr, &n, stdin);
		lineptr_cp = malloc(sizeof(char) * nread);
		if (lineptr_cp == NULL)
			return (-1);
		strcpy(lineptr_cp, lineptr);
		if (nread == -1)
			return (-1);

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

return (0);
}
