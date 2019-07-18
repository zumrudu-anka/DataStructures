#include "SinglyLinkedList.h"

int main(){
    SinglyLinkedList<int> new_list;
    new_list.add_front(3);
    new_list.add_front(8);
    new_list.add_front(5);
    new_list.print_list();
    SinglyLinkedList<char> char_list;
    char_list.add_front('a');
    char_list.add_front('k');
    char_list.add_front('n');
    char_list.add_front('a');
    char_list.print_list();
    char_list.append('k');
    char_list.append('u');
    char_list.append('s');
    char_list.append('u');
    char_list.print_list();
    new_list.insert_after(8,99);
    new_list.print_list();
    new_list.insert_after(3,17);
    new_list.print_list();
    new_list.remove(99);
    new_list.print_list();
    new_list.remove(8);
    new_list.print_list();
    char_list.remove('s');
    char_list.print_list();

    return 0;
}