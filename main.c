#include "monty.h"
#include "var.h"
/**
 * cleanup - frees everything
 *
 * @h: the stack
 * Return: nothing, it is voi
 */
void cleanup(stack_t *h)
{
	free_stack(h);
	free(arguments);
	free(result);
	free(string);
	status = EXIT_FAILURE;
}
/**
 * main - the main runner of the code
 *
 * @ac: the number of command line arguments
 * @av: the array of command line arguments
 * Return: success
 */
int main(int ac, char *av[])
{
	stack_t *h = NULL;
	void (*func)(stack_t **, unsigned int);
	size_t i = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	string = pen(av[1]);
	arguments = split(string, "\n");
	while (arguments[i])
	{
		result = split(arguments[i], " \t");
		if (check(result[0]) == 0)
		{
			fprintf(stderr, "L%ld: unknown instruction %s\n", i + 1, result[0]);
			cleanup(h);
			return (EXIT_FAILURE);
		}
		func = get_opcode(result[0]);
		func(&h, i + 1);
		if (status == EXIT_FAILURE)
			return (status);
		i++;
		free(result);
	}
	free_stack(h);
	free(arguments);
	free(string);
	return (EXIT_SUCCESS);
}
