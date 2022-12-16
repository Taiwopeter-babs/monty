#include "monty.h"
/**
 * check_valid_digit - checks if the value is a digit or
 * if a value is passed
 * @tokens: array of pointers to function opcode and value
 * @stack: pointer to head of stack linked list
 * Return: nothing
 */
void check_valid_digit(char **tokens, stack_t **stack)
{
	int idx;

	if (!(tokens[1]))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
				line_number);
		if (*stack)
			free_stack_list(stack);
		free(tokens);
		exit(EXIT_FAILURE);
	}
	for (idx = 0; tokens[1][idx]; idx++)
	{
		if (tokens[1][idx] == '-' && idx == 0)
			continue;
		if (isdigit(tokens[1][idx]) == 0)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
					line_number);
			if (*stack)
				free_stack_list(stack);
			free(tokens);
			exit(EXIT_FAILURE);
		}
	}
}
