#include "monty.h"

/**
 * func_call - checks for appropriate function to perform;
 * checks the validity of the value
 * @tokens: argument that contains function string and value
 * @stack: pointer to head of stack
 * Return: nothing
 */
void func_call(char **tokens, stack_t **stack)
{
	instruction_t func[] = {
			{"pall", _pall},
			{"push", _push},
			{"pint", _pint},
			{NULL, NULL}
		};
	int idx;

	for (idx = 0; func[idx].opcode != NULL; idx++)
	{
		if (strcmp(tokens[0], func[idx].opcode) == 0)
		{
			if (strcmp(func[idx].opcode, "push") == 0)
			{
				func[idx].f(stack, line_number);
				check_valid_digit(tokens, stack);
				(*stack)->n = atoi(tokens[1]);
				break;

			}
			func[idx].f(stack, line_number);
			break;
		}
	}
	if (func[idx].opcode == NULL)
	{
		dprintf(STDERR_FILENO,
				"L%u: unknown instruction %s\n",
				line_number, tokens[0]);
		exit(EXIT_FAILURE);
	}
}
/**
 * check_valid_digit - checks if the value is a digit or
 * if a value is passed
 * @tokens: array od pointers to function opcode and value
 * @stack: pointer to head of stack linked list
 * Return: nothing
 */
void check_valid_digit(char **tokens, stack_t **stack)
{
	int idx = 0;

	if (!(tokens[1][idx]))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
				line_number);
		if (*stack)
			free_stack_list(stack);
		free(tokens);
		exit(EXIT_FAILURE);
	}

	for ( ; tokens[1][idx]; idx++)
	{
		if (tokens[1][idx] == '-' && idx == 0)
		{
			continue;
		}
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
