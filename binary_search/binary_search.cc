#include "binary_search.h"

int RecursionBinarySearch(int first, int last, int arr[], int val)
{
	while (first <= last)
	{
		int middle = (first + last) / 2;
		if (arr[middle] > val)
		{
			return RecursionBinarySearch(first, middle - 1, arr, val);
		}
		else if (arr[middle] < val)
		{
			return RecursionBinarySearch(middle + 1, last, arr, val);
		}
		else
		{
			return middle;
		}
	}

	return -1;
}

int LoopBinarySearch(int first, int last, int arr[], int val)
{
	while (first <= last)
	{
		int middle = (first + last) / 2;
		if (arr[middle] < val)
		{
			first = middle + 1;
		}
		else if (arr[middle] == val)
		{
			return middle;
		}
		else
		{
			last = middle - 1;
		}
	}

	return -1;
}