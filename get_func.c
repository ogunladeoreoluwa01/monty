#include "monty.h"
/**
 * get_opcode - gets the opcode of a particular function
 *
 * @s: the opcode to be checked
 * Return: a function pointer to the right opcode
 */
void (*get_opcode(char *s))(stack_t **, unsigned int)
{
	instruction_t op[] = {
		{"pall", op_pall},
		{"pop", op_pop},
		{"swap", op_swap},
		{"pint", op_pint},
		{"add", op_add},
		{"sub", op_sub},
		{"mul", op_mul},
		{"div", op_div},
		{"mod", op_mod},
		{"nop", op_nop},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"push", op_push},
		{"stack", op_stack},
		{"queue", op_queue},
		{"rotr", op_rotr},
		{NULL, NULL}
	};
	int i;

	i = 0;
	if (s[0] == '#')
		return (op_nop);
	while (i < 18)
	{
		if (strcmp(s, op[i].opcode) == 0)
			return (op[i].f);
		i++;
	}
	return (NULL);

}
/**
 * free_stack - frees a stack
 *
 * @h: the head of the stack
 * Return: nothing it is void
 */
void free_stack(stack_t *h)
{
	stack_t *temp;

	while (h)
	{
		temp = h;
		h = h->next;
		free(temp);
	}
	free(h);
}
/**
 * check - check if an argument i an opcode
 *
 * @s: the opcode
 * Return: 0 or 1
 */
int check(char *s)
{
	char *st[] = {"push", "pall", "pop", "pint", "swap",
		"add", "sub", "div", "mul", "mod", "rotl", "rotr",
		"pchar", "pstr", "stack", "queue", "nop"};
	int i, flag;

	i = 0;
	flag = 0;
	if (s[0] == '#')
		return (1);
	while (i < 17)
	{
		if (strcmp(s, st[i]) == 0)
		{
			flag = 1;
			break;
		}
		i++;
	}
	return (flag);
}
/**
 * itoan - converts integer to string
 *
 * @n: the integer
 * Return: the string
 */
char *itoan(int n)
{
	char *str = malloc(sizeof(char) * 13);

	if (str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	sprintf(str, "%d", n);
	return (str);
}
/**
 * checkatoi - checks if a string can be turned into numbers
 * Description:'A funciton'
 * @s: the string to be checked
 * Return: bool; true (1) if string can be converted else false(0)
 */
int checkatoi(char *s)
{
	char *sa;
	int i = 0;

	if (s[0] == '-' && s[1] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	sa = itoan(atoi(s));
	if (strcmp(s, "-0") == 0)
		;

	else if (strcmp(sa, s) != 0)
	{
		free(sa);
		return (0);
	}
	free(sa);
	return (1);
}
