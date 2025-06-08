## DFS/BFS

### Undirected - 

`O(V + 2E)`

### Directed -

`O(V + E)`

## Topological Sort

Topological Sort of a Directed Acyclic Graph (DAG) is a linear ordering of its vertices such that for every directed edge u→v, vertex u appears before vertex v in the ordering.

### 📌 Summary Table

| Method                  | Time Complexity | Space Complexity | Method |
|-------------------------|-----------------|------------------|------------------|
| DFS-based Topo Sort     | O(V + E)         | O(V + E)          | Use stack with DFS |
| Kahn’s Algorithm (BFS)  | O(V + E)         | O(V + E)          | Use queue with indegrees array |
