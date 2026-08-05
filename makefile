CXX = g++
CXXFLAGS = -O2 -std=c++11

all: graph

graph: main.cpp bfs.cpp dfs.cpp csr.cpp
	$(CXX) $(CXXFLAGS) main.cpp bfs.cpp dfs.cpp csr.cpp -o graph

clean:
	del /Q graph.exe