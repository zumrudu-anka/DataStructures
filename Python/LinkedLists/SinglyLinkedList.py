class Node():

    def __init__(self, data):
        self.data = data
        self.nextnode = None

    def setNextNode(self,node):
        self.nextnode = node
    
    def getNextNode(self):
        return self.nextnode
    
    def getNodeValue(self):
        return self.data

class SinglyLinkedList():

    def __init__(self):
        self.head = None
    
    def push(self, data):

        new_node = Node(data)
        new_node.nextnode = self.head
        self.head = new_node
    
    def insert_after(self,prev_node,data):
        new_node = Node(data)
        temp = self.head
        while temp:
            if(temp.getNodeValue() == prev_node):
                prev_node = temp
                break
            temp = temp.nextnode
        if not temp:
            print("Boyle bir dugum yok")
        else:
            new_node.nextnode = prev_node.nextnode
            prev_node.nextnode = new_node

    def append(self,data):
        if self.head:
            new_node = Node(data)
            temp = self.head
            while temp.nextnode:
                temp = temp.nextnode
            temp.nextnode = new_node
        else:
            self.push(data)
    
    def delete_node(self,data):
        if self.head:
            temp = self.head
            if self.head.getNodeValue() == data:
                self.head = temp.nextnode
                temp = None
            else:
                temp = self.head
                while temp.nextnode:
                    if temp.nextnode.getNodeValue() == data:
                        break
                    temp = temp.nextnode
                del_node = temp.nextnode
                temp.nextnode = del_node.nextnode
                del_node = None
        else:
            print("Liste Bos")

    def printLinkedList(self):
        temp = self.head
        while temp:
            print(temp.data)
            temp = temp.nextnode

linked_list = SinglyLinkedList()
linked_list.append(27)
linked_list.push("tail")
linked_list.push(25)
linked_list.push(10)
linked_list.push("head")
linked_list.insert_after(10,13)
linked_list.insert_after(13,"aga")
linked_list.insert_after(18,"aga")
linked_list.append(33)
linked_list.delete_node(25)
linked_list.delete_node("aga")
linked_list.delete_node("head")
linked_list.delete_node(10)
linked_list.delete_node("tail")
linked_list.push("head")
linked_list.insert_after(33,"tail")

linked_list.printLinkedList()
