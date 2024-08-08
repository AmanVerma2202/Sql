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
    // Reverse the linked list pointed by 'head', update 'prev' to point to the new head.
    // Returns the length of the reversed list.
    int reverse(ListNode* head, ListNode*& prev) {
        ListNode* ptr = head;
        ListNode* next = NULL;
        int len = 0;
        while (ptr) {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
            len++;
        }
        return len;
    }

    // Main function to add two numbers represented as linked lists.
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = nullptr;
        ListNode* r2 = nullptr;

        // Reverse both linked lists to simplify addition.
        int len1 = reverse(l1, r1);
        int len2 = reverse(l2, r2);

        // Ensure 'r1' represents the longer number and 'r2' represents the shorter number.
        if (len1 < len2) {
            swap(len1, len2);
            swap(r1, r2);
        }

        int carry = 0;
        ListNode* ptr1 = r1;
        ListNode* ptr2 = r2;
        ListNode* ans = NULL;
        ListNode* next = NULL;

        // Iterate through the longer list and add corresponding digits from the shorter list.
        while (ptr1) {
            if (ptr2) {
                ptr1->val += ptr2->val + carry;
                ptr2 = ptr2->next;
            } 
            else {
                ptr1->val += carry;
            }

            // Update carry and calculate new value for the current digit.
            carry = ptr1->val / 10;
            ptr1->val %= 10;

            // Reverse the processed node and move to the next node.
            next = ptr1->next;
            ptr1->next = ans;
            ans = ptr1;
            ptr1 = next;
        }

        // If there is any carry left after processing all digits, add it as a new node.
        if (carry == 1) {
            ListNode* newNode = new ListNode(1);
            newNode->next = ans;
            ans = newNode;
        }
        return ans;
    }
};