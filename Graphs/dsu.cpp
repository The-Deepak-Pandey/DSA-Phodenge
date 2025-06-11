#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;

public:

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i; // Initially, each node is its own parent
        }
    }

    int findUPar (int node){
        if(node == parent[node]) {
            return node; // If the node is its own parent, return it
        }
        // Path compression optimization
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u); // Find the ultimate parent of u
        int ulp_v = findUPar(v); // Find the ultimate parent of v

        if(ulp_u == ulp_v) return; // If they are already in the same set, do nothing
        
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; // Make ulp_v the parent of ulp_u
        } else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u; // Make ulp_u the parent of ulp_v
        } else {
            parent[ulp_v] = ulp_u; // Make ulp_u the parent of ulp_v
            rank[ulp_u]++; // Increase the rank of the new parent
        }
    }
    
};