#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    T* queuee;
    int item_count;
public:
    Queue(/* args */);
    void push(T item);
    void pop();
    int get_size();
    T get_item(int index);
    ~Queue();
};

template <class T>
Queue<T>::Queue(/* args */)
{
    this->queuee = nullptr;
    this->item_count = 0;
}

template <class T>
void Queue<T>::push(T item){
    if(this->item_count == 0){
        this->queuee = new T[1];
        queuee[this->item_count++] = item;
    }
    else{
        T* temp = new T[this->item_count];
        for(int i=0;i<this->item_count;i++){
            temp[i]=this->queuee[i];
        }
        this->queuee = new T[++this->item_count];
        this->queuee[0]=item;
        for(int i=1;i<this->item_count;i++){
            this->queuee[i]=temp[i-1];
        }
    }
}

template <class T>
void Queue<T>::pop(){
    if (this->item_count != 0)
	{
		if(--this->item_count == 0){
			delete[] this->queuee;
			this->queuee = nullptr;
		}
		else{
			T* temp = new T[this->item_count];
			for (int i = 0; i < item_count; i++)
			{
				temp[i]=this->queuee[i];
			}
			this->queuee=new T[this->item_count];
			for (int i = 0; i < item_count; i++)
			{
				this->queuee[i]=temp[i];
			}
			delete[] temp;
		}
	}
	else{
		cout<<endl<<"Queue is empty!"<<endl;
	}
}

template <class T>
T Queue<T>::get_item(int index){
    if(this->item_count!=0){
        return this->queuee[index];
    }
}

template <class T>
int Queue<T>::get_size(){
    return this->item_count;
}

template <class T>
Queue<T>::~Queue()
{
    delete[] this->queuee;
}

int main(){
    Queue<int> new_queue;
    cout<<endl<<"Size: "<<new_queue.get_size()<<endl;
    new_queue.pop();
    new_queue.push(1);
    new_queue.push(3);
    new_queue.push(7);
    new_queue.push(2);
    cout<<endl<<"Size: "<<new_queue.get_size()<<endl;
    cout<<endl<<new_queue.get_item(0)<<endl;
    cout<<endl<<new_queue.get_item(3)<<endl;
    new_queue.pop();
    cout<<endl<<new_queue.get_item(0)<<endl;
    cout<<endl<<new_queue.get_item(2)<<endl;
    new_queue.pop();
    new_queue.push(5);
    cout<<endl<<"Size: "<<new_queue.get_size()<<endl;
    cout<<endl<<new_queue.get_item(0)<<endl;
    cout<<endl<<new_queue.get_item(2)<<endl;
    new_queue.pop();
    new_queue.pop();
    new_queue.pop();
	
    return 0;
}