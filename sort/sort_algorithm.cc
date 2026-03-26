#include "sort_algorithm.h"

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < capacity - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < capacity - 1 - i; j++)
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
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

void InsertionSort(int arr[], int size)
{

}

void ShellSort(int arr[], int size)
{

}

void QuickSort(int arr[], int size)
{

}

void MergeSort(int arr[], int size)
{

}