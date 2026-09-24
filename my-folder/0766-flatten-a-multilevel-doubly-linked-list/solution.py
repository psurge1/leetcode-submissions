"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        """
        iterate through a node until we reach a node with a child
        add next node to the stack
        continue from the child node
        once the child linked list has been traversed, pop from the stack and continue from the popped element
        continue
        """
        dummy = Node(0, None, head, None)
        curr = dummy.next
        stack = []
        while curr or len(stack) > 0:
            if curr.child:
                if curr.next:
                    stack.append(curr.next)
                curr.next = curr.child
                curr.child = None
                curr.next.prev = curr
            elif curr.next is None and len(stack) > 0:
                next_node = stack.pop()
                curr.next = next_node
                curr.next.prev = curr
            curr = curr.next

        return dummy.next
