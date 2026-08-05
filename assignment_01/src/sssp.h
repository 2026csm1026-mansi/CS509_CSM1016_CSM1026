#ifndef SSSP_H
#define SSSP_H

#include <vector>
#include "csr.h"

// Single-Source Shortest Path using Dijkstra's algorithm.
std::vector<long long> sssp(const CSRGraph& graph, int source);

#endif