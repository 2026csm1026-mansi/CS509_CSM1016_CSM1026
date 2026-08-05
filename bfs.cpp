#include "bfs.h"

#include <iostream>
#include <queue>

using namespace std;

void BFS(
    const vector<int>& rowPtr,
    const vector<int>& colIndex,
    int vertices,
    int source
)
{
    vector<bool> visited(vertices, false);

    queue<int> bfsQueue;

    visited[source] = true;
    bfsQueue.push(source);

    while (!bfsQueue.empty())
    {
        int current = bfsQueue.front();
        bfsQueue.pop();

        cout << current << " ";

        for (int i = rowPtr[current];
             i < rowPtr[current + 1];
             i++)
        {
            int neighbour = colIndex[i];

            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                bfsQueue.push(neighbour);
            }
        }
    }

    cout << endl;
}