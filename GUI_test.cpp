#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

// Function to clear screen
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to display GUI
void displayGUI(const std::vector<int> &arr)
{
    clearScreen();

    // Print title
    std::cout << "Bogo Sort Visualization" << std::endl;
    std::cout << "-----------------------" << std::endl;

    // Print array
    std::cout << "Array: ";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Sleep for visualization
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

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
    srand(time(0));
    std::random_shuffle(arr.begin(), arr.end());
}

// Function to perform Bogo Sort
void bogoSort(std::vector<int> &arr)
{
    srand(time(0)); // Seed for random number generation
    while (!isSorted(arr))
    {
        shuffleArray(arr);
        displayGUI(arr);
    }
}

int main()
{
    const int SIZE = 5; // Adjust array size as needed
    std::vector<int> arr(SIZE);

    // Generate random values
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = rand() % 1000; // Values between 0 and 999
    }

    bogoSort(arr);

    std::cout << "Bogo Sort completed!" << std::endl;

    return 0;
}
