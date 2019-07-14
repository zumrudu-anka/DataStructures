def createStack():
    stack = []
    return stack

def size(stack):
    pass

def top(stack):
    pass

def push(stack,item):
    stack.append(item)

def pop(stack):
    return stack.pop()

def reverse(string):
    l = len(string)
    stack = createStack()
    for i in range(l):
        push(stack, string[i])
    result = ""
    for i in range(l):
        result += pop(stack)
    return result

print(reverse("Osman"))