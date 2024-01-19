#include "monty.h"
/**
 * op_push - pushes an element onto the stack
 *
 * @head: the stack
 * @line_no: the line number of the argument
 * Return: nothing, it is void
 */
void op_push(stack_t **head, unsigned int line_no)
{
	stack_t *temp, *temp2;
	int n;

	if (!(result[1]) || checkatoi(result[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		cleanup(*head);
		return;
	}
	n = atoi(result[1]);
	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		cleanup(*head);
		return;
	}
	temp->n = n;
	if (mode == STACK)
	{
		temp->prev = NULL;
		temp->next = (*head);
		if ((*head) != NULL)
			(*head)->prev = temp;
		(*head) = temp;
		return;
	}
	temp2 = (*head);
	if (*head == NULL)
	{
		temp->prev = NULL;
		temp->next = (*head);
		(*head) = temp;
		return;
	}
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp;
	temp->prev = temp2;
	temp->next = NULL;
}

/**
 * op_pall - prints all values on the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: nothing, it is void
 */

void op_pall(stack_t **head, unsigned int line_no)
{
	stack_t *temp;

	(void)line_no;
	temp = (*head);
	while (temp)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * op_pint - prints the first member of the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: nothing, it is void
 */

void op_pint(stack_t **head, unsigned int line_no)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		cleanup(*head);
		return;
	}
	fprintf(stdout, "%d\n", (*head)->n);
}

/**
 * op_pop - removes the top element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line_number
 * Return: nothing, it is a void
 */

void op_pop(stack_t **head, unsigned int line_no)
{
	stack_t *temp;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		cleanup(*head);
		return;
	}
	temp = (*head);
	(*head) = (*head)->next;
	free(temp);
}

/**
 * op_swap - swaps the top two elements in the stack
 *
 * @head: the head of the stack
 * @line_no: the line_number
 * Return: nothing, it is a void
 */

void op_swap(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	int a;

	temp = (*head);
	if (!(temp && temp->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		cleanup(*head);
		return;
	}
	a = temp->n;
	temp->n = temp->next->n;
	temp->next->n = a;
}
