#include "monty.h"
/**
 * op_add - adds the first and second element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: Nothing, it is void
 */
void op_add(stack_t **head, unsigned int line_no)
{
	stack_t *ne;
	int xsum;

	ne = (*head);
	if (!(ne && ne->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
		cleanup(*head);
		return;
	}
	xsum = ne->n + ne->next->n;
	ne->next->n = xsum;
	(*head) = (*head)->next;
	free(ne);
	(*head)->prev = NULL;
}
/**
 * op_sub - subtracts the first from the second element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: Nothing, it is void
 */
void op_sub(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	int a;

	temp = (*head);
	if (!(temp && temp->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_no);
		cleanup(*head);
		return;
	}
	a = temp->next->n - temp->n;
	temp->next->n = a;
	(*head) = (*head)->next;
	free(temp);
}
/**
 * op_mul - multiplies the first and second element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: Nothing, it is void
 */
void op_mul(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	int a;

	temp = (*head);
	if (!(temp && temp->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_no);
		cleanup(*head);
		return;
	}
	a = (temp->next->n) * (temp->n);
	temp->next->n = a;
	(*head) = (*head)->next;
	free(temp);
}
/**
 * op_div - divides the second by thr first element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: Nothing, it is void
 */
void op_div(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	int a;

	temp = (*head);
	if (!(temp && temp->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_no);
		cleanup(*head);
		return;
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		cleanup(*head);
		return;
	}
	a = temp->next->n / temp->n;
	temp->next->n = a;
	(*head) = (*head)->next;
	free(temp);
}
/**
 * op_mod - gives the modulus of the second by the first element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: Nothing, it is void
 */
void op_mod(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	int a;

	temp = (*head);
	if (!(temp && temp->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_no);
		cleanup(*head);
		return;
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		cleanup(*head);
		return;
	}
	a = temp->next->n % temp->n;
	temp->next->n = a;
	(*head) = (*head)->next;
	free(temp);
}
