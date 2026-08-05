#include "bfs.h"

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(
    const CSRGraph& graph,
    int source
)
{
    int vertices = graph.row_ptr.size() - 1;

    vector<bool> visited(vertices, false);

    queue<int> bfsQueue;

    visited[source] = true;
    bfsQueue.push(source);

    while (!bfsQueue.empty())
    {
        int current = bfsQueue.front();
        bfsQueue.pop();

        cout << current << " ";

        for (int index = graph.row_ptr[current];
             index < graph.row_ptr[current + 1];
             index++)
        {
            int neighbour = graph.col_idx[index];

            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                bfsQueue.push(neighbour);
            }
        }
    }

    cout << endl;
}