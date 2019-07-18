class Node():

    def __init__(self, data):
        self.data = data
        self.nextnode = None
        self.prevnode = None

    def setNextNode(self,node):
        self.nextnode = node
    
    def setPrevNode(self,node):
        self.prevnode = node

    def getNextNode(self):
        return self.nextnode
    
    def getPrevNode(self):
        return self.prevnode

    def getNodeValue(self):
        return self.data
