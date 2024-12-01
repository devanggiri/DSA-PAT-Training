def floyd_warshall(graph):
    # Initialize the distance matrix with the graph's adjacency matrix
    dist = [row[:] for row in graph]
    n = len(graph)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    return dist

# Example usage
graph = [
    [0, 3, float('inf'), float('inf')],
    [3, 0, 1, float('inf')],
    [float('inf'), 1, 0, 7],
    [float('inf'), float('inf'), 7, 0]
]

print(floyd_warshall(graph))  # Output: Matrix of shortest paths between all pairs of nodes
