#include "sssp.h"
#include <queue>
#include <limits>

std::vector<long long> sssp(const CSRGraph& graph, int source)
{
    int V = graph.row_ptr.size() - 1;

    const long long INF = std::numeric_limits<long long>::max();

    std::vector<long long> dist(V, INF);

    std::priority_queue<
        std::pair<long long, int>,
        std::vector<std::pair<long long, int>>,
        std::greater<std::pair<long long, int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist != dist[u])
            continue;

        for (int i = graph.row_ptr[u]; i < graph.row_ptr[u + 1]; i++)
        {
            int v = graph.col_idx[i];
            int weight = graph.values[i];

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}