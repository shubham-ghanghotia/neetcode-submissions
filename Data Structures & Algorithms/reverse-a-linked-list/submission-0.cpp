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
    ListNode* reverseList(ListNode* head) {

        ListNode* tail = nullptr;

        while(head != nullptr){
            ListNode* node = new ListNode(head->val);
            if(tail != nullptr){
                node->next = tail;
            }

            tail = node;
            head = head->next;
        }
        
        return tail;
    }
};
