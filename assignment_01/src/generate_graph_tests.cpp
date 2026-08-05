#include <fstream>
#include <iostream>
#include <random>

using namespace std;

void generateGraph(const string& filename, int vertices)
{
    ofstream out(filename);

    out << vertices << "\n";

    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < vertices; i++)
    {
        int maxNeighbours = min(5, vertices - 1);

        uniform_int_distribution<> neighbourCount(1, maxNeighbours);
        int edges = neighbourCount(gen);

        out << edges << " ";

        uniform_int_distribution<> vertex(0, vertices - 1);

        for (int j = 0; j < edges; j++)
        {
            int v;

            do
            {
                v = vertex(gen);
            }
            while (v == i);

            out << v << " ";
        }

        out << "\n";
    }

    out.close();

    cout << filename << " generated.\n";
}

int main()
{generateGraph("assignment_01/tests/graph_10.txt", 10);
generateGraph("assignment_01/tests/graph_100.txt", 100);
generateGraph("assignment_01/tests/graph_10000.txt", 10000);
generateGraph("assignment_01/tests/graph_50000.txt", 50000);
generateGraph("assignment_01/tests/graph_100000.txt", 100000);

    return 0;
}