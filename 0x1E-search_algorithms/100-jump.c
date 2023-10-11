#include "search_algos.h"
/**
  * jump_search - Searches for a value in a sorted array
  *               of ints using jump search.
  * @array: Pointer to the first element of the array to search.
  * @size: Number of elements in the array.
  * @value: Value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  */

int jump_search(int *array, size_t size, int value)
{
	size_t ui, jump, step;

	/* Check if the array is NULL or empty */
	if (array == NULL || size == 0)
		return (-1);

	/* Calculate the jump step size */
	step = sqrt(size);

	/* Perform the jump search */
	for (ui = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);

		/* Store the previous jump position */
		ui = jump;

		/* Update the jump position */
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", ui, jump);

	/* Adjust the jump position */
	jump = jump < size - 1 ? jump : size - 1;

	/* Perform a linear search within the identified range */
	for (; ui < jump && array[ui] < value; ui++)
		printf("Value checked array[%ld] = [%d]\n", ui, array[ui]);

	printf("Value checked array[%ld] = [%d]\n", ui, array[ui]);

	/* Check if the value is found and return the corresponding index */
	return (array[ui] == value ? (int)ui : -1);
}
