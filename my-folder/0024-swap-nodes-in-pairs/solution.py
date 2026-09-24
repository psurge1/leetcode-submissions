# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode | None) -> ListNode | None:
        dummy = ListNode(next=head)
        curr = dummy
        while curr and curr.next and curr.next.next:
            temp = curr.next
            temp_two = curr.next.next
            temp_three = temp_two.next

            curr.next = temp_two
            temp_two.next = temp
            temp.next = temp_three
            curr = temp

        
        return dummy.next
