#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
private:
    T data;
    Node* next;
public:
    Node(T data);
    T get_data();
    void set_next(Node* next);
    Node* get_next();
    ~Node();
};

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
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
Node<T>* Node<T>::get_next(){
    return this->next;
}

template <class T>
Node<T>::~Node()
{
    if(this->next!=nullptr){
        this->next->~Node();
    }
}
#endif