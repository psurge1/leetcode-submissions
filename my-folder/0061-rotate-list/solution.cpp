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
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while (temp) {
            ++size;
            temp = temp->next;
        }
        if (size == 0) {
            return head;
        }

        k %= size;
        if (k == 0) {
            return head;
        }

        temp = head;
        int numNodesToSkip = size - k;
        for (; numNodesToSkip > 1; --numNodesToSkip) {
            temp = temp->next;
        }
        ListNode* partitionedList = temp->next;
        temp->next = nullptr;

        temp = partitionedList;
        while (temp && temp->next) {
            temp = temp->next;
        }
        if (temp)
            temp->next = head;
        return partitionedList;
    }
};
