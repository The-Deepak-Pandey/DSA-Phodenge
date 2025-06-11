#include <bits/stdc++.h>   
using namespace std;

// Function to find Shortest Path in Undirected Graph with Unit Weights

vector<int> shortestPath1(int src, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    queue<int> q;
    q.push(src);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (dist[node] + 1 < dist[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    
    return dist;
}

vector<int> dijkstraPQ(int src, vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> ans(n, INT_MAX);
    ans[src] = 0;
    
    // dist , node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    
    while(!pq.empty()){
        auto topNode = pq.top();
        int node = topNode.second;
        int curDist = topNode.first;
        pq.pop();
        
        for(auto neigh : adj[node]){
            int neighNode = neigh.first;
            int neighWeight = neigh.second;
            
            if(curDist + neighWeight < ans[neighNode]){
                ans[neighNode] = curDist + neighWeight;
                pq.push({curDist + neighWeight, neighNode});
            }
        }
    }
    
    return ans;
}

vector<int> printShortestPath(int src, vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[src] = 0;
    parent[src] = src;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto topNode = pq.top();
        int node = topNode.second;
        int curDist = topNode.first;
        pq.pop();
        
        for(auto neigh : adj[node]){
            int neighNode = neigh.first;
            int neighWeight = neigh.second;
            
            if(curDist + neighWeight < dist[neighNode]){
                dist[neighNode] = curDist + neighWeight;
                parent[neighNode] = node;
                pq.push({dist[neighNode], neighNode});
            }
        }
    }
    vector<int> path;
    for(int i = 0; i < n; i++){
        if(dist[i] == INT_MAX) continue;
        vector<int> tempPath;
        int curNode = i;
        while(curNode != src){
            tempPath.push_back(curNode);
            curNode = parent[curNode];
        }
        tempPath.push_back(src);
        reverse(tempPath.begin(), tempPath.end());
        path.insert(path.end(), tempPath.begin(), tempPath.end());
    }
    return path;
}

vector<int> dijkstraSET(int src, vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> ans(n, INT_MAX);
    ans[src] = 0;
    
    set<pair<int, int>> s;
    s.insert({0, src});
    
    while(!s.empty()){
        auto topNode = *s.begin();
        int node = topNode.second;
        int curDist = topNode.first;
        s.erase(s.begin());
        
        for(auto neigh : adj[node]){
            int neighNode = neigh.first;
            int neighWeight = neigh.second;
            
            if(curDist + neighWeight < ans[neighNode]){
                if(ans[neighNode] != INT_MAX){
                    s.erase(s.find({ans[neighNode], neighNode}));
                }
                ans[neighNode] = curDist + neighWeight;
                s.insert({ans[neighNode], neighNode});
            }
        }
    }
    
    return ans;
}

vector<int> bellmanFord(int src, vector<vector<int>> &edges, int V){

    vector<int> dist(V, 1e8);

    dist[src] = 0;

    // Relax all edges V-1 times
    for(int i = 0; i < V - 1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycles
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            cout << "Negative weight cycle detected!" << endl;
            return {-1};
        }
    }

    return dist;

}

vector<vector<int>> floydWarshall(int V, vector<vector<int>>& edges) {
    // Initialize distance matrix
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    
    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }
    
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        dist[u][v] = min(dist[u][v], w);
    }
    
    // Floyd-Warshall algorithm

    for(int via = 0; via < V; via++){
        for(int u = 0; u < V; u++){
            for(int v = 0; v < V; v++){
                if(dist[u][via] != INT_MAX && dist[via][v] != INT_MAX){
                    dist[u][v] = min(dist[u][v], dist[u][via] + dist[via][v]);
                }
            }
        }
    }

    // Negative cycle detection
    for (int k = 0; k < V; k++) {
        if (dist[k][k] < 0) {
            cout << "Negative weight cycle detected!" << endl;
            return {{-1}};
        }
    }

    return dist;
}