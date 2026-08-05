#include "../src/csr1.h"
#include "../src/dfs.h"

#include <iostream>
#include <vector>
#include <string>
#include <chrono>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./dfs_test <input_file>\n";
        return 1;
    }

    std::vector<std::vector<int>> adjacencyList;
    int vertices;

    if (!readGraph(argv[1], adjacencyList, vertices))
    {
        std::cerr << "Error: Could not open input file.\n";
        return 1;
    }

    // CSR conversion is preprocessing, so it is NOT timed.
    CSRGraph graph = convertToCSR(adjacencyList);

    int source;

    std::cout << "Enter source vertex: ";
    std::cin >> source;

    // Start timing immediately before DFS.
    auto start = std::chrono::steady_clock::now();

    DFS(graph, source);

    // Stop timing immediately after DFS.
    auto end = std::chrono::steady_clock::now();

    double executionTime =
        std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "\nAlgorithm: DFS\n";
    std::cout << "Source: " << source << "\n";
    std::cout << "Execution time: "
              << executionTime << " ms\n";

    return 0;
}