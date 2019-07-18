from Node import Node

class DoublyLinkedList():

    def __init__(self):
        self.head = None

    def push(self, data):
        if self.head:
            new_node = Node(data)
            new_node.nextnode = self.head
            self.head.prevnode = new_node
            self.head = new_node
        else:
            new_node = Node(data)
            self.head = new_node

    def append(self, data):
        if self.head:
            temp = self.head
            while temp.nextnode:
                temp = temp.nextnode
            new_node = Node(data)
            temp.nextnode = new_node
            new_node.prevnode = temp
        else:
            new_node = Node(data)
            self.head = new_node

    def insert_after(self, prev_data, data):
        if self.head:
            temp = self.head
            while temp and temp.getNodeValue() != prev_data:
                temp = temp.nextnode
            if temp:
                new_node = Node(data)
                new_node.nextnode = temp.nextnode
                temp.nextnode = new_node
                new_node.prevnode = temp
                if new_node.nextnode:
                    new_node.nextnode.prevnode = new_node
            else:
                print("Listede Boyle Bir Eleman Yok!")
        else:
            print("Listede Boyle Bir Eleman Yok!")

    def delete(self,data):
        if self.head:
            temp = self.head
            while temp and temp.getNodeValue() != data:
                temp = temp.nextnode
            if temp:
                if temp == self.head:
                    if temp.nextnode:
                        temp.nextnode.prevnode = None
                        self.head = temp.nextnode
                        temp = None
                    else:
                        self.head = None
                else:
                    temp.prevnode.nextnode = temp.nextnode
                    if temp.nextnode:
                        temp.nextnode.prevnode = temp.prevnode
                    temp = None
            else:
                print("Listede Boyle Bir Eleman Yok!")
        else:
            print("Listede Eleman Yok!")

    def print_list(self):
        if self.head:
            temp = self.head
            while temp:
                print(temp.data)
                temp = temp.nextnode
        else:
            print("Listede Eleman Yok!")

linked_list = DoublyLinkedList()
linked_list.push(14)
linked_list.push(3)
linked_list.push(5)
linked_list.push(17)
linked_list.print_list()
linked_list.append(12)
linked_list.append(77)
linked_list.append(91)
linked_list.print_list()
linked_list.insert_after(77,15)
linked_list.insert_after(3,13)
linked_list.insert_after(91,68)
linked_list.insert_after(68,69)
linked_list.insert_after(17,1)
linked_list.insert_after(19,12)
linked_list.print_list()
print("--------------------")
linked_list.delete(999)
linked_list.delete(77)
linked_list.delete(68)
linked_list.delete(5)
linked_list.delete(69)
linked_list.delete(91)
linked_list.delete(17)
linked_list.append(91)

linked_list.print_list()