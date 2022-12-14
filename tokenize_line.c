#include "monty.h"

/**
 * tokenize_line - splits the string into tokens
 * @str: string to split
 *
 * Return: tokenized string, otherwise NULL
 */
char **tokenize_line(char *str)
{
	char **buffer;
	char *token;
	char *delim = " \t\r\n";
	int idx;

	token = strtok(str, delim);
	if (token == NULL)
		return (NULL);

	buffer = malloc(sizeof(char **) * 3); /* given that tokens are < 3 */
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	idx = 0;
	while (token != NULL)
	{
		if (idx < 3)
			buffer[idx] = token;
		token = strtok(NULL, delim);
		idx++;
	}

	buffer[2] = NULL;
	return (buffer);

}
