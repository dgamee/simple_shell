#include "main.h"

/**
 * _getline - function that execute just like getline
 * @line: first argument passed.
 * @ptr: second argument passed in
 * Return: line read
 */

ssize_t _getline(char *line, size_t ptr)
{
	static char line_buffer[RANGE];
	static size_t size_buff;
	char *braking = NULL;
	ssize_t size = 0;
	static size_t ptrbuff;
	size_t length, copy;

	while (1)
	{
		if (ptrbuff >= size_buff)
		{
			size_buff = read(STDIN_FILENO, line_buffer, RANGE);
			if (size_buff <= 0)
				return (-1);
			ptrbuff = 0;
		}
		braking = memchr(line_buffer + ptrbuff, '\n', size_buff - ptrbuff);
		if (braking)
		{
			length = braking - (line_buffer + ptrbuff);
			if (length < ptr - 1)
			{
				memcpy(line, line_buffer + ptrbuff, length);
				line[length] = '\0';
				ptrbuff = braking - line_buffer + 1;
				size += length + 1;
				return (size);
			}
		}
		copy = (size_buff - ptrbuff < ptr - 1) ? size_buff - ptrbuff : ptr - 1;
		memcpy(line, line_buffer + ptrbuff, copy);
		ptrbuff += copy;
		line += copy;
		size += copy;
		if (copy < ptr - 1)
		{
			*line = '\0';
			return (size);
		}
	}
}
