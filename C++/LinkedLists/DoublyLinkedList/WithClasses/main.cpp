#include "DoublyLinkedList.h"

int main(){
    DoublyLinkedList<int> new_list;
    new_list.add_front(3);
    new_list.add_front(8);
    new_list.add_front(5);
    new_list.append(5);
    new_list.append(13);
    new_list.add_front(8);
    new_list.insert_after(8,12);
	new_list.insert_after(13,15);
	new_list.insert_after(15,21);
    new_list.add_front(17);
    new_list.append(77);
	new_list.insert_after(77,99);
	new_list.insert_after(77,43);
	new_list.remove(99);
	new_list.remove(43);
	new_list.remove(8);
	new_list.remove(17);
	new_list.remove(12);
	new_list.add_front(777);
	new_list.append(124);
	new_list.insert_after(124,23);
	new_list.insert_after(777,25);		
	new_list.print_list();
    DoublyLinkedList<char> char_list;
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
