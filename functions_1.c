#include "monty.h"
/**
 * _add - adds the first two data on the stack and deletes the
 * first node, making the second node storage for the result, and
 * top of the stack
 * @stack: pointer to head/top of linked list/stack
 * @line_number: see _push for reference (unused argument)
 * Return: nothing
 */
void _add(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int count, addn_res;
	stack_t *temp, *f_node, *s_node;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
				line_number);
		if (*stack)
			free_stack_list(stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	for (count = 0; temp; count++)
		temp = temp->next;

	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	f_node = *stack;
	s_node = (*stack)->next;

	addn_res = s_node->n + f_node->n;
	s_node->n = addn_res;
	_pop(stack, line_number);
}
