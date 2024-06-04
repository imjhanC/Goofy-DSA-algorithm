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

// Function to update the details of a specific row
void updateRow(vector<testDetails> &test, const string &nameToUpdate, double newTestMarks, double newAvg)
{
    auto it = find_if(test.begin(), test.end(), [&](const testDetails &t)
                      { return t.name == nameToUpdate; });

    if (it != test.end())
    {
        it->testmarks = newTestMarks;
        it->avg = newAvg;
    }
}

int main()
{
    vector<testDetails> test;
    test.emplace_back("Cheng Jia Han", 50.0, 2.4);
    test.emplace_back("Cheng Jia Han1", 60.0, 9.4);
    test.emplace_back("Cheng Jia Han2", 70.0, 8.4);
    test.emplace_back("Cheng Jia Han3", 80.0, 1.4);
    test.emplace_back("Cheng Jia Han4", 90.0, 3.4);

    // Displaying before update
    cout << "Before update:" << endl;
    for (const auto &t : test)
    {
        cout << t.name << " " << t.testmarks << " " << t.avg << endl;
    }

    // Update a specific row
    updateRow(test, "Cheng Jia Han", 75.0, 7.8);

    // Displaying after update
    cout << "\nAfter update:" << endl;
    for (const auto &t : test)
    {
        cout << t.name << " " << t.testmarks << " " << t.avg << endl;
    }

    return 0;
}
