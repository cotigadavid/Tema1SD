#pragma once

#include <fstream>
#include <random>

using namespace std;

ofstream out("test.txt");

void generator(int n, int max, vector<int>& arr)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, max); 

    for (int i = 0; i < n; i++) {
        int random = dis(gen); 
        arr[i] = random;
    }
    out.close();
}