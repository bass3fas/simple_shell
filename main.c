#include "shell.h"
/**
 * main - simple shell prompt
 * @ac: no of args
 * @av: args
 * @env: environment
 * Return: sucess
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);
	return (0);
}
