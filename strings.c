#include "monty.h"
/**
 * op_nop - does nothing
 *
 * @head: the stack
 * @line_no: the line_number
 * Return: nothing, it is void
 */
void op_nop(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;
}
/**
 * op_pchar - prints ascii
 *
 * @head: the stack
 * @line_no: the line_number
 * Return: nothing, it is void
 */
void op_pchar(stack_t **head, unsigned int line_no)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_no);
		cleanup(*head);
		return;
	}
	if ((*head)->n < 1 || (*head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_no);
		cleanup(*head);
		return;
	}
	fprintf(stdout, "%c\n", (*head)->n);
}
/**
 * op_pstr - prints the ascii value in the stack'
 *
 * @head: the head
 * @line_no: the line_number
 * Return: nothing, it was void
 */
void op_pstr(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	(void)line_no;

	temp = (*head);
	while (temp)
	{
		if (temp->n < 1 || temp->n > 127)
			break;
		fprintf(stdout, "%c", temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
/**
 * op_rotl - rotates top to bottom
 *
 * @head: the stack
 * @line_no: the line number
 * Return: nothing, it is void
 */
void op_rotl(stack_t **head, unsigned int line_no)
{
	stack_t *top, *bottom;

	if ((*head) && (*head)->next)
	{

		top = (*head);
		bottom = (*head)->next;
		while (bottom->next)
			bottom = bottom->next;
		(*head) = (*head)->next;
		bottom->next = top;
		top->next = NULL;
		top->prev = bottom;
		(void)line_no;

	}
}
/**
 * op_rotr - rotates the bottom to the top
 *
 * @head: the stack
 * @line_no: the line number
 */
void op_rotr(stack_t **head, unsigned int line_no)
{
	stack_t *bottom, *temp;

	if ((*head) && (*head)->next)
	{
		temp = NULL;
		bottom = (*head);
		while (bottom->next != NULL)
		{
			temp = bottom;
			bottom = bottom->next;
		}
		temp->next = NULL;
		bottom->prev = NULL;
		bottom->next = (*head);
		(*head)->prev = bottom;
		(*head) = bottom;
	}
	(void)line_no;
}
