class DoublyLinkedListNode():

    def __init__(self,value):
        self.value = value
        self.prevnode = None
        self.nextnode = None
    
    def setNextNode(self,node):
        self.nextnode = node
    
    def setPrevNode(self,node):
        self.prevnode = node

    def getPrevNode(self):
        return self.prevnode
    
    def getNextNode(self):
        return self.nextnode
    
    def getNodeValue(self):
        return self.value

ankara = DoublyLinkedListNode("06")
erzurum = DoublyLinkedListNode("25")
istanbul = DoublyLinkedListNode("34")

print(ankara.getNodeValue())
ankara.setNextNode(erzurum)
erzurum.setPrevNode(ankara)
print(ankara.getNextNode().getNodeValue())
print(erzurum.getPrevNode().getNodeValue())
erzurum.setNextNode(istanbul)
istanbul.setPrevNode(erzurum)
print(erzurum.getNextNode().getNodeValue())
print(istanbul.getPrevNode().getNodeValue())