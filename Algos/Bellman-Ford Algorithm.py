def bellman_ford(edges, n, source):
    dist = [float('inf')] * n
    dist[source] = 0
    
    for _ in range(n - 1):
        for u, v, weight in edges:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
    
    # Check for negative weight cycles
    for u, v, weight in edges:
        if dist[u] + weight < dist[v]:
            print("Graph contains negative weight cycle")
            return None
    return dist

# Test
edges = [(0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2), (1, 4, 2), (3, 2, 5), (3, 1, 1), (4, 3, -3)]
n = 5  # Number of vertices
print(bellman_ford(edges, n, 0))  # Output: Shortest distances from source
