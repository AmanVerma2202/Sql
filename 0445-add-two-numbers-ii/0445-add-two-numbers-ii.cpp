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
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Reverse both input linked lists
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode* result = new ListNode(0); // Dummy node to start the result list
        ListNode* ptr = result;
        int carry = 0;

        // Add the two numbers
        while (l1 != nullptr || l2 != nullptr ) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            sum = sum % 10;
            
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
        }

        // Reverse the result list to get the final answer
        result = reverseList(result->next);
        return result;
    }
};
