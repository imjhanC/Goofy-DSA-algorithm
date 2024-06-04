#include <iostream>
using namespace std;

int main()
{
    // Create a buffer with a size of 5 integers
    int buffer[5];

    // Attempt to write beyond the end of the buffer
    for (int i = 0; i <= 5; ++i)
    {
        buffer[i] = i; // Buffer overflow occurs here
    }

    // Print out the contents of the buffer
    for (int i = 0; i < 10; ++i)
    {
        cout << buffer[i] << " "; // This may print unexpected values due to buffer overflow
    }
    cout << endl;

    return 0;
}
