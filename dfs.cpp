#include "dfs.h"

#include <iostream>

using namespace std;

void DFSUtil(
    int current,
    const vector<int>& rowPtr,
    const vector<int>& colIndex,
    vector<bool>& visited
)
{
    visited[current] = true;

    cout << current << " ";

    for (int i = rowPtr[current];
         i < rowPtr[current + 1];
         i++)
    {
        int neighbour = colIndex[i];

        if (!visited[neighbour])
        {
            DFSUtil(
                neighbour,
                rowPtr,
                colIndex,
                visited
            );
        }
    }
}

void DFS(
    const vector<int>& rowPtr,
    const vector<int>& colIndex,
    int vertices,
    int source
)
{
    vector<bool> visited(vertices, false);

    DFSUtil(
        source,
        rowPtr,
        colIndex,
        visited
    );

    cout << endl;
}