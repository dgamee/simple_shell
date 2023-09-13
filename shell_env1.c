#include "main.h"

/**
 * evn_location - a program the describe to the path 
 * @command_args: agument 
 *
 * Return: returns the path location
 */

char *env_location(char *command_args)
{
	 
	int len1, len2;
	char *envpath, *copypath = NULL, *token, *filepath = NULL;
	struct stat str;

	envpath = _envpath("PATH");
	if (envpath)
	{
		copypath = _strdup(envpath);
		if (!copypath)
			return (NULL);
		len1 = lenstr(command_args);
		token = strtok(copypath, ":");
		while (token != NULL)
		{
			len2 = lenstr(token);
			filepath = malloc(len1 + len2 + 2);
			cpystr(filepath, token);
			catstr(filepath, "/");
			catstr(filepath, command_args);
			catstr(filepath, "\0");
			if (stat(filepath, &str) == 0)
			{
				free(copypath);
				return (filepath);
			}
			else
			{
				free(filepath);
				token = strtok(NULL, ":");
			}
		}
		free(copypath);
		if (stat(command_args, &str) == 0)
			return (command_args);
		return (NULL);
	}
	return (NULL);
}
