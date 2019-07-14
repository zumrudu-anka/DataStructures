class QueueByTwoStack():
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    
    def enqueue(self,item):
        self.stack1.append(item)
    
    def dequeue(self):
        while len(self.stack1) > 0:
            self.stack2.append(self.stack1.pop())
        return self.stack2.pop()

queue = QueueByTwoStack()

queue.enqueue("1")
queue.enqueue("2")
queue.enqueue("3")
queue.enqueue("5")
queue.enqueue("4")
print(queue.dequeue())
print(queue.dequeue())
queue.enqueue("1")
print(queue.dequeue())

