## DFS/BFS

### Undirected - 

`O(V + 2E)`

### Directed -

`O(V + E)`

## Topological Sort

Topological Sort of a Directed Acyclic Graph (DAG) is a linear ordering of its vertices such that for every directed edge u→v, vertex u appears before vertex v in the ordering.

When question is like - something before something , try thinking of toposort

### 📌 Summary Table

| Method                  | Time Complexity | Space Complexity | Method |
|-------------------------|-----------------|------------------|------------------|
| DFS-based Topo Sort     | O(V + E)         | O(V + E)          | Use stack with DFS |
| Kahn’s Algorithm (BFS)  | O(V + E)         | O(V + E)          | Use queue with indegrees array |


## Dijkstra's Algorithm

`ElogV`


Could be implemented either with Priority Queue or Set data structure. While implementing set, when found a smaller distance just erase the older value from the set like -

```C++
if(curDist + neighWeight < ans[neighNode]){
    if(ans[neighNode] != INT_MAX){
        s.erase(s.find({ans[neighNode], neighNode}));
    }
    ans[neighNode] = curDist + neighWeight;
    s.insert({ans[neighNode], neighNode});
}
```
## Bellman-Ford Algorithm

`O(V^2)`

## Floyd-Warshall Algorithm

`O(V^3)` - Time Complexity

`O(V^2)` - Space Complexity

## Disjoint Set Union

`O(4*alpha)` - Time Complexity