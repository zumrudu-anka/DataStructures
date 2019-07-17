#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class SinglyLinkedList
{
private:
    Node<T>* root;
public:
    SinglyLinkedList();
    void add_front(T data);
    void append(T data);
    void insert_after(T prev_data,T data);
    void remove(T data);
    void print_list();
    ~SinglyLinkedList();
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    this->root = nullptr;
}

template <class T>
void SinglyLinkedList<T>::add_front(T data){
    Node<T>* new_node = new Node<T>(data);
    new_node->set_next(this->root);
    this->root = new_node;
}

template <class T>
void SinglyLinkedList<T>::append(T data){
    Node<T>* new_node = new Node<T>(data);
    Node<T>* iter = this->root;
    while(iter->get_next() != nullptr){
        iter = iter->get_next();
    }
    iter->set_next(new_node);
}

template <class T>
void SinglyLinkedList<T>::insert_after(T prev_data, T data){
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
            iter->set_next(new_node);
        }
    }
}

template <class T>
void SinglyLinkedList<T>::remove(T data){
    if(this->root == nullptr){
        cout<<"Listede Eleman Yok"<<endl;
    }
    else{
        Node<T>* iter = this->root;
        while(iter->get_next() != nullptr && iter->get_next()->get_data() != data){
            iter = iter->get_next();
        }
        if(iter->get_next() == nullptr){
            cout<<"Listede "<<data<<"Elemani Bulunmuyor!"<<endl;
        }
        else{
            Node<T>* temp = iter->get_next();
            iter->set_next(temp->get_next());
            delete temp;
        }
    }
}

template <class T>
void SinglyLinkedList<T>::print_list(){
    Node<T>* iter = this->root;
    while(iter != nullptr){
        cout<<iter->get_data()<<endl;
        iter = iter->get_next();
    }
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    if(this->root!=nullptr){
        this->root->~Node();
    }
}

#endif