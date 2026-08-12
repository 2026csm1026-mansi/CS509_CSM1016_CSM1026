#include "betweenness_centrality.h"

#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<double> calculateBetweennessCentrality(const CSRGraph& graph)
{
    int vertices = graph.row_ptr.size() - 1;

    vector<double> centrality(vertices, 0.0);

    // Run Brandes' algorithm from every source vertex
    for (int source = 0; source < vertices; source++)
    {
        // distance[v] = shortest distance from source to v
        vector<int> distance(vertices, -1);

        // sigma[v] = number of shortest paths from source to v
        vector<double> sigma(vertices, 0.0);

        // dependency[v] = dependency accumulated during back-propagation
        vector<double> dependency(vertices, 0.0);

        // predecessors[v] = vertices immediately before v
        // on a shortest path from source
        vector<vector<int>> predecessors(vertices);

        queue<int> bfsQueue;
        stack<int> stack;

        distance[source] = 0;
        sigma[source] = 1.0;

        bfsQueue.push(source);

        // -------------------------------
        // Forward BFS
        // -------------------------------
        while (!bfsQueue.empty())
        {
            int current = bfsQueue.front();
            bfsQueue.pop();

            stack.push(current);

            for (int i = graph.row_ptr[current];
                 i < graph.row_ptr[current + 1];
                 i++)
            {
                int neighbour = graph.col_idx[i];

                // First time visiting neighbour
                if (distance[neighbour] < 0)
                {
                    distance[neighbour] = distance[current] + 1;
                    bfsQueue.push(neighbour);
                }

                // current -> neighbour is part of a shortest path
                if (distance[neighbour] == distance[current] + 1)
                {
                    sigma[neighbour] += sigma[current];
                    predecessors[neighbour].push_back(current);
                }
            }
        }

        // -------------------------------
        // Backward accumulation
        // -------------------------------
        while (!stack.empty())
        {
            int current = stack.top();
            stack.pop();

            for (int predecessor : predecessors[current])
            {
                dependency[predecessor] +=
                    (sigma[predecessor] / sigma[current]) *
                    (1.0 + dependency[current]);
            }

            // The source itself is not counted in its own
            // betweenness centrality.
            if (current != source)
            {
                centrality[current] += dependency[current];
            }
        }
    }
    // For undirected graphs, each shortest-path pair
    // is counted in both directions.
    for (int vertex = 0; vertex < vertices; vertex++)
    {
        centrality[vertex] /= 2.0;
    }
    return centrality;
}