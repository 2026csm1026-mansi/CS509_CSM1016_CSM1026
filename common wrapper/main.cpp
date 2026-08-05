#include "csr1.h"
#include "bfs.h"
#include "dfs.h"

#include <vector>
#include <string>
#include <chrono>
#include <iostream>

using namespace std;

void runBFS();
void runDFS();
void runSSSP();

int main()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "       CS509 Assignment 2\n";
        cout << "=====================================\n";
        cout << "1. BFS\n";
        cout << "2. DFS\n";
        cout << "3. SSSP\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                runBFS();
                break;

            case 2:
                runDFS();
                break;

            case 3:
                runSSSP();
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

void runBFS()
{
    int testChoice;
    string filename;

    cout << "\n========== BFS ==========\n";
    cout << "1. graph_10.txt\n";
    cout << "2. graph_100.txt\n";
    cout << "3. graph_10000.txt\n";
    cout << "4. graph_50000.txt\n";
    cout << "5. graph_100000.txt\n";
    cout << "0. Back\n";

    cout << "\nEnter your choice: ";
    cin >> testChoice;

    if (testChoice == 0)
        return;

    switch (testChoice)
    {
        case 1:
            filename = "input/graph_10.txt";
            break;

        case 2:
            filename = "input/graph_100.txt";
            break;

        case 3:
            filename = "input/graph_10000.txt";
            break;

        case 4:
            filename = "input/graph_50000.txt";
            break;

        case 5:
            filename = "input/graph_100000.txt";
            break;

        default:
            cout << "\nInvalid Test Case!\n";
            return;
    }

    vector<vector<int>> adjacencyList;
    int vertices;

    if (!readGraph(filename,
                   adjacencyList,
                   vertices))
    {
        cout << "\nError opening input file.\n";
        return;
    }

    // CSR conversion (NOT TIMED)
    CSRGraph graph = convertToCSR(adjacencyList);

    int source;

    cout << "\nEnter Source Vertex: ";
    cin >> source;

    auto start = chrono::high_resolution_clock::now();

    BFS(graph,
        source);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> executionTime = end - start;

    cout << "\nExecution Time: "
         << executionTime.count()
         << " ms\n";
}

void runDFS()
{
    int testChoice;
    string filename;

    cout << "\n========== DFS ==========\n";
    cout << "1. graph_10.txt\n";
    cout << "2. graph_100.txt\n";
    cout << "3. graph_10000.txt\n";
    cout << "4. graph_50000.txt\n";
    cout << "5. graph_100000.txt\n";
    cout << "0. Back\n";

    cout << "\nEnter your choice: ";
    cin >> testChoice;

    if (testChoice == 0)
        return;

    switch (testChoice)
    {
        case 1:
            filename = "input/graph_10.txt";
            break;

        case 2:
            filename = "input/graph_100.txt";
            break;

        case 3:
            filename = "input/graph_10000.txt";
            break;

        case 4:
            filename = "input/graph_50000.txt";
            break;

        case 5:
            filename = "input/graph_100000.txt";
            break;

        default:
            cout << "\nInvalid Test Case!\n";
            return;
    }

    vector<vector<int>> adjacencyList;
    int vertices;

    if (!readGraph(filename,
                   adjacencyList,
                   vertices))
    {
        cout << "\nError opening input file.\n";
        return;
    }

    // CSR conversion (NOT TIMED)
    CSRGraph graph = convertToCSR(adjacencyList);

    int source;

    cout << "\nEnter Source Vertex: ";
    cin >> source;

    auto start = chrono::high_resolution_clock::now();

    DFS(graph,
        source);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> executionTime = end - start;

    cout << "\nExecution Time: "
         << executionTime.count()
         << " ms\n";
}

void runSSSP()
{
    cout << "\nSSSP module not implemented yet.\n";
}