#include "Lab05.h"
#include <stdlib.h>

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

void insertionSort(int* arr, const int n)
{
	int i, j, toMove;
	for (i = 1; i < n; ++i)
	{
		toMove = arr[i];
		j = i;
		while (j > 0 && toMove < arr[j - 1])
		{
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = toMove;
	}
}

void shellSort(int* arr, const int n)
{
	int i, j, h, toAdd;
	for (h = n / 2; h > 0; h /= 2)
		for (i = h; i < n; ++i)
		{
			toAdd = arr[i];
			for (j = i; j >= h && toAdd < arr[j - h]; j--)
				arr[j] = arr[j - h];
			arr[j] = toAdd;
		}
}

void quickSort(int * arr, const int begin, const int end)
{
	if (begin < end)
	{
		int j = pivot(arr, begin, end);
		quickSort(arr, begin, j - 1);
		quickSort(arr, j + 1, end);
	}
}
int pivot(int* arr, const int begin, const int end)
{
	int i = begin;
	int j = end;
	int pivot = arr[begin];
	while (i < j)
	{
		while (pivot >= arr[i] && j > i) ++i;
		while (arr[j] > pivot) --j;
		if (i < j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[begin] = arr[j];
	arr[j] = pivot;
	return j;
}

void countSort(int* arr, const int n, const int k)
{
	int c[55] = { 0 };
	int* b = calloc(n, sizeof(int));

	for (int i = 0; i < n; ++i)
		c[arr[i]]++;
	for (int i = 1; i <= k; ++i)
		c[i] += c[i - 1];
	for (int j = n - 1; j >= 0; --j)
	{
		b[c[arr[j]] - 1] = arr[j]; // <- !
		c[arr[j]]--;
	}
	for (int i = 0; i < n; ++i)
		arr[i] = b[i];
}

int minimum(int* arr, const int n)
{
	int min = arr[0];
	for (int i = 1; i < n; ++i)
		if (min > arr[i])
			min = arr[i];
	return min;
}
int maximum(int* arr, const int n)
{
	int max = arr[0];
	for (int i = 1; i < n; ++i)
		if (max < arr[i])
			max = arr[i];
	return max;
}

int find(int* arr, const int low, const int high, const int k)
{
	int j = partition(arr, low, high);
	int i = k + low - 1;
	if (i == j)
		return arr[i];
	if (i > j)
		return find(arr, j + 1, high, k - j);
	else
		return find(arr, low, j - 1, k);

}
int partition(int* arr, const int low, const int high)
{
	int i = low;
	int j = high;
	int pivot = arr[low];
	while (i < j)
	{
		while (arr[i] <= pivot && j > i) ++i;
		while (arr[j] > pivot) --j;
		if (i < j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[low] = arr[j];
	arr[j] = pivot;
	return j;
}

int intSearch(int* arr, const int key, const int n)
{
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = low + (high - low)*(key - arr[low]) / (arr[high] - arr[low]);
		if (arr[mid] == key)
			return arr[mid];
		else
			if (arr[mid] < key)
				low = mid + 1;
			else
				high = mid - 1;
	}
	return 0;
}