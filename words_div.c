#include "main.h"
/**
 * words_div - executing the command passed
 * @lineptr: line read from prompt
 * @nread: status of line read
 * Return: words of the line
 */
char **words_div(char *lineptr, ssize_t nread)
{
	char *lineptr_cp = NULL;
	char *word, **words;
	const char *dm = " \n";
	int nword, i;

	lineptr_cp = malloc(sizeof(char) * nread);
	if (lineptr_cp == NULL)
	{
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
	free(lineptr_cp);
	return (words);
}
