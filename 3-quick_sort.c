#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme
 * @array: Array to sort.
 * @low: Low index.
 * @high: High index.
 * @size: Size of the array.
 * Return: Index of the pivot.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != j)
		print_array(array, size);

	return (i + 1);
}

/**
 * quicksort - Helper function for quick_sort.
 * @array: Array to sort.
 * @low: Low index.
 * @high: High index.
 * @size: Size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quicksort(array, low, pivot_index - 1, size);
		quicksort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick Sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quicksort(array, 0, size - 1, size);
}
