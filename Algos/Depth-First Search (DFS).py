def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    for neighbor in graph[start] - visited:
        dfs(graph, neighbor, visited)
    return visited

# Test
graph = {
    0: {1, 2},
    1: {0, 3, 4},
    2: {0, 4},
    3: {1, 5},
    4: {1, 2},
    5: {3}
}
print(dfs(graph, 0))  # Output: {0, 1, 2, 3, 4, 5}
