from typing import List


class Node:
    def __init__(self, x, next=None) -> None:
        self.x = x
        self.next = next

    def __str__(self) -> str:
        s = '['
        node = self
        while node != None:
            s += str(node.x)
            if (node.next != None):
                s += ', '
            node = node.next
        s += ']'
        return s


class Stack(List):
    def peek(self):
        return self[-1] if len(self) != 0 else None


def reverseList(head: Node) -> Node:
    stack = Stack()
    node = head
    while node != None:
        stack.append(node)
        node = node.next
    result = stack.peek()
    while len(stack) != 0:
        node = stack.pop()
        node.next = stack.peek()
    return result


def reverseList2(head: Node) -> Node:
    node = head
    node_prev = None
    while node != None:
        node_next = node.next
        node.next = node_prev
        node_prev = node
        node = node_next
    return node_prev


lst = Node(1, Node(2, Node(3)))
print(reverseList2(lst))
