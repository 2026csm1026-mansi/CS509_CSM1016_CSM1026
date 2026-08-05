#include "../src/csr.h"
#include "../src/sssp.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <limits>

using namespace std;

void runSSSP();
void runBFS();
void runDFS();

int main()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "       CS509 Laboratory Wrapper\n";
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


// =====================================================
// BFS
// =====================================================

void runBFS()
{
    cout << "\n========== BFS ==========\n";
    cout << "BFS module will be added here.\n";
}


// =====================================================
// DFS
// =====================================================

void runDFS()
{
    cout << "\n========== DFS ==========\n";
    cout << "DFS module will be added here.\n";
}


// =====================================================
// SSSP
// =====================================================

void runSSSP()
{
    int testChoice;
    string filename;

    cout << "\n========== SSSP ==========\n";
    cout << "1. sssp_10.txt\n";
    cout << "2. sssp_100.txt\n";
    cout << "3. sssp_10000.txt\n";
    cout << "4. sssp_50000.txt\n";
    cout << "5. sssp_100000.txt\n";
    cout << "0. Back\n";

    cout << "\nEnter your choice: ";
    cin >> testChoice;

    if (testChoice == 0)
        return;

    switch (testChoice)
    {
        case 1:
            filename = "assignment_01/tests/sssp_10.txt";
            break;

        case 2:
            filename = "assignment_01/tests/sssp_100.txt";
            break;

        case 3:
            filename = "assignment_01/tests/sssp_10000.txt";
            break;

        case 4:
            filename = "assignment_01/tests/sssp_50000.txt";
            break;

        case 5:
            filename = "assignment_01/tests/sssp_100000.txt";
            break;

        default:
            cout << "\nInvalid Test Case!\n";
            return;
    }

    ifstream file(filename);

    if (!file)
    {
        cout << "\nError opening input file.\n";
        return;
    }

    int V, E;
    file >> V >> E;

    WeightedAdjList adjacencyList(V);

    for (int i = 0; i < V; i++)
    {
        int u, degree;
        file >> u >> degree;

        for (int j = 0; j < degree; j++)
        {
            int neighbour, weight;
            file >> neighbour >> weight;

            adjacencyList[u].push_back({neighbour, weight});
        }
    }

    string sourceLabel;
    int source;

    file >> sourceLabel >> source;

    // CSR conversion is preprocessing and is NOT timed.
    CSRGraph graph = convertToCSR(adjacencyList);

    // Only SSSP execution is timed.
    auto start = chrono::steady_clock::now();

    vector<long long> distances = sssp(graph, source);

    auto end = chrono::steady_clock::now();

    double executionTime =
        chrono::duration<double, milli>(end - start).count();

    cout << "\n========== SSSP Result ==========\n";
    cout << "Algorithm: Dijkstra SSSP\n";
    cout << "Vertices: " << V << "\n";
    cout << "Edges: " << E << "\n";
    cout << "Source: " << source << "\n";

    cout << "\nVertex Distance\n";

    cout << "\nDistances:\n";

    if (V <= 100)
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " ";

            if (distances[i] == numeric_limits<long long>::max())
                cout << "INF\n";
            else
                cout << distances[i] << "\n";
        }
    }
    else
    {
        cout << "First 10 vertices:\n";

        for (int i = 0; i < 10; i++)
        {
            cout << i << " ";

            if (distances[i] == numeric_limits<long long>::max())
                cout << "INF\n";
            else
                cout << distances[i] << "\n";
        }

        cout << "...\n";
        cout << "Last 10 vertices:\n";

        for (int i = V - 10; i < V; i++)
        {
            cout << i << " ";

            if (distances[i] == numeric_limits<long long>::max())
                cout << "INF\n";
            else
                cout << distances[i] << "\n";
        }
    }

        cout << "\nExecution time: "
            << executionTime
            << " ms\n";
    }