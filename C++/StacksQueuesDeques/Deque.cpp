#include <iostream>

using namespace std;

class Deque
{
private:
    int* dequee;
    int item_count;
public:
    Deque();
    void add_front(int item);
    void add_back(int item);
    void remove_front();
    void remove_back();
    int get_size();
    int get_item(int index);
    ~Deque();
};

Deque::Deque()
{
    this->dequee = nullptr;
    this->item_count = 0;
}

void Deque::add_front(int item){
    if(this->item_count==0){
        this->dequee = new int[1];
        this->dequee[this->item_count++] = item;
    }
    else{
        int* temp = new int[this->item_count];
        for(int i=0;i<this->item_count;i++){
            temp[i]=this->dequee[i];
        }
        this->dequee = new int[++this->item_count];
        this->dequee[0]=item;
        for(int i=1;i<this->item_count;i++){
            this->dequee[i]=temp[i-1];
        }
        delete[] temp;
    }
}

void Deque::add_back(int item){
    if(this->item_count==0){
        this->dequee = new int[1];
        this->dequee[this->item_count++] = item;
    }
    else{
        int* temp = new int[this->item_count];
		for (int i = 0; i < this->item_count; i++)
		{
			temp[i] = this->dequee[i];
		}
		this->dequee = new int[++this->item_count];
		for (int i = 0; i < this->item_count - 1; i++)
		{
			this->dequee[i] = temp[i];
		}
		delete[] temp;
		this->dequee[this->item_count - 1] = item;
    }
}

void Deque::remove_front(){
    if(this->item_count!=0){
        int* temp = new int[--this->item_count];
        for(int i=0;i<this->item_count;i++){
            temp[i]=this->dequee[i+1];
        }
        this->dequee = new int[this->item_count];
        for(int i=0;i<this->item_count;i++){
            this->dequee[i]=temp[i];
        }
        delete[] temp;
    }
    else{
		cout<<endl<<"Deque is empty!"<<endl;
    }
}

void Deque::remove_back(){
    if(this->item_count!=0){
        int* temp = new int[--this->item_count];
        for(int i=0;i<this->item_count;i++){
            temp[i]=this->dequee[i];
        }
        this->dequee = new int[this->item_count];
        for(int i=0;i<this->item_count;i++){
            this->dequee[i]=temp[i];
        }
        delete[] temp;
    }
    else{
		cout<<endl<<"Deque is empty!"<<endl;
    }
}

int Deque::get_item(int index){
    if(this->item_count!=0){
        return this->dequee[index];
    }
}

int Deque::get_size(){
    return this->item_count;
}

Deque::~Deque()
{
    delete[] this->dequee;
}

void print(Deque &deq){
    cout<<endl<<"--"<<endl;
    for(int i=0;i<deq.get_size();i++){
        cout<<deq.get_item(i)<<endl;
    }
}

int main(){
    Deque new_deq;
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

    return 0;
}