// Topo Sort works on Directed Acyclic Graphs (DAGs).

#include <bits/stdc++.h>
using namespace std;

class topologicalSortDFS{
    private:
        // Helper function to perform DFS and fill the stack with topological order
        void dfs(int node, vector<vector<int>> &adjList, vector<int> &visited, stack<int> &orderStack) {
            visited[node] = 1; // Mark the current node as visited

            // Visit all the adjacent nodes
            for (auto neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, adjList, visited, orderStack);
                }
            }

            // Push the node to the stack after visiting all its neighbors
            orderStack.push(node);
        }

    public:
        // Function to return the topological ordering of a directed graph
        vector<int> topoSort(int numVertices, vector<vector<int>>& adjList) {
            stack<int> orderStack;

            vector<int> visited(numVertices, 0);

            // Perform DFS from each unvisited node
            for (int i = 0; i < numVertices; i++) {
                if (!visited[i]) {
                    dfs(i, adjList, visited, orderStack);
                }
            }

            // Extract the topological order from the stack
            vector<int> topoOrder;
            while (!orderStack.empty()) {
                topoOrder.push_back(orderStack.top());
                orderStack.pop();
            }

            return topoOrder;
        }
};


class topologicalSortBFS{
    public:
        // Function to return the topological ordering of a directed graph using Kahn's algorithm
        vector<int> topoSort(int numVertices, vector<vector<int>>& adjList) {
            vector<int> inDegree(numVertices, 0);
            vector<int> topoOrder;

            // Calculate in-degrees of all vertices
            for (int i = 0; i < numVertices; i++) {
                for (auto neighbor : adjList[i]) {
                    inDegree[neighbor]++;
                }
            }

            // Use a queue to process nodes with in-degree 0
            queue<int> q;
            for (int i = 0; i < numVertices; i++) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }

            // Process the queue
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                topoOrder.push_back(node);

                // Decrease the in-degree of adjacent nodes
                for (auto neighbor : adjList[node]) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }

            return topoOrder;
        }
};