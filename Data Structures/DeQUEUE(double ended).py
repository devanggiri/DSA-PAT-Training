# Deque implementation using collections.deque
from collections import deque

dq = deque()
dq.append(1)      # Add to the right
dq.appendleft(2)  # Add to the left
dq.pop()          # Remove from the right
dq.popleft()      # Remove from the left
print(dq)  # Output: deque([])
