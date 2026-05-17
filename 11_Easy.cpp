#include<iostream>
using namespace std;

// 21. Merge Two Sorted Lists

/***************
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
***************/


// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newNode = new ListNode(0);
        ListNode* curr = newNode;
        
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;


        while(curr1 != nullptr and curr2 != nullptr)
        {
            if(curr1->val <= curr2->val)
            {
                curr->next = curr1;
                curr1 = curr1->next;
            }
            else
            {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }

        if(curr1 != nullptr)
            curr->next = curr1;
        
        if(curr2 != nullptr)
            curr->next = curr2;

        return newNode->next;
    }
};
