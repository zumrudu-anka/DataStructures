#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class DoublyLinkedList
{
private:
    Node<T>* root;
public:
    DoublyLinkedList();
    void add_front(T data);
    void append(T data);
    void insert_after(T prev_data,T data);
    void remove(T data);
    void print_list();
    ~DoublyLinkedList();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->root = nullptr;
}

template <class T>
void DoublyLinkedList<T>::add_front(T data){
    Node<T>* new_node = new Node<T>(data);
    if(this->root != nullptr)
    	this->root->set_prev(new_node);
	new_node->set_next(this->root);
    this->root = new_node;
}

template <class T>
void DoublyLinkedList<T>::append(T data){
    Node<T>* new_node = new Node<T>(data);
    if(this->root == nullptr){
    	this->root = new_node;
	}
	else{
		Node<T>* iter = this->root;
		while(iter->get_next() != nullptr){
        	iter = iter->get_next();
	    }
	    iter->set_next(new_node);
	    new_node->set_prev(iter);
	}
}

template <class T>
void DoublyLinkedList<T>::insert_after(T prev_data, T data){
    if(this->root == nullptr){
        cout<<"Listede Eleman Yok"<<endl;
    }
    else{
        Node<T>* iter = this->root;
        while(iter->get_data() != prev_data && iter != nullptr){
            iter = iter->get_next();
        }
        if(iter == nullptr){
            cout<<"Listede "<<prev_data<<" Elemani Bulunmuyor!"<<endl;
        }
        else{
            Node<T>* new_node = new Node<T>(data);
            new_node->set_next(iter->get_next());
            if(iter->get_next() != nullptr)
            	iter->get_next()->set_prev(new_node);
            iter->set_next(new_node);
            new_node->set_prev(iter);
        }
    }
}

template <class T>
void DoublyLinkedList<T>::remove(T data){
    if(this->root == nullptr){
        cout<<"Listede Eleman Yok"<<endl;
    }
    else{
        Node<T>* iter = this->root;
        while(iter != nullptr && iter->get_data() != data){
            iter = iter->get_next();
        }
        if(iter == nullptr){
            cout<<"Listede "<<data<<"Elemani Bulunmuyor!"<<endl;
        }
        else{
            if(iter->get_prev() == nullptr && iter->get_next()==nullptr){
            	this->root=nullptr;
            }
            else if(iter->get_prev() == nullptr){
				iter->get_next()->set_prev(nullptr);
				this->root = iter->get_next();
			}
			else if(iter->get_next() == nullptr){
				iter->get_prev()->set_next(nullptr);
			}
			else{
        		iter->get_prev()->set_next(iter->get_next());
				iter->get_next()->set_prev(iter->get_prev());	
			}
        }
    }
}

template <class T>
void DoublyLinkedList<T>::print_list(){
    Node<T>* iter = this->root;
    while(iter != nullptr){
        cout<<iter->get_data()<<endl;
        iter = iter->get_next();
    }
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    if(this->root!=nullptr){
        this->root->~Node();
    }
}

#endif
