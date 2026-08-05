#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include <string>

using namespace std;

void generateGraph(const string& filename, int vertices)
{
    ofstream out(filename);

    random_device rd;
    mt19937 gen(rd());

    vector<vector<int>> adjacencyList(vertices);

    int totalEdges = 0;

    for (int i = 0; i < vertices; i++)
    {
        int maxNeighbours = min(5, vertices - 1);

        uniform_int_distribution<> neighbourCount(1, maxNeighbours);
        int degree = neighbourCount(gen);

        uniform_int_distribution<> vertex(0, vertices - 1);

        while ((int)adjacencyList[i].size() < degree)
        {
            int v = vertex(gen);

            if (v == i)
                continue;

            bool exists = false;

            for (int x : adjacencyList[i])
            {
                if (x == v)
                {
                    exists = true;
                    break;
                }
            }

            if (!exists)
            {
                adjacencyList[i].push_back(v);
            }
        }

        totalEdges += degree;
    }

    // Write graph header
    out << vertices << " " << totalEdges << "\n";

    // Write adjacency list
    for (int i = 0; i < vertices; i++)
    {
        out << i << " " << adjacencyList[i].size() << " ";

        for (int neighbour : adjacencyList[i])
        {
            out << neighbour << " ";
        }

        out << "\n";
    }

    // Source vertex
    out << "SOURCE 0\n";

    out.close();

    cout << filename << " generated.\n";
}

int main()
{
    generateGraph("assignment_01/tests/graph_10.txt", 10);
    generateGraph("assignment_01/tests/graph_100.txt", 100);
    generateGraph("assignment_01/tests/graph_10000.txt", 10000);
    generateGraph("assignment_01/tests/graph_50000.txt", 50000);
    generateGraph("assignment_01/tests/graph_100000.txt", 100000);

    return 0;
}