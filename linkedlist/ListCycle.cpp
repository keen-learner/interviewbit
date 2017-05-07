/*
List Cycle
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 


LEETCODE : # 141: https://leetcode.com/problems/linked-list-cycle/#/description 
LEETCODE : # 142: https://leetcode.com/problems/linked-list-cycle-ii/#/description 

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::detectCycle(ListNode* head) {
    // not required:
    // if (!head || !head->next) return NULL;
    auto *slow = head;
    auto *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { // cycle found
            fast = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
 
