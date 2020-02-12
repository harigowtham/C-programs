class node:
    def __init__(self, data):
        self.head=data
        self.next=None

class llist:
    def __init__(self):
        self.head=None

    def printl(self):
        temp = self.head
        while(temp):
            print temp.head
            temp = temp.next

    def insertatend(self,data):
        newNode = node(data)
        if self.head is None:
            self.head= newNode
            return
        temp = self.head
        while(temp.next):
            temp = temp.next
        temp.next = newNode

if __name__=='__main__':

    llist = llist()
    #llist.head = node(1)
    #second = node('hi')
    #third = node(3)

    #llist.head.next = second
    #second.next = third
    #third.next = None
    llist.insertatend(44443)
    llist.insertatend(4443)
    llist.insertatend(443)
    llist.insertatend(43)

    llist.printl()
