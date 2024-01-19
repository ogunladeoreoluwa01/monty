#include "monty.h"
/**
 * appendStr - append a string to an array of strings
 *
 * @arr: a pointer to a malloced array of strings
 * @size: a pointer to an integer holding the size of the array
 * @str: the new string to append to the array
 * @index: the index at which to insert the string
 *
 * Return: 1 if succeeded, or 0 if it failed
 */

bool appendStr(char ***arr, size_t *size, char *str, int index)
{
	size_t arr_size;
	char **array;

	arr_size = *size;
	array = *arr;

	if (!(arr && *arr))
		return (false);
	while (arr_size <= (unsigned int)index)
	{
		if (arr_size == 0)
			arr_size++;
		array = _realloc(array,
			NPTRS(arr_size),
			NPTRS(arr_size) * 2);
		arr_size *= 2;
		if (!array)
			return (false);
	}
	(array)[index] = str;
	*arr = array;
	*size = arr_size;
	return (true);
}
/**
 * split - split a string using a delimiter
 *
 * @string: the string to split
 *
 * @delimiter: a list of delimiters to use to split the string
 * Return: A null-terminated array of strings.
 * NULL is returned if malloc failed or if the string
 * could not be split; this could be because:
 * - the string is empty
 * - the string is NULL
 * - the string only contains delimiters
 * - delimiters is NULL
 * - delimiters is empty
 */

char **split(char *string, char *delimiter)
{
	char **array, prev = '\0', curr;
	size_t arr_size = 2, arr_ind = 0, str_ind, i;
	bool flipped;

	if (!(string && *string && delimiter && *delimiter))
		return (NULL);
	array = malloc(NPTRS(arr_size));
	if (array == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		status = EXIT_FAILURE;
		return (NULL);
	}
	for (str_ind = 0; string[str_ind]; str_ind++)
	{
		curr = string[str_ind];
		flipped = false;
		for (i = 0; delimiter[i]; i++)
			if (curr == delimiter[i])
			{
				string[str_ind] = '\0';
				flipped = true;
				break;
			}
		if (prev == '\0' && flipped == false)
			appendStr(&array, &arr_size, &string[str_ind], arr_ind++);
		if (string[str_ind + 1] == '\n' && strcmp(delimiter, "\n") == 0 &&
				string[str_ind] == '\0')
			appendStr(&array, &arr_size, "#", arr_ind++);
		prev = string[str_ind];
	}
	if (arr_ind)
		appendStr(&array, &arr_size, NULL, arr_ind);
	else
	{
		free(array);
		array = NULL;
	}
	return (array);
}
