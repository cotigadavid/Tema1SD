#pragma once

#include <vector>

using namespace std;

bool verifSort(vector<int>& nums)
{
    int size = nums.size();
    for(int i = 0; i < size - 1; ++i)
    {
        if(nums[i] > nums[i + 1])
        {
            return false;
        }
    }
    return true;
}