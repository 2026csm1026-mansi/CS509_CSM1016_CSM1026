#include "dfs.h"

#include <iostream>
#include <vector>

using namespace std;

void DFSUtil(
    int current,
    const CSRGraph& graph,
    vector<bool>& visited
)
{
    visited[current] = true;

    if (graph.row_ptr.size() - 1 <= 100)
{
    cout << current << " ";
}

    for (int index = graph.row_ptr[current];
         index < graph.row_ptr[current + 1];
         index++)
    {
        int neighbour = graph.col_idx[index];

        if (!visited[neighbour])
        {
            DFSUtil(
                neighbour,
                graph,
                visited
            );
        }
    }
}

void DFS(
    const CSRGraph& graph,
    int source
)
{
    int vertices = graph.row_ptr.size() - 1;

    vector<bool> visited(vertices, false);

    DFSUtil(
        source,
        graph,
        visited
    );

    cout << endl;
}