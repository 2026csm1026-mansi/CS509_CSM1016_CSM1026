#include "connected_components.h"
#include <queue>

std::vector<int> findConnectedComponents(const CSRGraph& graph)
{
    int vertices = static_cast<int>(graph.row_ptr.size()) - 1;
    std::vector<int> component(vertices, -1);

    int componentID = 0;

    for (int start = 0; start < vertices; start++)
    {
        if (component[start] != -1)
        {
            continue;
        }

        std::queue<int> bfsQueue;

        component[start] = componentID;
        bfsQueue.push(start);

        while (!bfsQueue.empty())
        {
            int current = bfsQueue.front();
            bfsQueue.pop();

            for (int index = graph.row_ptr[current];
                 index < graph.row_ptr[current + 1];
                 index++)
            {
                int neighbour = graph.col_idx[index];

                if (component[neighbour] == -1)
                {
                    component[neighbour] = componentID;
                    bfsQueue.push(neighbour);
                }
            }
        }

        componentID++;
    }

    return component;
}