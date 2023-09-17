# Graphs
## Topics to cover
1. Basic graph traversal using BFS and DFS.
2. Disjoint sets and Union & Find Algorithm (Nice video by [Abdul Bari](https://www.youtube.com/watch?v=wU6udHRIkcc)).
3. Finding minimum spanning tree (any of prims or kruskal's is fine, Kruskal's use greedy and union find).
4. Topological Sorting 
5. Finding cycles in the graph
6. Connected components
7. Shortest Distances (mostly using Dijsktra).

## Learnings:
1. For graph algorithms, undirected graphs uses `visited` approach vs directed graph uses `indegree` approach to traverse a graph.
2. You need to count all nodes traversed to detect `cycle` in a graph (mainly in Topological Sorting). If no of nodes traversed is not total nodes, there is either a connection break or cycle.

## Union Find:
1. If we add an edge, we find both vertices and see in which set they belong.
2. If they belong to same set, there is a cycle.
![Notes](./images/union_find_notes.jpeg)
