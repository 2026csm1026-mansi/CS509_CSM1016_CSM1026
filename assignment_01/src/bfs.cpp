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
    vector<int> distance(vertices, -1);

    queue<int> bfsQueue;

    visited[source] = true;
    distance[source] = 0;

    bfsQueue.push(source);

    while (!bfsQueue.empty())
    {
        int current = bfsQueue.front();
        bfsQueue.pop();

        // Print traversal
        cout << current << " ";

        for (int index = graph.row_ptr[current];
             index < graph.row_ptr[current + 1];
             index++)
        {
            int neighbour = graph.col_idx[index];

            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                distance[neighbour] = distance[current] + 1;
                bfsQueue.push(neighbour);
            }
        }
    }

    cout << "\n\nDistances:\n";

    if (vertices <= 100)
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " ";

            if (distance[i] == -1)
                cout << "INF\n";
            else
                cout << distance[i] << "\n";
        }
    }
    else
    {
        cout << "First 10 vertices:\n";

        for (int i = 0; i < 10; i++)
        {
            cout << i << " ";

            if (distance[i] == -1)
                cout << "INF\n";
            else
                cout << distance[i] << "\n";
        }

        cout << "...\n";

        cout << "Last 10 vertices:\n";

        for (int i = vertices - 10; i < vertices; i++)
        {
            cout << i << " ";

            if (distance[i] == -1)
                cout << "INF\n";
            else
                cout << distance[i] << "\n";
        }
    }

    cout << endl;
}