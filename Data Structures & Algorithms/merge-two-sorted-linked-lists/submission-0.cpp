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
    // TC : O(n)
    // SC : O(n)
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     if(list1 == nullptr) return list2;
    //     if(list2 == nullptr) return list1;
    //     ListNode* head = nullptr;
    //     ListNode* tail = nullptr;
    
    //     while(list1 != nullptr){
    //         int num1 = list1->val;

    //         if(list2 == nullptr){
    //             ListNode* node = new ListNode(num1);
    //             if(head != nullptr){
    //                 tail->next = node;
    //                 tail = tail->next;
    //             }  else {
    //                 head = node;
    //                 tail = node;
    //             }
    //             list1 = list1->next;
    //             continue;
    //         };

    //         int num2 = list2->val;

    //         if(num1 > num2){
    //             ListNode* node = new ListNode(num2);
    //             if(head != nullptr){
    //                 tail->next = node;
    //                 tail = tail->next;
    //             } else {
    //                 head = node;
    //                 tail = node;
    //             }
    //             list2 = list2->next;
    //         } else {
    //             ListNode* node = new ListNode(num1);
    //             if(head != nullptr){
    //                 tail->next = node;
    //                 tail = tail->next;
    //             }  else {
    //                 head = node;
    //                 tail = node;
    //             }
    //             list1 = list1->next;
    //         }
    //     }

    //     tail->next = list2;

    //     return head;
    // }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    ListNode* tail = &dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    tail->next = (list1 != nullptr) ? list1 : list2;

    return dummy.next;
}
};
