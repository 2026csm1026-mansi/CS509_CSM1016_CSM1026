#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <filesystem>

using namespace std;

// Generate an undirected graph with V vertices and E edges.
void generateGraph(int V, int E, const string& filename)
{
    vector<vector<int>> adj(V);

    mt19937 rng(42);

    uniform_int_distribution<int> vertexDist(0, V - 1);

    int edgesAdded = 0;

    while (edgesAdded < E)
    {
        int u = vertexDist(rng);
        int v = vertexDist(rng);

        if (u == v)
            continue;

        bool alreadyExists = false;

        for (int neighbour : adj[u])
        {
            if (neighbour == v)
            {
                alreadyExists = true;
                break;
            }
        }

        if (alreadyExists)
            continue;

        adj[u].push_back(v);
        adj[v].push_back(u);

        edgesAdded++;
    }

    // Make sure the tests directory exists.
    filesystem::create_directories("assignment_02/tests");

    ofstream output(filename);

    if (!output.is_open())
    {
        cerr << "Could not open file: " << filename << endl;
        return;
    }

    output << V << " " << E << "\n";

    for (int u = 0; u < V; u++)
    {
        output << u << " " << adj[u].size();

        for (int v : adj[u])
        {
            output << " " << v;
        }

        output << "\n";
    }

    output.close();

    cout << "Generated: " << filename
         << " | V = " << V
         << " | E = " << E << endl;
}


int main()
{
    // Triangle Counting
    generateGraph(
        10000,
        30000,
        "assignment_02/tests/tc_10000.txt"
    );

    generateGraph(
        50000,
        150000,
        "assignment_02/tests/tc_50000.txt"
    );

    generateGraph(
        100000,
        300000,
        "assignment_02/tests/tc_100000.txt"
    );

    // Connected Components
    generateGraph(
        10000,
        30000,
        "assignment_02/tests/cc_10000.txt"
    );

    generateGraph(
        50000,
        150000,
        "assignment_02/tests/cc_50000.txt"
    );

    generateGraph(
        100000,
        300000,
        "assignment_02/tests/cc_100000.txt"
    );

    return 0;
}