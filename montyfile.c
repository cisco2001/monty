#include "monty.h"
/**
 * main - main
 * @arg: number of arguments
 * @argv: argumenets
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t len = 0;
	file *mounty_file;
	char *stack = NULL;
	unsigned int line_count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file monty_file\n");
		return (EXIT_FAILURE);
	}
	while (getline(&buffer, &len, monty_file) != -1)
	{
		line_count++;
		if (pass&execute(&stack, buffer, line_count)) == EXIT_FAILURE
		{
			fprintf(stderr, "L%u: unknown instruction <opcode>\n", line_count);
			fclose(monty_file);
			free(buffer);
			free_stack(&stack);
			return (EXIT_FAILURE);
		}
	}
	fclose(monty_file);
	free(buffer);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
