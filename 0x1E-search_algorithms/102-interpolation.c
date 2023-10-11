#include "search_algos.h"

/**
  * interpolation_search - Searches for a value in a sorted array
  *                        of ints using interpolation search.
  * @array: Pointer to the first element of the array to search.
  * @size: Number of elements in the array.
  * @value: Value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  */

int interpolation_search(int *array, size_t size, int value)
{
	size_t ui, l, r;

	/* Check if the array is NULL */
	if (array == NULL)
		return (-1);

	/* Perform interpolation search */
	for (l = 0, r = size - 1; r >= l;)
	{
		ui = l + (((double)(r - l) / (array[r] - array[l])) * (value - array[l]));
		if (ui < size)
			printf("Value checked array[%ld] = [%d]\n", ui, array[ui]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", ui);
			break;
		}

		if (array[ui] == value)
			return (ui);
		if (array[ui] > value)
			r = ui - 1;
		else
			l = ui + 1;
	}

	return (-1);
}
