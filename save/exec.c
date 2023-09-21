#include "main.h"
/**
 * exec - execute commands
 * @words: commands array
 */
void exec(char **words)
{
	char *command = NULL, *real_command;

	if (words != NULL)
	{
		command = words[0];
		real_command = get_path(command);
		if (execve(real_command, words, NULL) == -1)
			perror("Error:");
	}
	else
		exit(EXIT_FAILURE);
}
