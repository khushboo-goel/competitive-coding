# Graphs
## Topics to cover
1. Basic graph traversal using BFS and DFS.
2. Union Find Algo
3. Finding minimum spanning tree (any of prims or kruskal's is fine, prim's use greedy and union find).
4. Topological Sorting
5. Finding cycles in the graph
6. Connected components (can be done with BFS, DFS or union find)
7. Shortest Distances (mostly using Dijsktra).

## Learnings:
1. For graph algorithms, undirected graphs uses `visited` approach vs directed graph uses `indegree` approach to traverse a graph.
2. You need to count all nodes traversed to detect `cycle` in a graph (mainly in Topological Sorting). If no of nodes traversed is not total nodes, there is either a connection break or cycle.
