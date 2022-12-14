#include "monty.h"

unsigned int line_number = 0;

/**
 * main - Entry point of program
 * @argc: number of command line arguments
 * @argv: array of pointers to command line arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fd;
	char *lineptr = NULL; /* store input from fd */
	size_t bufsize = 0;
	char **tokens = NULL; /* store tokenized value of line in file*/
	stack_t *head = NULL; /* pointer to head of list */

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r+");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
				argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&lineptr, &bufsize, fd)) != -1)
	{
		/* increment line number in file */
		line_number++;
		/* tokenize stored input */
		tokens = tokenize_line(lineptr);
		if (tokens)
		{
			/* call the function to run the monty code */
			func_call(tokens, &head);
			free(tokens);
		}
	}
	free(lineptr);
	free_stack_list(&head);
	fclose(fd);

	return (0);
}
/**
 * free_stack_list - frees a stack
 * @stack: pointer to head of stack to be freed
 * Return: nothing
 */
void free_stack_list(stack_t **stack)
{
	stack_t *temp, *prev;

	temp = *stack;

	while (temp)
	{
		if (temp->next == NULL)
		{
			free(temp);
			break;
		}
		prev = temp;
		temp = temp->next;
		free(prev);
	}
}
