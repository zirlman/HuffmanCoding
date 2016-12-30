#include "Lab05.h"

void bubbleSort(int *arr, const int n)
{
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - i - 1; ++j)
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

void selectionSort(int* arr, const int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < n; ++j)
			if (arr[min] < arr[j])
				min = j;
		if (min != i)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}