#include <bits/stdc++.h>
using namespace std;

class adjencencyMatrix {
private:
    vector<vector<int>> matrix;
    int size;
public:
    adjencencyMatrix(int n) {
        size = n;
        matrix.resize(size, vector<int>(size, 0));
    }

    void addEdge(int u, int v) {
        if (u >= 0 && u < size && v >= 0 && v < size) {
            matrix[u][v] = 1;
        }
    }

    void removeEdge(int u, int v) {
        if (u >= 0 && u < size && v >= 0 && v < size) {
            matrix[u][v] = 0;
        }
    }

    bool hasEdge(int u, int v) {
        return u >= 0 && u < size && v >= 0 && v < size && matrix[u][v] == 1;
    }

    void bfs(int start) {
        vector<bool> visited(size, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int i = 0; i < size; i++) {
                if (matrix[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void dfs(int start, vector<bool> &visited) {
        visited[start] = true;
        cout << start << " ";
        for (int i = 0; i < size; i++) {
            if (matrix[start][i] == 1 && !visited[i]) {
                dfs(i, visited);
            }
        }
    }
};

class adjencencyList {
private:
    vector<vector<int>> list;
    int size;
public:
    adjencencyList(int n) {
        size = n;
        list.resize(size);
    }

    void addEdge(int u, int v) {
        if (u >= 0 && u < size && v >= 0 && v < size) {
            list[u].push_back(v);
        }
    }

    void removeEdge(int u, int v) {
        if (u >= 0 && u < size && v >= 0 && v < size) {
            auto it = find(list[u].begin(), list[u].end(), v);
            if (it != list[u].end()) {
                list[u].erase(it);
            }
        }
    }

    bool hasEdge(int u, int v) {
        return u >= 0 && u < size && v >= 0 && v < size &&
               find(list[u].begin(), list[u].end(), v) != list[u].end();
    }

    void bfs(int start) {
        vector<bool> visited(size, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int neighbor : list[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void dfs(int start, vector<bool> &visited) {
        visited[start] = true;
        cout << start << " ";
        for (int neighbor : list[start]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }
    
};