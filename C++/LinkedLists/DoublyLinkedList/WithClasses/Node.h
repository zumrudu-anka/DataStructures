#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
private:
    T data;
    Node* next;
    Node* prev;
public:
    Node(T data);
    T get_data();
    void set_next(Node* next);
    void set_prev(Node* prev);
    Node* get_next();
    Node* get_prev();
	~Node();
};

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T>
T Node<T>::get_data(){
    return this->data;
}

template <class T>
void Node<T>::set_next(Node* next){
    this->next = next;
}

template <class T>
void Node<T>::set_prev(Node* prev){
    this->prev = prev;
}

template <class T>
Node<T>* Node<T>::get_next(){
    return this->next;
}

template <class T>
Node<T>* Node<T>::get_prev(){
    return this->prev;
}

template <class T>
Node<T>::~Node()
{
    if(this->next!=nullptr){
        this->next->~Node();
    }
}
#endif
