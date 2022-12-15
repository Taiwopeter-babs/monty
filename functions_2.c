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
/**
 * _pstr - prints the data on the top of the stack as ascii
 * @stack: pointer to head/top of linked list/stack
 * @line_number: see _push for reference (unused argument)
 * Return: nothing
 */
void _pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack))
	{
		dprintf(STDOUT_FILENO, "\n");
	}
	temp = *stack;

	while (temp)
	{
		if (temp->n == 0 || temp->n < 0 || temp->n > 127)
		{
			break;
		}
		dprintf(STDOUT_FILENO, "%c", temp->n);
		temp = temp->next;
	}
	dprintf(STDOUT_FILENO, "\n");
}
/**
 * _rotl - rotates the stack to the left; the top node
 * becomes the last node, and the second top becomes top
 * @stack: pointer to head/top of linked list/stack
 * @line_number: see _push for reference (unused argument)
 * Return: nothing
 */
void _rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp, *curr, *new_head, *new_last;
	int count = 0;

	temp = *stack;
	curr = *stack;
	new_last = *stack;
	new_head = (*stack)->next;

	while (temp)
	{
		count++;
		temp = temp->next;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new_last;
	new_last->next = NULL;
	new_last->prev = curr;
	*stack = new_head;
}
