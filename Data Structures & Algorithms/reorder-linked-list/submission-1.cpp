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
//     void reorderList(ListNode* head) {
//         vector<ListNode*> nodes;
//         ListNode* curr = head;
//         // Build array from list;
//         while(curr != nullptr){
//             nodes.push_back(curr);
//             curr = curr->next;
//         }

//         int i = 0, j = nodes.size() - 1;

//         while(i < j){
//             nodes[i]->next = nodes[j];
//             i++;
//             if(i == j) break;
//             nodes[j]->next = nodes[i];
//             j--;
//         }

//         nodes[i]->next = nullptr;
//     }
// };

class Solution {
   public:
    void reorderList(ListNode* head) {
        // Step 1: Find middle
        ListNode* slow = head;  // ✓ ListNode not LinkedList
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;  // ✓ start from slow->next
        slow->next = nullptr;         // ✓ cut the list in half

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Merge alternately
        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr) {  // ✓ 'second' not 'seond'
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;   // ✓ tmp1 not temp1
            second = tmp2;  // ✓ tmp2 not temp2
        }
    }
};
