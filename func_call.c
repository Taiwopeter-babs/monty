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
			{"pall", _pall}, {"push", _push}, {"pint", _pint},
			{"pop", _pop}, {"swap", _swap}, {"nop", NULL},
			{"add", _add}, {"sub", _sub}, {"div", _div},
			{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
			{NULL, NULL}};
	int idx;

	if (tokens[0][0] == '#')
		return;
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
			if (func[idx].f)
				func[idx].f(stack, line_number);
			break;
		}
		if (func[idx].opcode == NULL)
		{
			dprintf(STDERR_FILENO,
					"L%u: unknown instruction %s\n",
					line_number, tokens[0]);
			exit(EXIT_FAILURE);
		}
	}
}
