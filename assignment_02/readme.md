# CS509 – Assignment 2

## Graph Algorithms

This assignment implements three graph algorithms using the **CSR (Compressed Sparse Row)** graph representation from Assignment 1:

- **Triangle Counting**
- **Connected Components**
- **Betweenness Centrality**

The CSR conversion functions from Assignment 1 are reused for the Assignment 2 algorithms.

---

## Directory Structure

```text
assignment_02/
├── src/
│   ├── triangle_counting.cpp
│   ├── triangle_counting.h
│   ├── connected_components.cpp
│   ├── connected_components.h
│   ├── betweenness_centrality.cpp
│   ├── betweenness_centrality.h
│   ├── generate_graph_tests.cpp
│   └── generate_bc_tests.cpp
│
├── driver/
│   ├── driver.cpp
│   ├── tc_test.cpp
│   ├── cc_test.cpp
│   └── bc_test.cpp
│
└── tests/
    ├── tc_10.txt
    ├── tc_100.txt
    ├── tc_10000.txt
    ├── tc_50000.txt
    ├── tc_100000.txt
    ├── cc_10.txt
    ├── cc_100.txt
    ├── cc_10000.txt
    ├── cc_50000.txt
    ├── cc_100000.txt
    ├── bc_10.txt
    ├── bc_100.txt
    ├── bc_1000.txt
    ├── bc_5000.txt
    └── bc_10000.txt
```

---

## Algorithms

### 1. Triangle Counting

Counts the number of triangles present in an undirected graph represented using CSR format.

### 2. Connected Components

Finds all connected components in an undirected graph using BFS over the CSR representation.

### 3. Betweenness Centrality

Computes the betweenness centrality of every vertex in an undirected, unweighted graph using **Brandes' algorithm**.

The implementation reports the raw, unnormalized centrality value for every vertex to two decimal places.

For an unweighted graph, Brandes' algorithm performs a BFS from every vertex and accumulates the contribution of shortest paths passing through each vertex.

---

## CSR Dependency

The Assignment 2 algorithms reuse the `CSRGraph` structure and CSR conversion functions from Assignment 1:

```text
assignment_01/src/csr.h
assignment_01/src/csr.cpp
```

The adjacency-list to CSR conversion is treated as preprocessing. It is completed before the algorithm timer starts, so CSR conversion time is not included in the reported algorithm execution time.

---

## Compilation

### Assignment 2 Driver

Run the following command from the repository root:

```powershell
g++ assignment_02\driver\driver.cpp assignment_02\src\triangle_counting.cpp assignment_02\src\connected_components.cpp assignment_02\src\betweenness_centrality.cpp assignment_01\src\csr.cpp -o assignment2.exe
```

### Individual Betweenness Centrality Test Driver

```powershell
g++ assignment_02\src\betweenness_centrality.cpp assignment_02\driver\bc_test.cpp assignment_01\src\csr.cpp -o bc_test.exe
```

---

## Running

### Triangle Counting

```powershell
.\assignment2.exe tc assignment_02\tests\tc_100.txt
```

### Connected Components

```powershell
.\assignment2.exe cc assignment_02\tests\cc_100.txt
```

### Betweenness Centrality

```powershell
.\assignment2.exe bc assignment_02\tests\bc_100.txt
```

The program reports the algorithm result and execution time.

---

## Common Assignment 2 Wrapper

A common wrapper is provided outside the Assignment 2 directory:

```text
wrapper/wrapper.cpp
```

The wrapper provides a menu for:

```text
1. Triangle Counting
2. Connected Components
3. Betweenness Centrality
0. Exit
```

Compile it from the repository root using:

```powershell
g++ -std=c++17 wrapper\wrapper.cpp assignment_02\src\triangle_counting.cpp assignment_02\src\connected_components.cpp assignment_02\src\betweenness_centrality.cpp assignment_01\src\csr.cpp -o wrapper.exe
```

Run:

```powershell
.\wrapper.exe
```

The wrapper allows the user to select an Assignment 2 algorithm and then select its corresponding test file.

---

## Test Generation

### Triangle Counting and Connected Components

Large test graphs can be generated using:

```text
assignment_02/src/generate_graph_tests.cpp
```

Compile:

