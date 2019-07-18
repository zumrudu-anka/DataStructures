def reverse_string(string):
    if len(string) == 1:
        return string
    return string[len(string)-1] + reverse_string(string[:(len(string)-1)])

def reverse_string2(string):
    if len(string) == 1:
        return string
    return reverse_string2(string[1:]) + string[0]

print(reverse_string("Zumrudu"))
print(reverse_string2("Anka"))
