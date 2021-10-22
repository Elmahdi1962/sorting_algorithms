#include "sort.h"

/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	qs(array, 0, (int)size, size);
}


/**
 * qs - recusion function of the quicksort algorithm
 * @arr: array
 * @low: first index
 * @high: last index
 * @size: size of the array
 * Return: void
 */

void qs(int *arr, int low, int high, size_t size)
{
	int p;

	if (low >= high)
		return;

	p = partition(arr, low, high, size);

	qs(arr, low, p - 1, size);
	qs(arr, p + 1, high, size);
}


/**
 * partition - lomuto partition implementation
 * @arr: array
 * @low: first index of the partition
 * @high: last index of the partition
 * @size: size of the array
 * Return: new index of the pivot
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high], i = low - 1, j, tmp;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			++i;
			/*swaping*/
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
	tmp = arr[high];
	arr[high] = arr[i + 1];
	arr[i + 1] = tmp;
	print_array(arr, size);
	return (i + 1);
}
