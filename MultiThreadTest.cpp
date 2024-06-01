#include <iostream>
#include <thread>
#include <vector>

// Function that will be executed by each thread
void threadFunction(int threadID, int iterations)
{
    for (int i = 0; i < iterations; ++i)
    {
        std::cout << "Thread " << threadID << " iteration " << i << std::endl;
    }
}

int main()
{
    const int numThreads = std::thread::hardware_concurrency(); // Get the number of hardware threads available

    std::vector<std::thread> threads;

    const int iterations = 10;

    // Create and start threads
    for (int i = 0; i < numThreads; ++i)
    {
        threads.emplace_back(threadFunction, i, iterations);
    }

    // Join threads
    for (auto &thread : threads)
    {
        thread.join();
    }

    return 0;
}
