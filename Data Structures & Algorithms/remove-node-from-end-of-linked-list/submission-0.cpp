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

// Approach 1.
// Space O(1)
// Space O(n)
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         // Step 1. Find length
//         int l = 0;
//         ListNode* len = head;
//         while(len != nullptr){
//             l++;
//             len = len->next;
//         }

//         // Step 2. Calculate node to remove
//         int remv = l - n;
//         if(remv == 0){
//             return head->next;
//         }

//         // Step 3. Reach the node before target
//         int cp = 1;
//         ListNode* curr = head;
//         while(curr != nullptr){
//             if(cp == remv){
//                 curr->next = curr->next->next;
//                 break;
//             }
//             cp++;
//             curr = curr->next;
//         }


//         return head;
//     }
// };

// Approach 2.
// Space O(1)
// Space O(n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for(int i = 0; i <= n; i++){
            fast = fast->next;
        }

        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        
        return dummy->next;
    }
};
