from collections import deque

queue = deque(["data","ml","ai"])

print(queue)
queue.insert(0,"deep")
print(queue)
queue.insert(0,"learning")
print(queue)
queue.pop()
print(queue)
queue.popleft()
print(queue)
queue.append("ai")
print(queue)
