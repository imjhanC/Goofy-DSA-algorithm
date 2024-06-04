#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};

    // Element to delete
    int itemToDelete = 3;

    // Using iterator to find and delete the specified item
    for (auto it = vec.begin(); it != vec.end();)
    {
        if (*it == itemToDelete)
        {
            it = vec.erase(it); // erase() returns iterator to the next valid position
        }
        else
        {
            ++it; // Move to the next element
        }
    }

    // Printing the updated vector
    cout << "Vector after deleting " << itemToDelete << ": ";
    for (auto num : vec)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
