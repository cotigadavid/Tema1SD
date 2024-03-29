#include <vector>
#include <algorithm>

int medianOfThree(std::vector<int>& arr, int left, int right) 
{
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid])
        std::swap(arr[left], arr[mid]);

    if (arr[left] > arr[right])
        std::swap(arr[left], arr[right]);

    if (arr[mid] > arr[right])
        std::swap(arr[mid], arr[right]);

    return mid;
}

int partition(std::vector<int>& arr, int left, int right)
{
    int pivotIndex = medianOfThree(arr, left, right);
    int pivotValue = arr[pivotIndex];

    std::swap(arr[pivotIndex], arr[right]);

    int i = left;
    for (int j = left; j < right; ++j) 
    {
        if (arr[j] < pivotValue) {
            std::swap(arr[i], arr[j]);
            ++i;
        }
    }

    std::swap(arr[i], arr[right]);
    return i;
}

void quickSort(std::vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}