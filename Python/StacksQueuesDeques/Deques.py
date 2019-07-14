class Deque():
    def __init__(self):
        self.items = []

    def add_rear(self,item):
        self.items.append(item)
    
    def add_front(self,item):
        self.items.insert(0,item)
    
    def remove_rear(self):
        self.items.pop()
    
    def remove_front(self):
        self.items.pop(0)

    def deque_is_empty(self):
        return self.items == []

    def size(self):
        return len(self.items)
    
    def get_item(self,index):
        return self.items[index]

deque = Deque()

print(deque.deque_is_empty())
deque.add_front("deep")
print(deque.get_item(0))
deque.add_front("learning")
print(deque.get_item(0))
print("size: ",deque.size())
deque.remove_front()
print("size: ",deque.size())
deque.remove_rear()
print("size: ",deque.size())
print(deque.deque_is_empty())
