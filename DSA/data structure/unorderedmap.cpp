#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct testDetails
{
    string name;
    double testmarks;
    double avg;

    testDetails(const string &n, double marks, double average) : name(n), testmarks(marks), avg(average) {}
};

// Function to delete a row with a specific name from the vector
void deleteRow(vector<testDetails> &test, const string &nameToDelete)
{
    test.erase(std::remove_if(test.begin(), test.end(), [&](const testDetails &t)
                              { return t.name == nameToDelete; }),
               test.end());
}

int main()
{
    vector<testDetails> test;
    test.emplace_back("Cheng Jia Han", 50.0, 2.4);
    test.emplace_back("Cheng Jia Han1", 60.0, 9.4);
    test.emplace_back("Cheng Jia Han2", 70.0, 8.4);
    test.emplace_back("Cheng Jia Han3", 80.0, 1.4);
    test.emplace_back("Cheng Jia Han4", 90.0, 3.4);

    // Displaying before deletion
    cout << "Before deletion:" << endl;
    for (const auto &t : test)
    {
        cout << t.name << " " << t.testmarks << " " << t.avg << endl;
    }

    // Delete a specific row
    deleteRow(test, "Cheng Jia Han2");

    // Displaying after deletion
    cout << "\nAfter deletion:" << endl;
    for (const auto &t : test)
    {
        cout << t.name << " " << t.testmarks << " " << t.avg << endl;
    }

    return 0;
}
