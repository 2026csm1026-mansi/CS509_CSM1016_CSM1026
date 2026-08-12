#include <iostream>
#include <vector>

#include "../../assignment_01/src/csr.h"
#include "../src/triangle_counting.h"

int main()
{
    std::vector<std::vector<int>> adjacencyList =
    {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2, 4, 5},
        {3, 5},
        {3, 4}
    };

    CSRGraph graph = convertToCSR(adjacencyList);

    long long triangles = countTriangles(graph);

    std::cout << "Total triangles: "
              << triangles
              << std::endl;

    return 0;
}