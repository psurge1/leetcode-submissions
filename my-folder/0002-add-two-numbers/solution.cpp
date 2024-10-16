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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* sum = new ListNode();
        ListNode* head = sum;
        short carry = 0;
        while (l1 && l2) {
            sum->next = new ListNode();
            sum->next->val = l1->val + l2->val + carry;
            if (sum->next->val > 9) {
                sum->next->val -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            sum = sum->next;
        }

        while (l1) {
            sum->next = new ListNode();
            sum->next->val = l1->val + carry;
            if (sum->next->val > 9) {
                sum->next->val -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            l1 = l1->next;
            sum = sum->next;
        }
        
        while (l2) {
            sum->next = new ListNode();
            sum->next->val = l2->val + carry;
            if (sum->next->val > 9) {
                sum->next->val -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            l2 = l2->next;
            sum = sum->next;
        }
        if (carry) {
            sum->next = new ListNode(carry);
        }

        return head->next;
    }
};
