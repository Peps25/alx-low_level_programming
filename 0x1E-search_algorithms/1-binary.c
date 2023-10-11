#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array
 *                 of ints using binary search.
 * @array: Pointer to the first element of the array to search
 * @size: Number of elements in the array
 * @value: Value to be searched for
 *
 * Return: -1 if no value is present or the array is NULL
 *         Otherwise, the index where the value is located
 */

int binary_search(int *array, size_t size, int value)
{
	size_t ui, left, right;

	/* Check if the array is NULL */
	if (array == NULL)
		return (-1);

	/* Perform binary search */
	for (left = 0, right = size - 1; right >= left;)
	{
		printf("Searching in array: ");
		for (ui = left; ui < right; ui++)
			printf("%d, ", array[ui]);
		printf("%d\n", array[ui]);

		/* Calculate the middle index */
		ui = left + (right - left) / 2;

		/* If the middle element is the value */
		if (array[ui] == value)
			/* Return the index */
			return (ui);

		/* If the middle element is greater than the value */
		if (array[ui] > value)
			/* Update the right boundary */
			right = ui - 1;
		else
			/* Otherwise, update the left boundary */
			left = ui + 1;
	}
	/* Value not found, return -1 */
	return (-1);
}
