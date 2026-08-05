#include "csr1.h"

#include <fstream>

using namespace std;

bool readGraph(
    const string& filename,
    vector<vector<int>>& adjacencyList,
    int& vertices
)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        return false;
    }

    inputFile >> vertices;

    adjacencyList.resize(vertices);

    for (int vertex = 0; vertex < vertices; vertex++)
    {
        int neighbours;
        inputFile >> neighbours;

        for (int i = 0; i < neighbours; i++)
        {
            int adjacentVertex;
            inputFile >> adjacentVertex;

            adjacencyList[vertex].push_back(adjacentVertex);
        }
    }

    inputFile.close();

    return true;
}

CSRGraph convertToCSR(const WeightedAdjList& adjacencyList)
{
    CSRGraph graph;

    size_t vertices = adjacencyList.size();

    graph.row_ptr.resize(vertices + 1);

    graph.row_ptr[0] = 0;

    for (size_t i = 0; i < vertices; i++)
    {
        graph.row_ptr[i + 1] =
            graph.row_ptr[i] + adjacencyList[i].size();
    }

    size_t edges = graph.row_ptr[vertices];

    graph.col_idx.reserve(edges);
    graph.values.reserve(edges);

    for (size_t i = 0; i < vertices; i++)
    {
        for (const auto& edge : adjacencyList[i])
        {
            graph.col_idx.push_back(edge.first);
            graph.values.push_back(edge.second);
        }
    }

    return graph;
}

CSRGraph convertToCSR(const vector<vector<int>>& adjacencyList)
{
    CSRGraph graph;

    size_t vertices = adjacencyList.size();

    graph.row_ptr.resize(vertices + 1);

    graph.row_ptr[0] = 0;

    for (size_t i = 0; i < vertices; i++)
    {
        graph.row_ptr[i + 1] =
            graph.row_ptr[i] + adjacencyList[i].size();
    }

    size_t edges = graph.row_ptr[vertices];

    graph.col_idx.reserve(edges);
    graph.values.reserve(edges);

    for (size_t i = 0; i < vertices; i++)
    {
        for (int neighbour : adjacencyList[i])
        {
            graph.col_idx.push_back(neighbour);
            graph.values.push_back(1);
        }
    }

    return graph;
}