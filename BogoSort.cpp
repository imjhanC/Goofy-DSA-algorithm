#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

// Function to check if the array is sorted
bool isSorted(const std::vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

// Function to shuffle the array randomly
void shuffleArray(std::vector<int> &arr)
{
    std::random_shuffle(arr.begin(), arr.end());
}

// Function to perform Bogo Sort
void bogoSort(std::vector<int> &arr)
{
    srand(time(0)); // Seed for random number generation
    while (!isSorted(arr))
    {
        shuffleArray(arr);
        system("clear"); // Clear screen
        for (size_t i = 0; i < arr.size(); ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pause for visualization
    }
}

int main()
{
    const int SIZE = 16;
    std::vector<int> arr(SIZE);

    // Generate random values
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = rand() % 1000; // Values between 0 and 999
    }

    auto startTime = std::chrono::high_resolution_clock::now(); // Start time

    bogoSort(arr);

    auto endTime = std::chrono::high_resolution_clock::now(); // End time
    std::chrono::duration<double> duration = endTime - startTime;

    std::cout << "Bogo Sort completed in " << duration.count() << " seconds." << std::endl;

    return 0;
}
