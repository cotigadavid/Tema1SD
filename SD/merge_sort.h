#pragma once

#include <vector>

void merge(std::vector<int>& arr, int left, int middle, int right)
{
    std::vector<int> tempArr(right - left + 1);

    int i = left, j = middle + 1, k = 0;
    while (i <= middle && j <= right) 
    {
        if (arr[i] <= arr[j]) 
        {
            tempArr[k] = arr[i];
            i++;
        }
        else 
        {
            tempArr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= middle) 
    {
        tempArr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) 
    {
        tempArr[k] = arr[j];
        j++;
        k++;
    }

    for (int p = 0; p < k; p++) 
    {
        arr[left + p] = tempArr[p];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right)
{
    if (left < right) 
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}