```powershell
g++ -std=c++17 assignment_02\src\generate_graph_tests.cpp -o generate_tests.exe
```

Run:

```powershell
.\generate_tests.exe
```

The generator uses a fixed random seed to produce reproducible graphs.

### Betweenness Centrality

BC test graphs are generated using:

```text
assignment_02/src/generate_bc_tests.cpp
```

Compile:

```powershell
g++ -std=c++17 assignment_02\src\generate_bc_tests.cpp -o generate_bc_tests.exe
```

Run:

```powershell
.\generate_bc_tests.exe
```

The generator creates the following test cases:

```text
bc_10.txt
bc_100.txt
bc_1000.txt
bc_5000.txt
bc_10000.txt
```

---

## Performance Results

### Triangle Counting

| Algorithm | Test Case | Vertices | Edges | Result | Time (ms) |
|---|---|---:|---:|---:|---:|
| Triangle Counting | `tc_10.txt` | 6 | 8 | 3 triangles | 0.001 |
| Triangle Counting | `tc_100.txt` | 100 | 200 | 9 triangles | 0.040 |
| Triangle Counting | `tc_10000.txt` | 10,000 | 30,000 | 25 triangles | 7.018 |
| Triangle Counting | `tc_50000.txt` | 50,000 | 150,000 | 45 triangles | 39.333 |
| Triangle Counting | `tc_100000.txt` | 100,000 | 300,000 | 34 triangles | 68.770 |

### Connected Components

| Algorithm | Test Case | Vertices | Edges | Result | Time (ms) |
|---|---|---:|---:|---:|---:|
| Connected Components | `cc_10.txt` | 8 | 4 | 4 components | 0.005 |
| Connected Components | `cc_100.txt` | 100 | 200 | 1 component | 0.018 |
| Connected Components | `cc_10000.txt` | 10,000 | 30,000 | 30 components | 2.083 |
| Connected Components | `cc_50000.txt` | 50,000 | 150,000 | 128 components | 6.643 |
| Connected Components | `cc_100000.txt` | 100,000 | 300,000 | 238 components | 15.768 |

### Betweenness Centrality

| Algorithm | Test Case | Vertices | Edges | Result | Time (ms) |
|---|---|---:|---:|---|---:|
| Betweenness Centrality | `bc_10.txt` | 10 | 20 | Centrality computed for all vertices | 0.000 |
| Betweenness Centrality | `bc_100.txt` | 100 | 300 | Centrality computed for all vertices | 11.138 |
| Betweenness Centrality | `bc_1000.txt` | 1,000 | 3,000 | Centrality computed for all vertices | 1560.004 |
| Betweenness Centrality | `bc_5000.txt` | 5,000 | 15,000 | Centrality computed for all vertices | 30163.597 |
| Betweenness Centrality | `bc_10000.txt` | 10,000 | 30,000 | Centrality computed for all vertices | 118611.309 |

---

## Correctness

The Betweenness Centrality implementation was checked using the official example provided in the assignment specification.

For the example graph:

```text
5 4
0 1 1
1 2 0 2
2 2 1 3
3 2 2 4
4 1 3
```

the expected raw betweenness centrality values are:

```text
0 0.00
1 3.00
2 4.00
3 3.00
4 0.00
```

The implementation produced the same values.

The generated BC test cases were also executed successfully through the Assignment 2 driver and common wrapper.

---

## Timing Note

Execution time measures only the algorithm execution.

The following are excluded from the measured time:

- Input-file reading
- Input parsing
- CSR graph construction
- Result printing
- File writing

For CSR-based algorithms, the timer starts immediately before the algorithm is called and stops immediately after it finishes.

---

## Required Graph Sizes

The required graph sizes differ by algorithm.

### Betweenness Centrality

```text
10
100
1000
5000
10000
```

The reduced sizes are used because Brandes' Betweenness Centrality algorithm has `O(V × E)` time complexity.

### Triangle Counting and Connected Components

```text
10
100
10000
50000
100000
```

---

## Dependency

The Assignment 2 implementation reuses the CSR representation and conversion functions from:

```text
assignment_01/src/csr.h
assignment_01/src/csr.cpp
```

No duplicate CSR implementation is maintained in Assignment 2.