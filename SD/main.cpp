#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "number_generator.h"
#include "merge_sort.h"
#include "radix_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include "tim_sort.h"
#include "verif.h"

using namespace std;

const int MAX = 1073741824; // 2 ^ 30

int main()
{
	int tests;

	ifstream fin("date.in");
	fin >> tests;

	for(int test = 1; test <= tests; ++test)
	{
		int n, max;
		fin >> n >> max;

		vector<int> nums(n), copy(n);

		generator(n, max, nums);

		for(int i = 0; i < n; ++i)
		{
			copy[i] = nums[i];
		}

		if (n > MAX)
		{
			cout << "Prea multe numere\n";
			cout << "Program terminat";
			return 0;
		}
			

		auto start = std::chrono::high_resolution_clock::now();
		mergeSort(nums, 0, n - 1);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "             Merge Sort || Timp executie: " << duration.count() << "ms || " << "Corect: "<< (verifSort(nums) ? "Da" : "Nu") << "\n";

		for (int i = 0; i < n; ++i)
		{
			nums[i] = copy[i];
		}

		start = std::chrono::high_resolution_clock::now();
		heapSort(nums, n);
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "              Heap Sort || Timp executie: " << duration.count() << "ms || " << "Corect: " << (verifSort(nums) ? "Da" : "Nu") << "\n";

		for (int i = 0; i < n; ++i)
		{
			nums[i] = copy[i];
		}

		start = std::chrono::high_resolution_clock::now();
		quickSort(nums, 0, n - 1);
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "             Quick Sort || Timp executie: " << duration.count() << "ms || " << "Corect: " << (verifSort(nums) ? "Da" : "Nu") << "\n";

		for (int i = 0; i < n; ++i)
		{
			nums[i] = copy[i];
		}

		start = std::chrono::high_resolution_clock::now();
		radixsort(nums, n, 10);
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "  Radix Sort in baza 10 || Timp executie: " << duration.count() << "ms || " << "Corect: " << (verifSort(nums) ? "Da" : "Nu") << "\n";

		for (int i = 0; i < n; ++i)
		{
			nums[i] = copy[i];
		}

		start = std::chrono::high_resolution_clock::now();
		radixsort(nums, n, 2 ^ 16);
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "Radix Sort in baza 2^16 || Timp executie: " << duration.count() << "ms || " << "Corect: " << (verifSort(nums) ? "Da" : "Nu") << "\n";

		for (int i = 0; i < n; ++i)
		{
			nums[i] = copy[i];
		}

		start = std::chrono::high_resolution_clock::now();
		timSort(nums, n);
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "               Tim Sort || Timp executie: " << duration.count() << "ms || " << "Corect: " << (verifSort(nums) ? "Da" : "Nu") << "\n";

		cout << "\n";
	}

	return 0;
}
