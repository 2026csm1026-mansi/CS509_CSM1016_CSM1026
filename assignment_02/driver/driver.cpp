/*#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include "../../assignment_01/src/csr.h"
#include "../src/triangle_counting.h"
#include "../src/connected_components.h"

using namespace std;

bool readUndirectedGraph(const string& filename,vector<vector<int>>& adjacencyList,int& vertices,int& edges)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open input file: "
             << filename << endl;

        return false;
    }

    if (!(inputFile >> vertices >> edges))
    {
        cerr << "Error: Invalid graph header." << endl;
        return false;
    }

    if (vertices < 0 || edges < 0)
    {
        cerr << "Error: Invalid number of vertices or edges." << endl;
        return false;
    }

    adjacencyList.resize(vertices);
    for (int i = 0; i < vertices; i++)
    {
        int vertex;
        int degree;

        if (!(inputFile >> vertex >> degree))
        {
            cerr << "Error: Invalid adjacency-list entry." << endl;
            return false;
        }

        if (vertex < 0 || vertex >= vertices || degree < 0)
        {
            cerr << "Error: Invalid vertex or degree." << endl;
            return false;
        }

        for (int j = 0; j < degree; j++)
        {
            int neighbour;

            if (!(inputFile >> neighbour))
            {
                cerr << "Error: Missing neighbour." << endl;
                return false;
            }

            if (neighbour < 0 || neighbour >= vertices)
            {
                cerr << "Error: Invalid neighbour vertex." << endl;
                return false;
            }

            adjacencyList[vertex].push_back(neighbour);
        }
    }

    inputFile.close();

    return true;
}
void printUsage()
{
    cout << "Usage:\n";
    cout << "  assignment2.exe tc <input_file>\n";
    cout << "  assignment2.exe cc <input_file>\n";
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printUsage();
        return 1;
    }

    string algorithm = argv[1];
    string filename = argv[2];

    if (algorithm != "tc" && algorithm != "cc")
    {
        cerr << "Error: Unknown algorithm '" << algorithm << "'." << endl;
        printUsage();
        return 1;
    }
    vector<vector<int>> adjacencyList;

    int vertices;
    int edges;

    if (!readUndirectedGraph(
            filename,
            adjacencyList,
            vertices,
            edges))
    {
        return 1;
    }
    CSRGraph graph = convertToCSR(adjacencyList);
    if (algorithm == "tc")
    {
        auto start = chrono::high_resolution_clock::now();
        long long triangles = countTriangles(graph);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> elapsed = end - start;


        cout << "Algorithm: Triangle Counting\n";
        cout << "Total triangles: " << triangles << "\n";
        cout << fixed << setprecision(3);
        cout << "Execution time: "
             << elapsed.count()
             << " ms\n";
    }
    else if (algorithm == "cc")
    {
        auto start = chrono::high_resolution_clock::now();

        vector<int> components =findConnectedComponents(graph);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> elapsed = end - start;
        int numberOfComponents = 0;

        for (int component : components)
        {
            if (component + 1 > numberOfComponents)
            {
                numberOfComponents = component + 1;
            }
        }


        cout << "Algorithm: Connected Components\n";
        cout << "Number of components: "<< numberOfComponents<< "\n\n";
        if (vertices <= 100)
        {
            cout << "Vertex Component\n";

            for (int i = 0; i < vertices; i++)
            {
                cout << i << " "
                     << components[i]
                     << "\n";
            }
        }
        else
        {
            cout << "First 10 vertices:\n";
            cout << "Vertex Component\n";

            for (int i = 0; i < 10; i++)
            {
                cout << i << " "
                     << components[i]
                     << "\n";
            }

            cout << "...\n";

            cout << "Last 10 vertices:\n";
            cout << "Vertex Component\n";

            for (int i = vertices - 10;i < vertices;i++)
            {
                cout << i << " "
                     << components[i]
                     << "\n";
            }
        }
        cout << fixed << setprecision(3);
        cout << "Execution time: "
             << elapsed.count()
             << " ms\n";
    }
    return 0;
}*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>

#include "../../assignment_01/src/csr.h"
#include "../src/triangle_counting.h"
#include "../src/connected_components.h"
#include "../src/betweenness_centrality.h"

using namespace std;


bool readUndirectedGraph(
    const string& filename,
    vector<vector<int>>& adjacencyList,
    int& vertices,
    int& edges)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open input file: "
             << filename << endl;

        return false;
    }

    if (!(inputFile >> vertices >> edges))
    {
        cerr << "Error: Invalid graph header." << endl;
        return false;
    }

    if (vertices < 0 || edges < 0)
    {
        cerr << "Error: Invalid number of vertices or edges." << endl;
        return false;
    }

    adjacencyList.resize(vertices);

    for (int i = 0; i < vertices; i++)
    {
        int vertex;
        int degree;

        if (!(inputFile >> vertex >> degree))
        {
            cerr << "Error: Invalid adjacency-list entry." << endl;
            return false;
        }

        if (vertex < 0 || vertex >= vertices || degree < 0)
        {
            cerr << "Error: Invalid vertex or degree." << endl;
            return false;
        }

        for (int j = 0; j < degree; j++)
        {
            int neighbour;

            if (!(inputFile >> neighbour))
            {
                cerr << "Error: Missing neighbour." << endl;
                return false;
            }

            if (neighbour < 0 || neighbour >= vertices)
            {
                cerr << "Error: Invalid neighbour vertex." << endl;
                return false;
            }

            adjacencyList[vertex].push_back(neighbour);
        }
    }

    inputFile.close();

    return true;
}


void printUsage()
{
    cout << "Usage:\n";
    cout << "  assignment2.exe tc <input_file>\n";
    cout << "  assignment2.exe cc <input_file>\n";
    cout << "  assignment2.exe bc <input_file>\n";
}


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printUsage();
        return 1;
    }

    string algorithm = argv[1];
    string filename = argv[2];

    if (algorithm != "tc" &&
        algorithm != "cc" &&
        algorithm != "bc")
    {
        cerr << "Error: Unknown algorithm '"
             << algorithm << "'." << endl;

        printUsage();
        return 1;
    }

    vector<vector<int>> adjacencyList;

    int vertices;
    int edges;

    if (!readUndirectedGraph(
            filename,
            adjacencyList,
            vertices,
            edges))
    {
        return 1;
    }

    // CSR conversion is preprocessing and is not included
    // in algorithm execution time.
    CSRGraph graph = convertToCSR(adjacencyList);


    if (algorithm == "tc")
    {
        auto start = chrono::high_resolution_clock::now();

        long long triangles = countTriangles(graph);

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> elapsed = end - start;

        cout << "Algorithm: Triangle Counting\n";
        cout << "Total triangles: " << triangles << "\n";

        cout << fixed << setprecision(3);

        cout << "Execution time: "
             << elapsed.count()
             << " ms\n";
    }


    else if (algorithm == "cc")
    {
        auto start = chrono::high_resolution_clock::now();

        vector<int> components =
            findConnectedComponents(graph);

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> elapsed =
            end - start;

        int numberOfComponents = 0;

        for (int component : components)
        {
            if (component + 1 > numberOfComponents)
            {
                numberOfComponents = component + 1;
            }
        }

        cout << "Algorithm: Connected Components\n";
        cout << "Number of components: "
             << numberOfComponents
             << "\n\n";

        if (vertices <= 100)
        {
            cout << "Vertex Component\n";

            for (int i = 0; i < vertices; i++)
            {
                cout << i << " "
                     << components[i]
                     << "\n";
            }
        }
        else
        {
            cout << "First 10 vertices:\n";
            cout << "Vertex Component\n";

            for (int i = 0; i < 10; i++)
            {
                cout << i << " "
                     << components[i]
                     << "\n";
            }

            cout << "...\n";

            cout << "Last 10 vertices:\n";
            cout << "Vertex Component\n";

            for (int i = vertices - 10;
                 i < vertices;
                 i++)
            {
                cout << i << " "
                     << components[i]
                     << "\n";
            }
        }

        cout << fixed << setprecision(3);

        cout << "Execution time: "
             << elapsed.count()
             << " ms\n";
    }


    else if (algorithm == "bc")
    {
        auto start = chrono::high_resolution_clock::now();

        vector<double> centrality =
            calculateBetweennessCentrality(graph);

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> elapsed =
            end - start;

        cout << "Algorithm: Betweenness Centrality\n";
        cout << "Vertex Centrality\n";

        cout << fixed << setprecision(2);

        for (int i = 0; i < vertices; i++)
        {
            cout << i << " "
                 << centrality[i]
                 << "\n";
        }

        cout << fixed << setprecision(3);

        cout << "Execution time: "
             << elapsed.count()
             << " ms\n";
    }

    return 0;
}