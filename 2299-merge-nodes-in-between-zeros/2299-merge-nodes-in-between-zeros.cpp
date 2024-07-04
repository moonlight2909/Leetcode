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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* low = head->next;  
        ListNode* high = head->next; 
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (high != NULL) {
            int sum = 0;
            while (high != NULL && high->val != 0) {
                sum += high->val;
                high = high->next;
            }
            if (sum != 0) {
                ListNode* Node = new ListNode(sum);
                temp->next = Node;
                temp = temp->next;
            }
            if (high != NULL) {
                high = high->next;
            }
            low = high; 
        }
        
        return dummy->next;
    }
};