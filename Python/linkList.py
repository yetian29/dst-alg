
class ListNode:
    def __init__(self, data: int | None = None, next: 'ListNode | None' = None):
        self.data = data
        self.next = next

class LinkList:
    def __init__(self):
        self.head = ListNode()

    def create_node_new(self, value: int):
        new_node = ListNode(value)
        return new_node

    def add(self, value: int):
        new_node = self.create_node_new(value)
        node_current = self.head
        while (node_current.next):
            node_current = node_current.next
        node_current.next = new_node

    def insert(self, value: int, position: int):
        new_node = self.create_node_new(value)
        node_current = self.head
        i = 0
        while (node_current and i < position - 1):
            node_current = node_current.next
            i += 1
        tmp =  node_current.next
        node_current.next = new_node
        new_node.next = tmp
    



    def out(self):
        node_current = self.head
        while node_current:
            print(f"{node_current.data}", end=" -> ")
            node_current = node_current.next
        print()




def main():
    linkList = LinkList()
    linkList.add(1)
    linkList.add(2)
    linkList.add(3)
    linkList.add(4)
    linkList.add(5)
    linkList.insert(6, 1)
    linkList.insert(7, 2)
    linkList.insert(8, 8)
    linkList.out()


if __name__ == "__main__":
    main()

