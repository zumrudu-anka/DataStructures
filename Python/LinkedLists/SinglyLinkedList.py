class Node():

    def __init__(self,value):
        self.value = value
        self.nextnode = None

    def setNextNode(self,node):
        self.nextnode = node
    
    def getNextNode(self):
        return self.nextnode
    
    def getNodeValue(self):
        return self.value

ankara = Node("06")
erzurum = Node("25")
istanbul = Node("34")

print(ankara.getNodeValue())
ankara.setNextNode(erzurum)
print(ankara.getNextNode().getNodeValue())
erzurum.setNextNode(istanbul)
print(ankara.getNextNode().getNextNode().getNodeValue())