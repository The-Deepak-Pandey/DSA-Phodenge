// Kosaraju Algorithm is used to find strongly connected components in a directed graph.
// A strongly connected component (SCC) is a maximal subgraph where every vertex is reachable 
// from every other vertex in the subgraph.
// The algorithm consists of two main steps:
// 1. Perform a DFS to get the finishing order of vertices.
// 2. Reverse the graph and perform DFS in the order of finishing times to find SCCs.

#include <bits/stdc++.h>
using namespace std;

class Kosaraju {
public:
    // Function to perform DFS and fill the stack with finishing order
    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& finishStack) {
        visited[node] = true;
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited, finishStack);
            }
        }
        finishStack.push(node);
    }

    // Function to perform DFS on the transposed graph
    void dfsTranspose(int node, vector<vector<int>>& transposedAdjList, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (auto neighbor : transposedAdjList[node]) {
            if (!visited[neighbor]) {
                dfsTranspose(neighbor, transposedAdjList, visited, component);
            }
        }
    }

    // Function to find strongly connected components using Kosaraju's algorithm
    vector<vector<int>> findSCCs(int numVertices, vector<vector<int>>& adjList) {
        stack<int> finishStack;
        vector<bool> visited(numVertices, false);

        // Step 1: Perform DFS and fill the stack with finishing order
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                dfs(i, adjList, visited, finishStack);
            }
        }

        // Step 2: Transpose the graph
        vector<vector<int>> transposedAdjList(numVertices);
        for (int i = 0; i < numVertices; i++) {
            for (auto neighbor : adjList[i]) {
                transposedAdjList[neighbor].push_back(i);
            }
        }

        // Step 3: Perform DFS on the transposed graph in the order of finishing times
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> sccs;

        while (!finishStack.empty()) {
            int node = finishStack.top();
            finishStack.pop();
            if (!visited[node]) {
                vector<int> component;
                dfsTranspose(node, transposedAdjList, visited, component);
                sccs.push_back(component);
            }
        }
        // Return the list of strongly connected components
        return sccs;  
    }
};