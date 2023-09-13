#include "main.h"

/**
 * _envpath - A program that get envnv varable
 * @str: an argument
 * Return: the path
 */

char *_envpath(const char *str)
{	
	int lenght = lenstr(str);
	char **envn = NULL;
	

	envn =  environ;
	while (*envn != NULL)
	{
		if (strncmp_made(str, *envn, lenght) == 0 && (*envn)[lenght] == '=')
		{
			return (&(*envn)[lenght + 1]);
		}
		envn++;
	}
	return (NULL);
}
