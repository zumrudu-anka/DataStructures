def product(x,y):
    if x == 1:
        return y
    return y + product(x-1,y)

def product2(x,y):
    if y == 1:
        return x
    return x + product(x,y-1)

print(product(2,3))
print(product2(2,3))
