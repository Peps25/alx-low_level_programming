#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array
 *                 of ints using linear search
 * @array: Pointer to the first element of the array to search
 * @size: Number of elements in array
 * @value: Value to be searched for
 *
 * Return: -1 if no value present or array is NULL
 *         Otherwise, the first index where the value is located.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t ui;

	/* Check if the array is NULL */
	if (array == NULL)
		return (-1);

	/* Iterate over each element of the array */
	for (ui = 0; ui < size; ui++)
	{
		/* Print the value being checked */
		printf("Value checked array[%ld] = [%d]\n", ui, array[ui]);

		/* If the value is found */
		if (array[ui] == value)

			/* Return the index of the value */
			return (i);
	}

	/* Value not found, return -1 */
	return (-1);
}
