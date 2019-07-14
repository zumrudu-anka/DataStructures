#include <iostream>

using namespace std;

template <class T>
class Deque
{
private:
    T* dequee;
    int item_count;
public:
    Deque();
    void add_front(T item);
    void add_back(T item);
    void remove_front();
    void remove_back();
    int get_size();
    T get_item(int index);
    ~Deque();
};

template <class T>
Deque<T>::Deque()
{
    this->dequee = nullptr;
    this->item_count = 0;
}

template <class T>
void Deque<T>::add_front(T item){
    if(this->item_count==0){
        this->dequee = new T[1];
        this->dequee[this->item_count++] = item;
    }
    else{
        T* temp = new T[this->item_count];
        for(int i=0;i<this->item_count;i++){
            temp[i]=this->dequee[i];
        }
        this->dequee = new T[++this->item_count];
        this->dequee[0]=item;
        for(int i=1;i<this->item_count;i++){
            this->dequee[i]=temp[i-1];
        }
        delete[] temp;
    }
}

template <class T>
void Deque<T>::add_back(T item){
    if(this->item_count==0){
        this->dequee = new T[1];
        this->dequee[this->item_count++] = item;
    }
    else{
        T* temp = new T[this->item_count];
		for (int i = 0; i < this->item_count; i++)
		{
			temp[i] = this->dequee[i];
		}
		this->dequee = new T[++this->item_count];
		for (int i = 0; i < this->item_count - 1; i++)
		{
			this->dequee[i] = temp[i];
		}
		delete[] temp;
		this->dequee[this->item_count - 1] = item;
    }
}

template <class T>
void Deque<T>::remove_front(){
    if(this->item_count!=0){
        T* temp = new T[--this->item_count];
        for(int i=0;i<this->item_count;i++){
            temp[i]=this->dequee[i+1];
        }
        this->dequee = new T[this->item_count];
        for(int i=0;i<this->item_count;i++){
            this->dequee[i]=temp[i];
        }
        delete[] temp;
    }
    else{
		cout<<endl<<"Deque is empty!"<<endl;
    }
}

template <class T>
void Deque<T>::remove_back(){
    if(this->item_count!=0){
        T* temp = new T[--this->item_count];
        for(int i=0;i<this->item_count;i++){
            temp[i]=this->dequee[i];
        }
        this->dequee = new T[this->item_count];
        for(int i=0;i<this->item_count;i++){
            this->dequee[i]=temp[i];
        }
        delete[] temp;
    }
    else{
		cout<<endl<<"Deque is empty!"<<endl;
    }
}

template <class T>
T Deque<T>::get_item(int index){
    if(this->item_count!=0){
        return this->dequee[index];
    }
}

template <class T>
int Deque<T>::get_size(){
    return this->item_count;
}

template <class T>
Deque<T>::~Deque()
{
    delete[] this->dequee;
}

template <class T>
void print(Deque<T> &deq){
    cout<<endl<<"--"<<endl;
    for(int i=0;i<deq.get_size();i++){
        cout<<deq.get_item(i)<<endl;
    }
}

int main(){
    Deque<int> new_deq;
    cout<<endl<<new_deq.get_size()<<endl;
    new_deq.remove_back();
    new_deq.remove_front();
    new_deq.add_back(1);
    new_deq.add_back(7);
    new_deq.add_back(5);
    new_deq.add_back(3);
    print(new_deq);
    new_deq.add_front(13);
    new_deq.add_front(41);
    print(new_deq);
    new_deq.remove_back();
    new_deq.remove_back();
    print(new_deq);
    new_deq.remove_front();
    print(new_deq);
    new_deq.remove_front();
    print(new_deq);

    Deque<char> new_deq2;
    cout<<endl<<new_deq2.get_size()<<endl;
    new_deq2.remove_back();
    new_deq2.remove_front();
    new_deq2.add_back('a');
    new_deq2.add_back('c');
    new_deq2.add_back('e');
    new_deq2.add_back('b');
    print(new_deq2);
    new_deq2.add_front('z');
    new_deq2.add_front('k');
    print(new_deq2);
    new_deq2.remove_back();
    new_deq2.remove_back();
    print(new_deq2);
    new_deq2.remove_front();
    print(new_deq2);
    new_deq2.remove_front();
    print(new_deq2);

    return 0;
}