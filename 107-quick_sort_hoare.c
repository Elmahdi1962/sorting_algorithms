#include "sort.h"

/**
 * quick_sort_hoare - sort array using quick_sort_hoare partition
 * @array: array
 * @size: size of the array
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qsh(array, 0, (int)size - 1, size);
}

/**
 * qsh - quick sort recursive function
 * @array: array
 * @low: lowest index
 * @high: highest index
 * @size: size of array
 * Return: void
 */
void qsh(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now*/
		/*at right place */
		int p = partitionh(array, low, high, size);

		/* Separately sort elements before*/
		/* partition and after partition*/
		qsh(array, low, p - 1, size);
		qsh(array, p + 1, high, size);
	}
}
/**
 * partitionh - hoare partition implementation
 * @arr: array
 * @low: lowest index
 * @high: hghest index
 * @size: size of array
 * Return: new pivot index
 */

int partitionh(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];/* pivot*/
	int i = (low - 1); /* Index of smaller element*/
	int j;

	for (j = low; j <= high - 1; j++)
	{
		/* If current element is smaller than or*/
		/* equal to pivot*/
		if (arr[j] <= pivot)
		{
			i++;/* increment index of smaller element*/
			swap(arr, i, j, size);
		}
	}
	swap(arr, i + 1, high, size);
	return (i + 1);
}

/**
 * swap - swap 2 indexes in an array
 * @array: array
 * @i: index 1
 * @j: index 2
 * @size: size of array
 * Return: void
 */

void swap(int *array, int i, int j, size_t size)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}
