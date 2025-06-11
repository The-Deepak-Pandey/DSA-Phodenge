// Baically a spanning tree is
// is a tree in which we have N nodes and N-1 edges
// and all nodes are reachable from each other

// And minimum spanning tree is a spanning tree 
// having sum of weights of edges as minimum

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> primsAlgorithm(int V, vector<vector<int>> adj[]){

    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;


    vector<int> vis(V, 0); // Visited array to keep track of visited nodes
    vector<pair<int, int>> mst; // To store the edges of the minimum spanning tree
    // mst will store the edges in the form of pairs (parent, child)
    int totalWeight = 0;

    pq.push({0, {0, -1}}); // {weight, {node, parent}}

    while(!pq.empty()){

        auto it = pq.top();
        pq.pop();
        int weight = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if(vis[node]) continue; // If already visited, skip
        vis[node] = 1; // Mark the node as visited

        totalWeight += weight; // Add weight to total

        if(parent != -1){
            mst.push_back({parent, node}); // Add edge to MST
        }

        for(auto &edge : adj[node]){
            int adjNode = edge[0];
            int edgeWeight = edge[1];

            if(!vis[adjNode]){ // If the adjacent node is not visited
                pq.push({edgeWeight, {adjNode, node}}); // Push to priority queue
            }
        }

    }

    cout << "Total weight of the minimum spanning tree: " << totalWeight << endl;
    
    return mst; // Return the edges of the minimum spanning tree

}
