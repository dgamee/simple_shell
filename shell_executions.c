#include "main.h"

/**
 * shell_exec - A function that executes command
 * @argstr: takes in command
 * Return: void
 */

void shell_exec(char **argstr)
{
	char *command = NULL;
	char *str_args = NULL;

	str_args = argstr[0];
	command = env_location(str_args);

	if (execve(command, argstr, NULL) == -1)
	{
		perror("command not found");
		exit(1);
	}
}
