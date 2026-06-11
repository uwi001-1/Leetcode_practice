#include<iostream>
using namespace std;

// 203. Remove Linked List Elements

/***************
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []
***************/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} 
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        // if LL is empty, we can't dereference the nullptr at head
        if(head == nullptr) return head;

        while(true)
        {
            // for cases like --> head = [7,7,7,7], val = 7
            if(head == nullptr) return head;
            
            if(head->val == val)
            {
                head = head->next;
            }
            else
            {
                // if head ain't the val then move forward
                break;
            }
        }
        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr != nullptr)
        {
            if(curr->val == val)
            {
                // remove it and keep prev at the same
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                // move one step ahead with both prev and curr
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
