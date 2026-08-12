#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <chrono>

#include "../../assignment_01/src/csr.h"
#include "../src/betweenness_centrality.h"

using namespace std;

bool readUndirectedGraph(
    const string& filename,
    vector<vector<int>>& adjacencyList,
    int& vertices,
    int& edges)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open input file: "
             << filename << endl;
        return false;
    }

    if (!(inputFile >> vertices >> edges))
    {
        cerr << "Error: Invalid graph header." << endl;
        return false;
    }

    if (vertices < 0 || edges < 0)
    {
        cerr << "Error: Invalid number of vertices or edges." << endl;
        return false;
    }

    adjacencyList.resize(vertices);

    for (int i = 0; i < vertices; i++)
    {
        int vertex;
        int degree;

        if (!(inputFile >> vertex >> degree))
        {
            cerr << "Error: Invalid adjacency-list entry." << endl;
            return false;
        }

        if (vertex < 0 || vertex >= vertices || degree < 0)
        {
            cerr << "Error: Invalid vertex or degree." << endl;
            return false;
        }

        for (int j = 0; j < degree; j++)
        {
            int neighbour;

            if (!(inputFile >> neighbour))
            {
                cerr << "Error: Missing neighbour." << endl;
                return false;
            }

            if (neighbour < 0 || neighbour >= vertices)
            {
                cerr << "Error: Invalid neighbour vertex." << endl;
                return false;
            }

            adjacencyList[vertex].push_back(neighbour);
        }
    }

    inputFile.close();

    return true;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: bc_test.exe <input_file>" << endl;
        return 1;
    }

    string filename = argv[1];

    vector<vector<int>> adjacencyList;

    int vertices;
    int edges;

    if (!readUndirectedGraph(
            filename,
            adjacencyList,
            vertices,
            edges))
    {
        return 1;
    }

    // CSR conversion is preprocessing and is therefore
    // performed before the timer starts.
    CSRGraph graph = convertToCSR(adjacencyList);

    auto start = chrono::high_resolution_clock::now();

    vector<double> centrality =
        calculateBetweennessCentrality(graph);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed = end - start;

    cout << "Algorithm: Betweenness Centrality\n";
    cout << "Vertex Centrality\n";

    cout << fixed << setprecision(2);

    for (int i = 0; i < vertices; i++)
    {
        cout << i << " "
             << centrality[i]
             << "\n";
    }

    cout << fixed << setprecision(3);
    cout << "Execution time: "
         << elapsed.count()
         << " ms\n";

    return 0;
}