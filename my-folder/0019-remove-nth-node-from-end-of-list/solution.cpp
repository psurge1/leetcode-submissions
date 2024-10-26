/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int numNodes = 0;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* node = dummy;
        while(node->next) {
            ++numNodes;
            node = node->next;
        }

        node = dummy;
        for (int i = 1; i <= numNodes - n; ++i) {
            node = node->next;
        }
        node->next = node->next->next;


        return dummy->next;
    }
};
