#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


// =====================================================
// Run Assignment 2 driver
// =====================================================

void runAlgorithm(const string& algorithm, const string& filename)
{
    string command =
        "assignment2.exe " + algorithm + " \"" + filename + "\"";

    int result = system(command.c_str());

    if (result != 0)
    {
        cout << "\nError: Could not execute assignment2.exe.\n";
    }
}


// =====================================================
// Triangle Counting
// =====================================================

void runTriangleCounting()
{
    int testChoice;
    string filename;

    cout << "\n========== Triangle Counting ==========\n";
    cout << "1. tc_10.txt\n";
    cout << "2. tc_100.txt\n";
    cout << "3. tc_10000.txt\n";
    cout << "4. tc_50000.txt\n";
    cout << "5. tc_100000.txt\n";
    cout << "0. Back\n";

    cout << "\nEnter your choice: ";
    cin >> testChoice;

    if (testChoice == 0)
        return;

    switch (testChoice)
    {
        case 1:
            filename = "assignment_02/tests/tc_10.txt";
            break;

        case 2:
            filename = "assignment_02/tests/tc_100.txt";
            break;

        case 3:
            filename = "assignment_02/tests/tc_10000.txt";
            break;

        case 4:
            filename = "assignment_02/tests/tc_50000.txt";
            break;

        case 5:
            filename = "assignment_02/tests/tc_100000.txt";
            break;

        default:
            cout << "\nInvalid Test Case!\n";
            return;
    }

    runAlgorithm("tc", filename);
}


// =====================================================
// Connected Components
// =====================================================

void runConnectedComponents()
{
    int testChoice;
    string filename;

    cout << "\n========== Connected Components ==========\n";
    cout << "1. cc_10.txt\n";
    cout << "2. cc_100.txt\n";
    cout << "3. cc_10000.txt\n";
    cout << "4. cc_50000.txt\n";
    cout << "5. cc_100000.txt\n";
    cout << "0. Back\n";

    cout << "\nEnter your choice: ";
    cin >> testChoice;

    if (testChoice == 0)
        return;

    switch (testChoice)
    {
        case 1:
            filename = "assignment_02/tests/cc_10.txt";
            break;

        case 2:
            filename = "assignment_02/tests/cc_100.txt";
            break;

        case 3:
            filename = "assignment_02/tests/cc_10000.txt";
            break;

        case 4:
            filename = "assignment_02/tests/cc_50000.txt";
            break;

        case 5:
            filename = "assignment_02/tests/cc_100000.txt";
            break;

        default:
            cout << "\nInvalid Test Case!\n";
            return;
    }

    runAlgorithm("cc", filename);
}


// =====================================================
// Betweenness Centrality
// =====================================================

void runBetweennessCentrality()
{
    int testChoice;
    string filename;

    cout << "\n========== Betweenness Centrality ==========\n";
    cout << "1. bc_10.txt\n";
    cout << "2. bc_100.txt\n";
    cout << "3. bc_1000.txt\n";
    cout << "4. bc_5000.txt\n";
    cout << "5. bc_10000.txt\n";
    cout << "0. Back\n";

    cout << "\nEnter your choice: ";
    cin >> testChoice;

    if (testChoice == 0)
        return;

    switch (testChoice)
    {
        case 1:
            filename = "assignment_02/tests/bc_10.txt";
            break;

        case 2:
            filename = "assignment_02/tests/bc_100.txt";
            break;

        case 3:
            filename = "assignment_02/tests/bc_1000.txt";
            break;

        case 4:
            filename = "assignment_02/tests/bc_5000.txt";
            break;

        case 5:
            filename = "assignment_02/tests/bc_10000.txt";
            break;

        default:
            cout << "\nInvalid Test Case!\n";
            return;
    }

    runAlgorithm("bc", filename);
}


// =====================================================
// Main Assignment 2 Wrapper
// =====================================================

int main()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "       CS509 Assignment 2 Wrapper\n";
        cout << "=====================================\n";

        cout << "1. Triangle Counting\n";
        cout << "2. Connected Components\n";
        cout << "3. Betweenness Centrality\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                runTriangleCounting();
                break;

            case 2:
                runConnectedComponents();
                break;

            case 3:
                runBetweennessCentrality();
                break;

            case 0:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}