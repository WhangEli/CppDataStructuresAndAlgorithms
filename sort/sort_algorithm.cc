#include "sort_algorithm.h"

void BubbleSort(int arr[], int capacity)
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

		if (flag)
		{
			return;
		}
	}
}

void SelectionSort(int arr[], int capacity)
{
	for (int i = 0; i < capacity; i++)
	{
		int min = i;
		for (int j = i; j < capacity; j++)
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

void InsertionSort(int arr[], int capacity)
{

}

void ShellSort(int arr[], int capacity)
{

}

void QuickSort(int arr[], int capacity)
{

}

void MergeSort(int arr[], int capacity)
{

}