#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
    // rank: to keep track of the depth of trees
    // parent: to keep track of the parent of each node
    // size: to keep track of the size of each set

public:

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1); // Initialize size of each set to 1
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

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u); // Find the ultimate parent of u
        int ulp_v = findUPar(v); // Find the ultimate parent of v

        if(ulp_u == ulp_v) return; // If they are already in the same set, do nothing
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; // Make ulp_v the parent of ulp_u
            size[ulp_v] += size[ulp_u]; // Update the size of the new parent
        } else {
            parent[ulp_v] = ulp_u; // Make ulp_u the parent of ulp_v
            size[ulp_u] += size[ulp_v]; // Update the size of the new parent
        }
    }

};

int kruskalAlgo(int V, vector<vector<int>> adj[]){
    vector<pair<int, pair<int, int>>> edges; // To store the edges in the form (weight, (u, v))
    
    // Convert adjacency list to edge list
    for(int u = 0; u < V; u++) {
        for(auto &edge : adj[u]) {
            int v = edge[0];
            int weight = edge[1];
            edges.push_back({weight, {u, v}});
        }
    }

    // Sort the edges based on their weights
    sort(edges.begin(), edges.end());

    int mstWt = 0;

    DisjointSet ds(V); // Create a disjoint set for union-find operations

    for(auto it : edges){
        int weight = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUPar(u) != ds.findUPar(v)) { // If u and v are in different sets
            ds.unionBySize(u, v); // Union the sets containing u and v
            mstWt += weight; // Add the weight to the total weight of the MST
        }
    }

    return mstWt;

}