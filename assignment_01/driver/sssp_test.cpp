#include "../src/csr.h"
#include "../src/sssp.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <limits>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./sssp_test <input_file>\n";
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file)
    {
        std::cerr << "Error: Could not open input file.\n";
        return 1;
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

    std::string sourceLabel;
    int source;

    file >> sourceLabel >> source;

    CSRGraph graph = convertToCSR(adjacencyList);

    auto start = std::chrono::steady_clock::now();

    std::vector<long long> distances = sssp(graph, source);
    auto end = std::chrono::steady_clock::now();

    double executionTime =
        std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Algorithm: SSSP\n";
    std::cout << "Source: " << source << "\n";
    std::cout << "Vertices: " << V << "\n";
    std::cout << "Edges: " << E << "\n";
    if (V <= 100)
    {
        std::cout << "Vertex Distance\n";

        for (int i = 0; i < V; i++)
        {
            std::cout << i << " ";

            if (distances[i] == std::numeric_limits<long long>::max())
                std::cout << "INF\n";
            else
                std::cout << distances[i] << "\n";
        }
    }
    else
    {
        std::cout << "Distances: first 10 and last 10 vertices\n";

        for (int i = 0; i < 10; i++)
        {
            std::cout << i << " ";

            if (distances[i] == std::numeric_limits<long long>::max())
                std::cout << "INF\n";
            else
                std::cout << distances[i] << "\n";
        }

        std::cout << "...\n";

        for (int i = V - 10; i < V; i++)
        {
            std::cout << i << " ";

            if (distances[i] == std::numeric_limits<long long>::max())
                std::cout << "INF\n";
            else
                std::cout << distances[i] << "\n";
        }
    }

    std::cout << "Execution time: "
              << executionTime << " ms\n";

    return 0;
}

