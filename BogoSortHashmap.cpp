#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

// Function to check if the array is sorted
bool isSorted(const std::vector<std::pair<int, int>> &arr)
{
    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i].first < arr[i - 1].first)
        {
            return false;
        }
    }
    return true;
}

// Function to shuffle the array randomly
void shuffleArray(std::vector<std::pair<int, int>> &arr)
{
    std::random_shuffle(arr.begin(), arr.end());
}

// Function to perform Bogo Sort
void bogoSort(std::vector<std::pair<int, int>> &arr)
{
    srand(time(0)); // Seed for random number generation
    while (!isSorted(arr))
    {
        shuffleArray(arr);

        // Clear screen
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        // Print the array
        for (size_t i = 0; i < arr.size(); ++i)
        {
            std::cout << arr[i].first << " ";
        }
        std::cout << std::endl;

        // Pause for visualization
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    const int SIZE = 3;
    std::vector<std::pair<int, int>> arr(SIZE);

    // Generate random values
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = {rand() % 1000, i}; // Values between 0 and 999
    }

    auto startTime = std::chrono::high_resolution_clock::now(); // Start time

    bogoSort(arr);

    auto endTime = std::chrono::high_resolution_clock::now(); // End time
    std::chrono::duration<double> duration = endTime - startTime;

    std::cout << "Bogo Sort completed in " << duration.count() << " seconds." << std::endl;

    return 0;
}
