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
	int count;
	stack_t *temp, *f_node, *s_node;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	for (count = 0; temp; count++)
		temp = temp->next;

	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
				line_number);
		if (*stack)
			free_stack_list(stack);
		exit(EXIT_FAILURE);
	}
	f_node = *stack;
	s_node = (*stack)->next;

	s_node->n += f_node->n;
	_pop(stack, line_number);
}
/**
 * _sub - subtracts the first two data on the stack and deletes the
 * first node, making the second node storage for the result, and
 * top of the stack
 * @stack: pointer to head/top of linked list/stack
 * @line_number: see _push for reference (unused argument)
 * Return: nothing
 */
void _sub(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int count;
	stack_t *temp, *f_node, *s_node;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	for (count = 0; temp; count++)
		temp = temp->next;

	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
				line_number);
		if (*stack)
			free_stack_list(stack);
		exit(EXIT_FAILURE);
	}
	f_node = *stack;
	s_node = (*stack)->next;

	s_node->n -= f_node->n;
	_pop(stack, line_number);
}
/**
 * _div - adds the first two data on the stack and deletes the
 * first node, making the second node storage for the result, and
 * top of the stack
 * @stack: pointer to head/top of linked list/stack
 * @line_number: see _push for reference (unused argument)
 * Return: nothing
 */
void _div(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int count;
	stack_t *temp, *f_node, *s_node;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	for (count = 0; temp; count++)
		temp = temp->next;

	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
				line_number);
		if (*stack)
			free_stack_list(stack);
		exit(EXIT_FAILURE);
	}
	f_node = *stack;
	s_node = (*stack)->next;
	if (f_node->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		free_stack_list(stack);
		exit(EXIT_FAILURE);
	}
	s_node->n /= f_node->n;
	_pop(stack, line_number);
}
/**
 * _mul - subtracts the first two data on the stack and deletes the
 * first node, making the second node storage for the result, and
 * top of the stack
 * @stack: pointer to head/top of linked list/stack
 * @line_number: see _push for reference (unused argument)
 * Return: nothing
 */
void _mul(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int count;
	stack_t *temp, *f_node, *s_node;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	for (count = 0; temp; count++)
		temp = temp->next;

	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
				line_number);
		if (*stack)
			free_stack_list(stack);
		exit(EXIT_FAILURE);
	}
	f_node = *stack;
	s_node = (*stack)->next;

	s_node->n *= f_node->n;
	_pop(stack, line_number);
}
/**
 * _mod - adds the first two data on the stack and deletes the
 * first node, making the second node storage for the result, and
 * top of the stack
 * @stack: pointer to head/top of linked list/stack
 * @line_number: see _push for reference (unused argument)
 * Return: nothing
 */
void _mod(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int count;
	stack_t *temp, *f_node, *s_node;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	for (count = 0; temp; count++)
		temp = temp->next;

	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n",
				line_number);
		if (*stack)
			free_stack_list(stack);
		exit(EXIT_FAILURE);
	}
	f_node = *stack;
	s_node = (*stack)->next;
	if (f_node->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		free_stack_list(stack);
		exit(EXIT_FAILURE);
	}
	s_node->n %= f_node->n;
	_pop(stack, line_number);
}
