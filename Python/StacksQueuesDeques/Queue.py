class Queue():

    def __init__(self):
        self.items = []
    
    def queue_is_empty(self):
        return self.items == []

    def enqueue(self,item):
        self.items.insert(0,item)
    
    def dequeue(self):
        self.items.pop()
    
    def size(self):
        return len(self.items)

queue = Queue()

print(queue.queue_is_empty())
queue.enqueue("istanbul")
queue.enqueue("ankara")
print("size: " ,queue.size())
queue.dequeue()
print("size: " ,queue.size())
