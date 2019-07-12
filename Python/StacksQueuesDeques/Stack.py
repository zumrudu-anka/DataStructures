class Stack:
   
    def __init__(self):
        self.items = []
    
    def stack_is_empty(self):
        return self.items == []     #return boolean phrase

    def push(self, item):
        self.items.append(item)
    
    def pop(self):
        return self.items.pop()
    
    def top(self):
        return self.items[len(self.items)-1]
    
    def size(self):
        return len(self.items)

stack = Stack()
print(stack.stack_is_empty())
stack.push("ankara")
print(stack.top())
stack.push("istanbul")
print(stack.top())
stack.push("izmir")
print(stack.top())
print(stack.size())
stack.pop()
print(stack.top())
print(stack.stack_is_empty())
stack.pop()
print(stack.top())
print(stack.stack_is_empty())
stack.pop()
print(stack.stack_is_empty())