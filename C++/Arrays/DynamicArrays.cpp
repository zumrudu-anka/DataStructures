#include <iostream>

using namespace std;

class DynamicArray
{
private:
    int item_count;
    int capacity;
    int* dynamic_array;
public:
    DynamicArray(/* args */);
    void append(int item);
    int get_item(int index);
    void resize();
    int get_capacity();
    ~DynamicArray();
};

DynamicArray::DynamicArray(/* args */)
{
    this->item_count = 0;
    this->capacity = 1;
    this->dynamic_array=new int[this->capacity];
}

void DynamicArray::append(int item){
    if(this->item_count==this->capacity)
        this->resize();
    this->dynamic_array[item_count] = item;
    this->item_count++;
}

int DynamicArray::get_item(int index){
    return this->dynamic_array[index];
}

void DynamicArray::resize(){
    int* temp=new int[this->capacity];
    for (int i = 0; i < this->capacity; i++)
    {
        temp[i]=this->dynamic_array[i];
    }
    this->dynamic_array = new int[++this->capacity];
    for (int i = 0; i < this->capacity - 1; i++)
    {
        this->dynamic_array[i]=temp[i];
    }    
}

int DynamicArray::get_capacity(){
    return this->capacity;
}

DynamicArray::~DynamicArray()
{
    delete[] this->dynamic_array;
}

int main(){
	DynamicArray newarray;
    newarray.append(1);
    newarray.append(3);
    newarray.append(5);
    for (int i = 0; i < newarray.get_capacity(); i++)
    {
        cout<<endl<<newarray.get_item(i);
    }
}
