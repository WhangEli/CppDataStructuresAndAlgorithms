#include "sort_algorithm.h"

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}

		if (!flag)
		{
			return;
		}
	}
}

void SelectionSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i; j < size; j++)
		{
			if (arr[min] >= arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

void InsertionSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		for (j; j >= 0; j--)
		{
			if (arr[j] > temp)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}

		arr[j + 1] = temp;
	}
}

void ShellSort(int arr[], int size)
{
	int gap = size / 2;
	while (gap >= 1)
	{
		for (int v = 0; v < gap; v++)
		{
			for (int i = v + gap; i < size; i = i + gap)
			{
				int temp = arr[i];
				int j = i - gap;
				for (j; j >= 0;  j = j - gap)
				{
					if (arr[j] > temp)
					{
						arr[j + gap] = arr[j];
					}
					else
					{
						break;
					}
				}

				arr[j + gap] = temp;
			}
		}

		gap = gap / 2;
	}
}

void QuickSort(int arr[], int size)
{

}

void MergeSort(int arr[], int size)
{

}