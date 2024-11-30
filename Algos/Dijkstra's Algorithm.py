import heapq

def dijkstra(graph, start):
    # The heap queue stores tuples of (distance, vertex)
    queue = [(0, start)]
    distances = {start: 0}
    while queue:
        current_dist, current_vertex = heapq.heappop(queue)

        for neighbor, weight in graph[current_vertex]:
            distance = current_dist + weight
            if neighbor not in distances or distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))

    return distances

# Example usage
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('A', 1), ('C', 2), ('D', 5)],
    'C': [('A', 4), ('B', 2), ('D', 1)],
    'D': [('B', 5), ('C', 1)],
}

print(dijkstra(graph, 'A'))  # Output: {'A': 0, 'B': 1, 'C': 3, 'D': 4}
