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
		return;
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

	if (!stack || !(*stack))
		return;

	temp = *stack;
	curr = *stack;
	new_last = *stack;
	if ((*stack)->next)
		new_head = (*stack)->next; /* set to second node on stack */

	while (temp)
	{
		count++; /* count the nodes on the stack */
		temp = temp->next;
	}
	if (count == 1) /* single-node stack cannot be rotated */
		return;
	while (curr->next) /* move this to end of list/stack */
		curr = curr->next;
	curr->next = new_last; /* set last-node next to top of stack */
	new_last->next = NULL; /* set top-node next to NULL */
	new_last->prev = curr; /* set top-node prev to last node */
	new_head->prev = NULL; 
	*stack = new_head; /* last is now first */
}
/**
 * _rotr - rotates the stack to the right; the top node
 * becomes the second node, and the last node becomes top
 * @stack: pointer to head/top of linked list/stack
 * @line_number: see _push for reference (unused argument)
 * Return: nothing
 */
void _rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp, *new_first, *new_last;
	int count, idx = 0;

	if (!stack || !(*stack))
		return;

	temp = *stack;

	for (count = 0; temp; count++)
		temp = temp->next;

	if (count == 1)
		return;
	if (count == 2) /* for exactly two-node stack */
	{
		new_first = (*stack)->next;
		new_last = *stack;
		new_first->next = new_last;
		new_first->prev = NULL;
		new_last->prev = new_first;
		new_last->next = NULL;
		*stack = new_first;
	}
	else /* for stacks with >2 nodes */
	{
		new_first = *stack;
		new_last = *stack;
		while (idx < count - 2)
		{
			new_last = new_last->next; /* move to 2nd to last */
			idx++;
		}
		while (new_first->next)
			new_first = new_first->next; /* move to last node */
		new_first->next = *stack; /* point last node to head */
		(*stack)->prev = new_first; /* set current head prev to last */
		new_first->prev = NULL;
		new_last->next = NULL;
		*stack = new_first; /* last is now first */
	}
}
