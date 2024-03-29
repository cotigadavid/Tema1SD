//#pragma once
//
//#include "merge_sort.h"
//
//using namespace std;
//const int RUN = 32;
//
//void insertionSort(std::vector<int>& arr, int left, int right)
//{
//	for (int i = left + 1; i <= right; i++)
//	{
//		int temp = arr[i];
//		int j = i - 1;
//
//		while (j >= left && arr[j] > temp) 
//		{
//			arr[j + 1] = arr[j];
//			j--;
//		}
//		arr[j + 1] = temp;
//	}
//}
//
//void timSort(std::vector<int>& arr, int size)
//{
//	for (int i = 0; i < size; i += RUN)
//		insertionSort(arr, i, min((i + RUN - 1), (size - 1)));
//
//	for (int size = RUN; size < size; size = 2 * size) 
//	{
//		for (int left = 0; left < size; left += 2 * size)
//		{
//			int mid = left + size - 1;
//			int right = min((left + 2 * size - 1), (size - 1));
//
//			if (mid < right)
//				merge(arr, left, mid, right);
//		}
//	}
//}

#include "merge_sort.h"
using namespace std;
const int RUN = 32;

void insertionSort(vector<int>& arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int temp = arr[i];
		int j = i - 1;

		while (j >= left && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void timSort(vector<int>& arr, int n)
{
	for (int i = 0; i < n; i += RUN)
		insertionSort(arr, i, min((i + RUN - 1), (n - 1)));

	for (int size = RUN; size < n; size = 2 * size) 
	{
		for (int left = 0; left < n; left += 2 * size) 
		{
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1), (n - 1));

			if (mid < right)
				merge(arr, left, mid, right);
		}
	}
}

