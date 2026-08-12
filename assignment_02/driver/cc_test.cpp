#include <iostream>
#include <vector>

#include "../../assignment_01/src/csr.h"
#include "../src/connected_components.h"

int main()
{
    std::vector<std::vector<int>> adjacencyList =
    {
        {1},
        {0, 2},
        {1, 3},
        {2},
        {5},
        {4},
        {},
        {}
    };

    CSRGraph graph = convertToCSR(adjacencyList);

    std::vector<int> components = findConnectedComponents(graph);

    int numberOfComponents = 0;

    for (int component : components)
    {
        if (component + 1 > numberOfComponents)
        {
            numberOfComponents = component + 1;
        }
    }

    std::cout << "Number of components: "
              << numberOfComponents << "\n\n";

    std::cout << "Vertex Component\n";

    for (int i = 0; i < static_cast<int>(components.size()); i++)
    {
        std::cout << i << " "
                  << components[i] << "\n";
    }

    return 0;
}