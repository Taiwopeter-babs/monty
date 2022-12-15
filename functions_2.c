#include "monty.h"
/**
 * _pchar - prints the data on the top of the stack as ascii
 * @stack: pointer to head/top of linked list/stack
 * @line_number: see _push for reference (unused argument)
 * Return: nothing
 */
void _pchar(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	if (temp->n < 0 || temp->n > 127)
	{
		dprintf(STDERR_FILENO,
				"L%u: can't pchar, value out of range\n",
				line_number);
		free_stack_list(stack);
		exit(EXIT_FAILURE);
	}
	dprintf(STDOUT_FILENO, "%c\n", temp->n);
}
