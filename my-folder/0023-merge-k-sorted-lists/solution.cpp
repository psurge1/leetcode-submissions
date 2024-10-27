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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int numElements = lists.size();
        ListNode* newList = new ListNode();
        ListNode* head = newList;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (int index = 0; index < numElements; ++index) {
            if (lists[index]) { //k
                heap.push({lists[index]->val, index});
                lists[index] = lists[index]->next;
            }
        }

        while (heap.size() != 0) {
            pair<int, int> e = heap.top(); //n
            newList->next = new ListNode(e.first); //n
            newList = newList->next; //n
            heap.pop(); // nlogk
            if (lists[e.second]) {
                heap.push({lists[e.second]->val, e.second}); // nlogk
                lists[e.second] = lists[e.second]->next; //n
            }
            
        }

        return head->next;
    }
};
