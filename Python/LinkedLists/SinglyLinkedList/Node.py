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
