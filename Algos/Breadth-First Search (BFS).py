from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    result = []
    
    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            result.append(node)
            queue.extend(graph[node] - visited)
    return result

# Test
graph = {
    0: {1, 2},
    1: {0, 3, 4},
    2: {0, 4},
    3: {1, 5},
    4: {1, 2},
    5: {3}
}
print(bfs(graph, 0))  # Output: [0, 1, 2, 3, 4, 5]
