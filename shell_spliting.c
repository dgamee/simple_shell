#include "main.h"

/**
 * split_str- program tha splits string into two
 * @str: string to be tokenalized
 * @delim: slipting params
 * Return: returns the slipted string
 */

char **split_str(char *str, const char *delim)
{
	
	int tokcount = 0, i;
	char *argtokcpy = _strdup(str);
	char **args = NULL;
	char *argtoken;

	argtoken = strtok(str, delim);
	while (argtoken != NULL)
	{
		tokcount++;
		argtoken = strtok(NULL, delim);
	}
	args = (char **)malloc(sizeof(char *) * (tokcount + 1));
	if (args == NULL)
	{
		perror("allocated memory failled");
		exit(98);
	}
	argtoken = strtok(argtokcpy, delim);
	for (i = 0; argtoken != NULL; i++)
	{
		args[i] = _strdup(argtoken);
		argtoken = strtok(NULL, delim);
	}
args[tokcount] = NULL;
	free(argtokcpy);
	return (args);
}
