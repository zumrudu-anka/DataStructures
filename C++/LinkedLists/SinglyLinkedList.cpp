#include <iostream>

using namespace std;

struct node
{
    int n;
    node* next;
};

void append(node* s_l_list,int data){
    node* iter;
    iter = s_l_list;
    while(iter->next != nullptr){
        iter = iter->next;
    }
    iter->next = new node[1];
    iter->next->n = data;
    iter->next->next = nullptr;
}

void print_list(node* s_l_list){
    node* iter;
    iter = s_l_list;
    while(iter != nullptr){
        cout<<endl<<iter->n<<endl;
        iter = iter->next;
    }
}

node* add_front(node* s_l_list,int data){
    node* new_node=new node[1];
    new_node->n = data;
    new_node->next = s_l_list;
    s_l_list = new_node;
    return s_l_list;
}

void insert(node* s_l_list,int prev_data, int data){
    node* iter;
    iter = s_l_list;
    while(iter->n != prev_data){
        iter = iter->next;
    }
    node* new_node = new node[1];
    new_node->n = data;
    new_node->next = iter->next;
    iter->next = new_node;
}

void remove(node* s_l_list,int data){
    node* iter;
    iter = s_l_list;
    while(iter->next->n != data){
        iter = iter->next;
    }
    node* temp = iter->next;
    iter->next = temp->next;
    delete[] temp;
    temp = nullptr;
}

int main(){
    node* root;
    root = new node[1];
    root->n = 0;
    root->next = nullptr;
    for (int i = 1; i <= 5; i++)
    {
        root = add_front(root,i);
    }
    print_list(root);
    append(root,6);
    print_list(root);
    append(root,17);
    print_list(root);
    insert(root,3,71);
    print_list(root);
    insert(root,6,47);
    print_list(root);
    root = add_front(root,59);
    print_list(root);
    remove(root,47);
    print_list(root);
    insert(root,6,47);
    print_list(root);

    return 0;
    
}