#ifndef BFS_H
#define BFS_H

#include <vector>

using namespace std;

void BFS(
    const vector<int>& rowPtr,
    const vector<int>& colIndex,
    int vertices,
    int source
);

#endif