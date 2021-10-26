#include "sort.h"

/**
 * merge_sort - sorting an array using mergse sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *B;

	if (array == NULL || size < 2)
		return;

	B = malloc(sizeof(int) * size + 1);
	if (!B)
		return;

	TopDownMergeSort(array, B, size);
}

/**
 * TopDownMergeSort - Top Down Merge Sort
 * @A: array A
 * @B: array B
 * @n: size of array
 * Return: void
 */

void TopDownMergeSort(int *A, int *B, int n)
{
	/* Array int *A has the items to sort; array int *B is a work array.*/
	CopyArray(A, 0, n, B);           /* one time copy of int *A to int *B */
	TopDownSplitMerge(B, 0, n, A);   /* sort data from int *B into int *A */
}

/**
 * TopDownSplitMerge - Top Down Split Merge
 * @B: array B
 * @iBegin: start index
 * @iEnd: end index
 * @A: array A
 * Return: void
 */

void TopDownSplitMerge(int *B, int iBegin, int iEnd, int *A)
{
	/* Split int *A into 2 runs, sort both runs into int *B,*/
	/*merge both runs from int *B to int *A*/
	/* iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).*/
	if (iEnd - iBegin <= 1)                     /* if run size == 1*/
		return;                                 /*   consider it sorted*/
	/* split the run longer than 1 item into halves*/
	int iMiddle = (iEnd + iBegin) / 2;              /*iMiddle = mid point*/
	/* recursively sort both runs from array int *A into int *B*/
	TopDownSplitMerge(A, iBegin,  iMiddle, B);  /* sort the left  run*/
	TopDownSplitMerge(A, iMiddle,    iEnd, B);  /* sort the right run*/
	/* merge the resulting runs from array int *B into int *A*/
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}


/**
 * TopDownMerge - tom down merger
 * @A: array A, the unsorted array
 * @iBegin: start index
 * @iMiddle: middle index that splits the subarrays
 * @iEnd: end index
 * @B: array b where sorted array will be
 * Return: void
 */

/*  Left source half is A[ iBegin:iMiddle-1].*/
/* Right source half is A[iMiddle:iEnd-1   ].*/
/* Result is            B[ iBegin:iEnd-1   ].*/

void TopDownMerge(int *A, int iBegin, int iMiddle, int iEnd, int *B)
{
	int i = iBegin, j = iMiddle, k;

	/* While there are elements in the left or right runs...*/
	for (k = iBegin; k < iEnd; k++)
	{
		/* If left run head exists and is <= existing right run head.*/
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		} else
		{
			B[k] = A[j];
			j = j + 1;
		}
	}
	printf("Merging...\n[left]: ");
	for (i = iBegin; i < iMiddle; i++)
	{
		if (iMiddle - i > 1)
			printf("%d, ", A[i]);
		else
			printf("%d", A[i]); }
	printf("\n");
	printf("[right]: ");
	for (i = iMiddle; i < iEnd; i++)
	{
		if (iEnd - i > 1)
			printf("%d, ", A[i]);
		else
			printf("%d", A[i]); }
	printf("\n");
	printf("[Done]]: ");
	for (i = iBegin; i < iEnd; i++)
	{
		if (iEnd - i > 1)
			printf("%d, ", B[i]);
		else
			printf("%d", B[i]); }
	printf("\n");
}

/**
 * CopyArray - copies array A to array B from iBegin
 * to iEnd
 * @A: array A
 * @iBegin: start index
 * @iEnd: end index
 * @B: array B
 * Return: void
 */

void CopyArray(int *A, int iBegin, int iEnd, int *B)
{
	int k;

	for (k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}
