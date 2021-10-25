#include "sort.h"

/**
 * shell_sort - sorts an array using shell sort algorithm
 * @array: array
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int h = 1, in, out, tmp;

	while (h <= ((int)size / 3))
		h = (h * 3) + 1;

	while (h > 0)
	{
		for (out = h; out < (int)size; out++)
		{
			tmp = array[out];
			in = out;
			while (in > h - 1 && array[in - h] >= tmp)
			{
				array[in] = array[in - h];
				in = in - h;
			}
			array[in] = tmp;
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
