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

    void print() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
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

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << i << ": ";
            for (int j : list[i]) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
};