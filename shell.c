#include "main.h"

/**
  * main - program that thats in args and  execute command
  * 
  *
  * Return: 0 on success
  */

int main(void)
{
	ssize_t len;
    char linestr[100];

	while (1)
	{

	write(STDIN_FILENO, "$ ", 3);

	len = _getline(linestr, sizeof(linestr));

	if (len == -1)
	{
		break;
	}

	if (linestr[len - 1] == '\n')
		linestr[len - 1] = '\0';

	command_handle(linestr);
	}
	return (0);
}



/**
  * free_str - program that free allocated space
  * @argstr: argument
  */

void free_str(char **strargs)
{
	int j;

	for (j = 0; strargs[j] != NULL; j++)
	{
		free(strargs[j]);
	}
	free(strargs);
}
 
/**
  * commandfork - program that duplicate process
  * @strargs: take in argument
  */


void commandfork(char **strargs)
{
	pid_t first = fork();

	if (first == -1)
	{
		perror("error the process fail");
		exit(1);
	}
	if (first == 0)
	{
		shell_exec(strargs);
		exit(0);
	}
	else
	{
		wait(NULL);
	}

}
