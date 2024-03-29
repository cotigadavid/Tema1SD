#pragma once

#include <vector>
#include <climits>

using namespace std;

int getMax(vector<int>& arr)
{
    int max = INT32_MIN;
    int len = arr.size();
    for(int i = 0; i < len; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(vector<int>& arr, int size, int exp, int base)
{
    
    vector<int> rez(size);
    vector<int> count(base, 0);
 
    for(int i = 0; i < size; ++i)
        count[(arr[i] / exp) % base]++;

    for(int i = 1; i < base; ++i)
        count[i] += count[i - 1];
 
    for(int i = size - 1; i >= 0; --i)
    {
        rez[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }

    for (int i = 0; i < size; ++i)
        arr[i] = rez[i];
}

void radixsort(vector<int>& arr, int n, int base)
{
    int m = getMax(arr);

    for(int exp = 1; m / exp > 0; exp *= base)
        countSort(arr, n, exp, base);
}
