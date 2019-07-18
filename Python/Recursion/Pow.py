def product(x,y):
    if x == 1:
        return y
    return y + product(x-1,y)

def product2(x,y):
    if y == 1:
        return x
    return x + product(x,y-1)

def my_pow(x,y):
    if y == 1:
        return x
    return product(x, pow(x,y-1))

print(my_pow(5,2))