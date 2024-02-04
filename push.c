#include "lists.h"
#include <ctype.h>
/**
 * push - function to push an element to the stack
 * @stack: place to push
 * @value: int to push
 * @line_count: number of lines
 *
 * Return: Always 0 (success)
 */
void push(stack_t **stack, char *value, unsigned int line_count)
{
	unsigned int integer;
	stack_t *new_node;

	if (!isdigit(*value) || !value)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_count);
		return (EXIT_FAILURE);
	}
	integer = atoi(value);

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	new_node->n = integer;
	new_node->previous = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
