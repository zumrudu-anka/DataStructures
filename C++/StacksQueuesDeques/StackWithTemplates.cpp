#include <iostream>
#include <iterator>
using namespace std;

template <class T>
class Stack{
	private:
		T* stack_list;
		int item_count;
	public:
		Stack();
		T top();
		void push(T item);
		void pop();
		int size();
		T get_item(int index);
		~Stack();
};

template <class T>
Stack<T>::Stack(){
	this->stack_list = nullptr;
	this->item_count = 0;
}

template <class T>
T Stack<T>::top(){
	if(this->item_count!=0){
		return this->stack_list[this->item_count-1];
	}
	//	must use try catch
}

template <class T>
T Stack<T>::get_item(int index){
	if(this->item_count!=0){
		return this->stack_list[index];
	}
}

template <class T>
void Stack<T>::push(T item){
	if(this->item_count == 0){
		this->stack_list = new T[++this->item_count];
		this->stack_list[0] = item;
	}
	else{
		T* temp = new T[this->item_count];
		for (int i = 0; i < this->item_count; i++)
		{
			temp[i] = this->stack_list[i];
		}
		this->stack_list = new T[++this->item_count];
		for (int i = 0; i < this->item_count - 1; i++)
		{
			this->stack_list[i] = temp[i];
		}
		delete[] temp;
		this->stack_list[this->item_count - 1] = item;
	}
}

template <class T>
void Stack<T>::pop(){
	if (this->item_count != 0)
	{
		if(--this->item_count == 0){
			delete[] this->stack_list;
			this->stack_list = nullptr;
		}
		else{
			T* temp = new T[this->item_count];
			for (int i = 0; i < item_count; i++)
			{
				temp[i]=this->stack_list[i];
			}
			this->stack_list=new T[this->item_count];
			for (int i = 0; i < item_count; i++)
			{
				this->stack_list[i]=temp[i];
			}
			delete[] temp;
		}
	}
	else{
		cout<<endl<<"Stack is empty!"<<endl;
	}
	
}

template <class T>
int Stack<T>::size(){
	return this->item_count;
}

template <class T>
Stack<T>::~Stack(){
	delete[] this->stack_list;
}

int main(){
	Stack<int> new_stack;
	cout<<endl<<"Stack Size: "<<new_stack.size()<<endl;
	new_stack.pop();
	new_stack.push(1);
	new_stack.push(2);
	new_stack.push(5);
	new_stack.push(9);
	new_stack.push(3);
	cout<<endl<<"Stack Size: "<<new_stack.size()<<endl;
	cout<<endl<<"Top Element: "<<new_stack.top()<<endl;
	new_stack.pop();
	cout<<endl<<"Stack Size: "<<new_stack.size()<<endl;
	cout<<endl<<"Top Element: "<<new_stack.top()<<endl;
	new_stack.pop();cout<<endl<<"Stack Size: "<<new_stack.size()<<endl;
	cout<<endl<<"Top Element: "<<new_stack.top()<<endl;
	new_stack.pop();
	cout<<endl<<"Stack Size: "<<new_stack.size()<<endl;
	cout<<endl<<"Top Element: "<<new_stack.top()<<endl;
	new_stack.pop();
	cout<<endl<<"Stack Size: "<<new_stack.size()<<endl;
	cout<<endl<<"Top Element: "<<new_stack.top()<<endl;
	new_stack.pop();
	cout<<endl<<"Stack Size: "<<new_stack.size()<<endl;
	cout<<endl<<"Top Element: "<<new_stack.top()<<endl;
	new_stack.pop();
	new_stack.push(7);
	cout<<endl<<"Stack Size: "<<new_stack.size()<<endl;
	cout<<endl<<"Top Element: "<<new_stack.top()<<endl;
	return 0;
}
