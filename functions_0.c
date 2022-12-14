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

