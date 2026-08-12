#include "triangle_counting.h"

long long countTriangles(const CSRGraph& graph)
{
    int vertices = static_cast<int>(graph.row_ptr.size()) - 1;

    long long triangleCount = 0;

    for (int u = 0; u < vertices; u++)
    {
        int startU = graph.row_ptr[u];
        int endU = graph.row_ptr[u + 1];
        for (int i = startU; i < endU; i++)
        {
            int v = graph.col_idx[i];

            for (int j = i + 1; j < endU; j++)
            {
                int w = graph.col_idx[j];
                int startV = graph.row_ptr[v];
                int endV = graph.row_ptr[v + 1];

                for (int k = startV; k < endV; k++)
                {
                    if (graph.col_idx[k] == w)
                    {
                        triangleCount++;
                        break;
                    }
                }
            }
        }
    }
    return triangleCount / 3;
}