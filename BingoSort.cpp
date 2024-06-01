#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex printMutex;

// Function to perform Bingo Sort
void bingoSort(std::vector<int> &arr, int start, int end, int threadId)
{
    int max;
    int nextMax;
    int lastMax = arr[end];

    while (true)
    {
        max = *std::max_element(arr.begin() + start, arr.begin() + end + 1);

        if (max == lastMax)
            break;

        nextMax = *std::min_element(arr.begin() + start, arr.begin() + end + 1,
                                    [max](int a, int b)
                                    { return (a > max && (b > max ? a < b : true)); });

        for (int i = start; i <= end; ++i)
        {
            if (arr[i] == max)
            {
                arr[i] = nextMax;
                arr[end--] = max;

                // Visualize the current data being processed
                std::lock_guard<std::mutex> lock(printMutex);
                std::cout << "Thread " << threadId << " processing: ";
                for (int j = start; j <= end; ++j)
                {
                    std::cout << arr[j] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}

// Function to divide the sorting task into multiple threads
void threadedBingoSort(std::vector<int> &arr, int numThreads)
{
    int size = arr.size();
    int chunkSize = size / numThreads;
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i)
    {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? (size - 1) : (start + chunkSize - 1);

        threads.emplace_back(bingoSort, std::ref(arr), start, end, i + 1);
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    // Merge sorted chunks
    std::sort(arr.begin(), arr.end());
}

int main()
{
    const int dataSize = 500000;
    const int numThreads = std::thread::hardware_concurrency();

    // Generate random data
    std::vector<int> data(dataSize);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 1000000);
    std::generate(data.begin(), data.end(), [&]()
                  { return dist(rng); });

    // Measure the time taken for sorting
    auto start = std::chrono::high_resolution_clock::now();
    threadedBingoSort(data, numThreads);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Sorting completed in " << duration.count() << " seconds" << std::endl;

    return 0;
}
