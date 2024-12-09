import heapq

def prim(graph, start):
    visited = set()
    min_heap = [(0, start)]  # (weight, node)
    total_cost = 0

    while min_heap:
        weight, node = heapq.heappop(min_heap)
        if node not in visited:
            visited.add(node)
            total_cost += weight
            for neighbor, w in graph[node]:
                if neighbor not in visited:
                    heapq.heappush(min_heap, (w, neighbor))
    return total_cost

# Test
graph = {
    0: [(1, 2), (3, 6)],
    1: [(0, 2), (2, 3), (3, 8), (4, 5)],
    2: [(1, 3), (4, 7)],
    3: [(0, 6), (1, 8)],
    4: [(1, 5), (2, 7)]
}
print(prim(graph, 0))  # Output: Minimum Cost of MST
