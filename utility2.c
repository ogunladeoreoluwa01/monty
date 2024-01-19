#include "monty.h"
/**
 * pen - opens a file
 *
 * @filename: the file
 * Return: the contents fo the file
 */
char *pen(char *filename)
{
	int fd;
	struct stat fdstat;
	size_t size;
	char *buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fstat(fd, &fdstat);
	size = fdstat.st_size;

	buffer = malloc(sizeof(char) * size + 1);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	read(fd, buffer, size);
	close(fd);
	buffer[size] = '\0';
	return (buffer);
}
/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: a pointer to the previously allocated memory
 * @osize: the size of the previously allocated memory
 * @nsize: the size of the memory to be allocated
 *
 * Return: reallocated memory or NULL if malloc fails.
 */
void *_realloc(void *ptr, size_t osize, size_t nsize)
{
	size_t nbytes, b;
	void *buffer;

	if (osize == nsize)
	return (ptr);
	if (!nsize && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (nsize > osize)
		nbytes = osize;
	else
		nbytes = nsize;
	buffer = malloc(nsize);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		status = EXIT_FAILURE;
		return (NULL);
	}
	if (!ptr)
		return (buffer);
	for (b = 0; b < nbytes; b++)
		((char *)buffer)[b] = ((char *)ptr)[b];
	free(ptr);
	return (buffer);
}
/**
 * op_stack - changes the mode to stack
 *
 * @head: the stack
 * @line_no: the line number
 * Return: nothing it is void
 */
void op_stack(stack_t **head, unsigned int line_no)
{
	mode = STACK;
	(void)head;
	(void)line_no;
}
/**
 * op_queue - changes the mode to queue
 *
 * @head: the head
 * @line_no: the line_number
 * Return: nothing, it is void
 */
void op_queue(stack_t **head, unsigned int line_no)
{
	mode = QUEUE;
	(void)head;
	(void)line_no;
}
