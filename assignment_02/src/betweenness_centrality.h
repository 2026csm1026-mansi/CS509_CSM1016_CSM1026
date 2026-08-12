#ifndef BETWEENNESS_CENTRALITY_H
#define BETWEENNESS_CENTRALITY_H

#include <vector>
#include "../../assignment_01/src/csr.h"

std::vector<double> calculateBetweennessCentrality(const CSRGraph& graph);

#endif