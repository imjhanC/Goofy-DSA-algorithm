#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right, int depth = 0)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, depth + 1);
    mergeSort(arr, mid + 1, right, depth + 1);

    std::cout << std::string(depth, '\t');
    std::cout << "Merge: [";
    for (int i = left; i <= right; ++i)
    {
        std::cout << arr[i];
        if (i < right)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    merge(arr, left, mid, right);
}

int main()
{
    const int SIZE = 500000;
    std::vector<int> arr(SIZE);

    srand(time(0)); // Seed for random number generation

    // Generate random values
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = rand() % 100; // Values between 0 and 99
    }

    std::cout << "Original array: [";
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << arr[i];
        if (i < SIZE - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    auto startTime = std::chrono::high_resolution_clock::now(); // Start time

    mergeSort(arr, 0, SIZE - 1);

    auto endTime = std::chrono::high_resolution_clock::now(); // End time
    std::chrono::duration<double> duration = endTime - startTime;

    std::cout << "Sorted array: [";
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << arr[i];
        if (i < SIZE - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    std::cout << "Merge Sort completed in " << duration.count() << " seconds." << std::endl;

    return 0;
}
