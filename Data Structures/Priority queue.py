import heapq

pq = []
heapq.heappush(pq, (2, "Task A"))
heapq.heappush(pq, (1, "Task B"))
heapq.heappush(pq, (3, "Task C"))
print(heapq.heappop(pq))  # Output: (1, 'Task B')
