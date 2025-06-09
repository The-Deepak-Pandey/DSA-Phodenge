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