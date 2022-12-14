#include "monty.h"

/**
 * _push - pushes a new node to the top of the stack;
 * beginning of linked list
 * @stack: pointer to head of linked list
 * @line_number: position of the command in the monty file
 * Return: nothing
 */
void _push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free(new_node);
		free_stack_list(stack);
		exit(EXIT_FAILURE);
	}

	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
/**
 * _pall - prints all the data in the stack (linked list)
 * @stack: pointer to head/top of linked list/stack
 * @line_number: see _push for reference (unused argument)
 * Return: nothing
 */
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !stack)
		return;

	temp = *stack;

	while (temp)
	{
		dprintf(STDOUT_FILENO, "%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * _pint - prints to stdout the data at th top of the stack
 * @stack: pointer to head of the stack
 * @line_number: reference to line number of command and data
 * Return: nothing
 */
void _pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	dprintf(STDOUT_FILENO, "%d\n", temp->n);
}
/**
 * _pop - deletes/removes the node at the top of the stack
 * @stack: pointer to head of stack
 * @line_number: reference to line number of command and data
 * Return: nothing
 */
void _pop(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	else if (*stack)
	{
		temp = *stack;
		if ((*stack)->next)
		{
			*stack = (*stack)->next;
			(*stack)->prev = NULL;
		}
		else
			*stack = NULL;

		free(temp);
	}
}
/**
 * _swap - swaps the first and second nodes on the stack
 * @stack: pointer to head of stack
 * @line_number: unused parameter
 * Return: nothing
 */
void _swap(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int count;
	stack_t *temp, *f_node, *s_node;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
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
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	f_node = *stack;
	s_node = (*stack)->next;
	if (count > 2)
	{
		f_node->next = s_node->next;
		s_node->next->prev = f_node;
		s_node->next = f_node;
		f_node->prev = s_node;
		s_node->prev = NULL;
		*stack = s_node;
	}
	if (count == 2)
	{
		f_node->next = NULL;
		s_node->next = f_node;
		f_node->prev = s_node;
		s_node->prev = NULL;
		*stack = s_node;
	}
}
