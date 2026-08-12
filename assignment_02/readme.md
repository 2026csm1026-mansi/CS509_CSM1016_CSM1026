# CS509 – Assignment 2

## Graph Algorithms

This assignment implements two graph algorithms using the **CSR (Compressed Sparse Row)** graph representation from Assignment 1:

* **Triangle Counting**
* **Connected Components**

## Directory Structure

```text
assignment_02/
├── src/
│   ├── triangle_counting.cpp
│   ├── triangle_counting.h
│   ├── connected_components.cpp
│   ├── connected_components.h
│   └── generate_graph_tests.cpp
│
├── driver/
│   ├── driver.cpp
│   ├── tc_test.cpp
│   └── cc_test.cpp
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
    └── cc_100000.txt
```

## Algorithms

### 1. Triangle Counting

Counts the number of triangles present in an undirected graph represented using CSR format.

### 2. Connected Components

Finds all connected components in an undirected graph using BFS over the CSR representation.

## Compilation

Run the following command from the repository root:

```powershell
g++ assignment_02\driver\driver.cpp assignment_02\src\triangle_counting.cpp assignment_02\src\connected_components.cpp assignment_01\src\csr.cpp -o assignment2.exe
```

## Running

### Triangle Counting

```powershell
.\assignment2.exe tc assignment_02\tests\tc_100.txt
```

### Connected Components

```powershell
.\assignment2.exe cc assignment_02\tests\cc_100.txt
```

The program reports the algorithm result and execution time.

## Test Generation

Large test graphs can be generated using `generate_graph_tests.cpp`.

Compile:

```powershell
g++ -std=c++17 assignment_02\src\generate_graph_tests.cpp -o generate_tests.exe
```

Run:

```powershell
.\generate_tests.exe
```

The generator uses a fixed random seed to produce reproducible graphs.

## Performance Results

| Algorithm            | Test Case       | Vertices |   Edges |         Result | Time (ms) |
| -------------------- | --------------- | -------: | ------: | -------------: | --------: |
| Triangle Counting    | `tc_10.txt`     |        6 |       8 |    3 triangles |     0.001 |
| Triangle Counting    | `tc_100.txt`    |      100 |     200 |    9 triangles |     0.040 |
| Triangle Counting    | `tc_10000.txt`  |   10,000 |  30,000 |   25 triangles |     7.018 |
| Triangle Counting    | `tc_50000.txt`  |   50,000 | 150,000 |   45 triangles |    39.333 |
| Triangle Counting    | `tc_100000.txt` |  100,000 | 300,000 |   34 triangles |    68.770 |
| Connected Components | `cc_10.txt`     |        8 |       4 |   4 components |     0.005 |
| Connected Components | `cc_100.txt`    |      100 |     200 |    1 component |     0.018 |
| Connected Components | `cc_10000.txt`  |   10,000 |  30,000 |  30 components |     2.083 |
| Connected Components | `cc_50000.txt`  |   50,000 | 150,000 | 128 components |     6.643 |
| Connected Components | `cc_100000.txt` |  100,000 | 300,000 | 238 components |    15.768 |

**Note:** Execution time measures only the algorithm execution and excludes input-file reading and CSR graph construction.

## Dependency

The assignment reuses the `CSRGraph` structure and CSR conversion functions from:

```text
assignment_01/src/csr.h
assignment_01/src/csr.cpp
```
