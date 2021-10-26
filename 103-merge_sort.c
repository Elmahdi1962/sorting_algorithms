#include "sort.h"

/**
 * merge_sort - sorting an array using mergse sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size + 1);
	if (!b)
		return;

	topdownmergesort(array, b, size);
	free(b);
}

/**
 * topdownmergesort - Top Down Merge Sort
 * @a: array a
 * @b: array b
 * @n: size of array
 * Return: void
 */

void topdownmergesort(int *a, int *b, int n)
{
	/* array int *a has the items to sort; array int *b is a work array.*/
	copyarray(a, 0, n, b);           /* one time copy of int *a to int *b */
	topdownsplitmerge(b, 0, n, a);   /* sort data from int *b into int *a */
}

/**
 * topdownsplitmerge - Top Down Split Merge
 * @b: array b
 * @ibegin: start index
 * @iend: end index
 * @a: array a
 * Return: void
 */

void topdownsplitmerge(int *b, int ibegin, int iend, int *a)
{
	/* Split int *a into 2 runs, sort both runs into int *b,*/
	/*merge both runs from int *b to int *a*/
	/* ibegin is inclusive; iend is exclusive (a[iend] is not in the set).*/
	if (iend - ibegin <= 1)                     /* if run size == 1*/
	{
		return;	                                /*   consider it sorted*/
	}
	/* split the run longer than 1 item into halves*/
	int imiddle = (iend + ibegin) / 2;              /*imiddle = mid point*/
	/* recursively sort both runs from array int *a into int *b*/
	topdownsplitmerge(a, ibegin,  imiddle, b);  /* sort the left  run*/
	topdownsplitmerge(a, imiddle,    iend, b);  /* sort the right run*/
	/* merge the resulting runs from array int *b into int *a*/
	topdownmerge(b, ibegin, imiddle, iend, a);
}


/**
 * topdownmerge - tom down merger
 * Left source half is a[ ibegin:imiddle-1]
 * Right source half is a[imiddle:iend-1   ]
 * Result is            b[ ibegin:iend-1   ]
 * @a: array a, the unsorted array
 * @ibegin: start index
 * @imiddle: middle index that splits the subarrays
 * @iend: end index
 * @b: array b where sorted array will be
 * Return: void
 */

void topdownmerge(int *a, int ibegin, int imiddle, int iend, int *b)
{
	int i = ibegin, j = imiddle, k;

	/* While there are elements in the left or right runs...*/
	for (k = ibegin; k < iend; k++)
	{
		/* If left run head exists and is <= existing right run head.*/
		if (i < imiddle && (j >= iend || a[i] <= a[j]))
		{
			b[k] = a[i];
			i = i + 1;
		} else
		{
			b[k] = a[j];
			j = j + 1;
		}
	}
	printf("Merging...\n[left]: ");
	for (i = ibegin; i < imiddle; i++)
	{
		if (imiddle - i > 1)
			printf("%d, ", a[i]);
		else
			printf("%d", a[i]); }
	printf("\n");
	printf("[right]: ");
	for (i = imiddle; i < iend; i++)
	{
		if (iend - i > 1)
			printf("%d, ", a[i]);
		else
			printf("%d", a[i]); }
	printf("\n");
	printf("[Done]: ");
	for (i = ibegin; i < iend; i++)
	{
		if (iend - i > 1)
			printf("%d, ", b[i]);
		else
			printf("%d", b[i]); }
	printf("\n");
}

/**
 * copyarray - copies array a to array b from ibegin
 * to iend
 * @a: array a
 * @ibegin: start index
 * @iend: end index
 * @b: array b
 * Return: void
 */

void copyarray(int *a, int ibegin, int iend, int *b)
{
	int k;

	for (k = ibegin; k < iend; k++)
		b[k] = a[k];
}
