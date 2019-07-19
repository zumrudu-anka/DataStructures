#include <iostream>

using namespace std;

struct node{
    int n;
    node* next;
    node* prev;
};

void append(node* root, int x){
    node* new_node = new node[1];
    new_node->n = x;
    node* iter = root;
    while(iter->next!=nullptr){
        iter=iter->next;
    }
    iter->next = new_node;
    new_node->prev = iter;
    new_node->next = nullptr;
}

node* add_front(node* root, int x){
    node* new_node = new node[1];
    new_node->n = x;
    new_node->prev=nullptr;
    new_node->next=root;
    root->prev=new_node;
    root = new_node;
    return root;
}

void remove(node* root,int x){
    node* iter = root;
    while(iter != nullptr && iter->n != x){
        iter=iter->next;
    }
    if(iter == nullptr){
        cout<<"Listede Boyle Bir Eleman Yok!";
    }
    else{
        iter->prev->next = iter->next;
        iter->next->prev = iter->prev;
        delete[] iter;
    }
}

void insert_after(node* root, int x, int y){
    node* iter = root;
    while(iter != nullptr && iter->n != x){
        iter = iter->next;
    }
    if(iter == nullptr){
        cout<<"Listede Boyle Bir Eleman Yok!";
    }
    else{
        node* new_node = new node[1];
        new_node->n = y;
        new_node->next = iter->next;
        iter->next->prev = new_node;
        iter->next = new_node;
        new_node->prev = iter;
    }
}

void print_list(node* root){
    node* iter = root;
    while(iter!=nullptr){
        cout<<endl<<iter->n<<endl;
        iter=iter->next;
    }
}

int main(){
    node* root;
    root = new node[1];
    root->n = 0;
    root->next = nullptr;
    root->prev = nullptr;
    for(int i = 1; i <= 5; i++){
        append(root,i);
    }
    print_list(root);
    cout<<"-------";
    root = add_front(root,13);
    root = add_front(root,19);
    root = add_front(root,38);
    print_list(root);
    cout<<"-------"<<endl;
    remove(root,3);
    remove(root,19);
    remove(root,28);
    print_list(root);
    cout<<"-------"<<endl;
    insert_after(root, 4, 7);
    insert_after(root, 7, 88);
    insert_after(root, 38, 93);
    print_list(root);

    return 0;
}