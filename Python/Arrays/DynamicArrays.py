import ctypes # for the create array

class DynamicArray(object):

    #initialize(constructor)
    def __init__(self):
        self.n = 0          #array element count
        self.capacity = 1   #array capacity
        self.arr = self.make_array(self.capacity)
    
    def __len__(self):
        return self.n
    
    def __getitem__(self,index):
        if self.n > index >= 0:
            return self.arr[index]
        else:
            return IndexError("index is out of bounds!")
        
    def append(self,element):
        if self.n == self.capacity:
            self._resize(self.capacity + 1)
            #self._resize(2 * self.capacity)
        self.arr[self.n] = element
        self.n += 1     #increase element count
    
    def _resize(self,new_capacity):

        new_arr = self.make_array(new_capacity)     #create new array
        
        #move old array to new array
        for i in range(self.n):
            new_arr[i] = self.arr[i]

        self.arr = new_arr
        self.capacity = new_capacity
    
    def make_array(self,new_capacity):
        return (new_capacity*ctypes.py_object)()

arr = DynamicArray()
arr.append(1)
arr.append(3)
arr.append(5)
arr.append(9)
arr.append(2)
for i in range(arr.n):
    print(arr[i])


