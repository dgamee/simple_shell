#include "main.h"

/**
  * command_handle - A program that handles commands passed to shell
  * @linestr: getline argument pass for execute
  */

void command_handle(char *linestr)
	{
	char **lineargs = NULL, *commmandpath = NULL;
	int status_exit;

	if (linestr[0] != '\0')
	{
		lineargs = split_str(linestr, " \n");
		if (!lineargs)
		{
			perror("Error tokenizing command");
			return;
		}

		if (cmpstr(linestr, "exit") == 0)
		{
		if (lineargs[1])
		{	status_exit = atoi(lineargs[1]);
			free_str(lineargs);
			exit(status_exit);
		}
		else
		{	free_str(lineargs);
			exit(0);
		}
		}

		if (cmpstr(linestr, "env") == 0)
		{	execute_env();
			free_str(lineargs);
			return;
		}
		commmandpath = env_location(lineargs[0]);
		if (commmandpath == NULL)
		{	perror("Command not found");
			free_str(lineargs);
		}
		else
		{	commandfork(lineargs);
			free_str(lineargs);
		}
		}
}


/**
 * execute_env - A program that executes the ennv variable
 * Return: nothing
 *
 */

void execute_env(void)
{
	char **envn = environ;

	while (*envn)
	{
		write(STDOUT_FILENO, *envn, lenstr(*envn));
		write(STDOUT_FILENO, "\n", 1);
		envn++;
	}
}
