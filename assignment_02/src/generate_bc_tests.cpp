#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <filesystem>

using namespace std;

// Generate an undirected graph with V vertices and E edges.
void generateBCGraph(int V, int E, const string& filename)
{
    vector<vector<int>> adjacencyList(V);

    mt19937 rng(42);

    uniform_int_distribution<int> vertexDist(0, V - 1);

    int edgesAdded = 0;

    while (edgesAdded < E)
    {
        int u = vertexDist(rng);
        int v = vertexDist(rng);

        if (u == v)
        {
            continue;
        }

        bool alreadyExists = false;

        for (int neighbour : adjacencyList[u])
        {
            if (neighbour == v)
            {
                alreadyExists = true;
                break;
            }
        }

        if (alreadyExists)
        {
            continue;
        }

        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);

        edgesAdded++;
    }

    filesystem::create_directories("assignment_02/tests");

    ofstream output(filename);

    if (!output.is_open())
    {
        cerr << "Could not open file: "
             << filename << endl;
        return;
    }

    output << V << " " << E << "\n";

    for (int u = 0; u < V; u++)
    {
        output << u << " "
               << adjacencyList[u].size();

        for (int v : adjacencyList[u])
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
    // Betweenness Centrality
    generateBCGraph(
        10,
        20,
        "assignment_02/tests/bc_10.txt"
    );

    generateBCGraph(
        100,
        300,
        "assignment_02/tests/bc_100.txt"
    );

    generateBCGraph(
        1000,
        3000,
        "assignment_02/tests/bc_1000.txt"
    );

    generateBCGraph(
        5000,
        15000,
        "assignment_02/tests/bc_5000.txt"
    );

    generateBCGraph(
        10000,
        30000,
        "assignment_02/tests/bc_10000.txt"
    );

    return 0;
}