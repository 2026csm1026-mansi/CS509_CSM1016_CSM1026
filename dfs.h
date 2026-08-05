#ifndef DFS_H
#define DFS_H

#include <vector>

using namespace std;

void DFS(
    const vector<int>& rowPtr,
    const vector<int>& colIndex,
    int vertices,
    int source
);

#endif