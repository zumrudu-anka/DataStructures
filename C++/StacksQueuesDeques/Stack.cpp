#include <iostream>
#include <iterator>
using namespace std;

class Stack{
	private:
		int* stack_list;
		int item_count;
	public:
		Stack();
		int top();
		void push(int item);
		void pop();
		int size();
		~Stack();
};

Stack::Stack(){
	this->stack_list = nullptr;
	this->item_count = 0;
}

int Stack::top(){
	if(this->item_count!=0){
		return this->stack_list[this->item_count-1];
	}
	//	must use try catch
}

void Stack::push(int item){
	if(this->item_count == 0){
		this->stack_list = new int[++this->item_count];
		this->stack_list[0] = item;
	}
	else{
		int* temp = new int[this->item_count];
		for (int i = 0; i < this->item_count; i++)
		{
			temp[i] = this->stack_list[i];
		}
		this->stack_list = new int[++this->item_count];
		for (int i = 0; i < this->item_count - 1; i++)
		{
			this->stack_list[i] = temp[i];
		}
		delete[] temp;
		this->stack_list[this->item_count - 1] = item;
	}
}

void Stack::pop(){
	if (this->item_count != 0)
	{
		if(--this->item_count == 0){
			delete[] this->stack_list;
			this->stack_list = nullptr;
		}
		else{
			int* temp = new int[this->item_count];
			for (int i = 0; i < item_count; i++)
			{
				temp[i]=this->stack_list[i];
			}
			this->stack_list=new int[this->item_count];
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

int Stack::size(){
	return this->item_count;
}

Stack::~Stack(){
	delete[] this->stack_list;
}

int main(){
	Stack new_stack;
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
