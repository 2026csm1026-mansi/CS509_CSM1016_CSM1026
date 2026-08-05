# CS509_CSM1016_CSM1026
CS509 Laboratory Assignments M.Tech CSE - buddy
# CS509 Assignment 1

## Team Members

- CSM1016
- CSM1026

---

# Assignment

Implementation of:

- CSR (Compressed Sparse Row)
- Breadth First Search (BFS)
- Depth First Search (DFS)
- Single Source Shortest Path (SSSP)

---

# Project Structure

```
assignment_01
│
├── driver
│   ├── bfs_test.cpp
│   ├── dfs_test.cpp
│   └── sssp_test.cpp
│
├── src
│   ├── bfs.cpp
│   ├── bfs.h
│   ├── dfs.cpp
│   ├── dfs.h
│   ├── csr.cpp
│   ├── csr.h
│   ├── sssp.cpp
│   ├── sssp.h
│   └── generate_graph_tests.cpp
│
├── tests
│
└── wrapper
    └── wrapper.cpp
```

---

# Compilation

Compile the wrapper using:

```bash
g++ -std=c++17 -I"assignment_01/src" assignment_01/wrapper/wrapper.cpp assignment_01/src/bfs.cpp assignment_01/src/dfs.cpp assignment_01/src/sssp.cpp assignment_01/src/csr.cpp -o wrapper
```

---

# Execution

Run the program using:

```bash
./wrapper
```

or on Windows

```bash
wrapper.exe
```

---

# Test Cases

The following graph sizes were used:

| Test File | Vertices |
|-----------|---------:|
| graph_10.txt | 10 |
| graph_100.txt | 100 |
| graph_10000.txt | 10000 |
| graph_50000.txt | 50000 |
| graph_100000.txt | 100000 |

For SSSP:

| Test File | Vertices |
|-----------|---------:|
| sssp_10.txt | 10 |
| sssp_100.txt | 100 |
| sssp_10000.txt | 10000 |
| sssp_50000.txt | 50000 |
| sssp_100000.txt | 100000 |

---

# Algorithms

## BFS

- Representation: CSR
- Data Structure: Queue

Time Complexity:

```
O(V + E)
```

---

## DFS

- Representation: CSR
- Implementation: Recursive

Time Complexity:

```
O(V + E)
```

---

## SSSP

- Algorithm: Dijkstra
- Graph Type: Positive Weighted Graph
- Representation: CSR

Time Complexity:

```
O((V + E) log V)
```

---

# Timing

Execution time includes **only algorithm execution**.

The following are excluded from timing:

- File reading
- Input parsing
- CSR conversion
- Output printing

---

# Input Format

### BFS / DFS

```
V E
u degree neighbours...
...
SOURCE s
```

### SSSP

```
V E
u degree neighbour weight ...
...
SOURCE s
```

---

# Output

The program reports:

- Algorithm name
- Source vertex
- Traversal (BFS/DFS)
- Distances (BFS/SSSP)
- Execution time
