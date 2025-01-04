
class ListNode:
    def __init__(self, data: int | None = None, next: 'ListNode | None' = None):
        self.data = data
        self.next = next

class LinkList:
    def __init__(self):
        self.head = ListNode()

    def add(self, value: int):
        new_node = ListNode(value)
        node_current = self.head
        while (node_current.next):
            node_current = node_current.next
        node_current.next = new_node

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
    linkList.out()

if __name__ == "__main__":
    main()

