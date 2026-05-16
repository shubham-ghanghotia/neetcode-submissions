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

// class Solution {
// public:
//     bool hasCycle(ListNode* head) {
//         unordered_set<ListNode*> visited;

//         while(head != nullptr){
//            if(visited.count(head)){
//               return true;
//            } else {
//              visited.insert(head);
//            }
//            head = head->next;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                return true;
            }
        }

       return false;
    }
};
