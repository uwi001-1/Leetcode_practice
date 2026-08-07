#include<iostream>
using namespace std;

// 82. Remove Duplicates from Sorted List II

/***************
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
***************/


// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        vector<int> arr;

        //push into an array
        ListNode* curr = head;
        int rep = -200;
        while(curr != nullptr)
        {
            // if rep don't push just head ahead
            if(curr->val == rep)
            {
                curr = curr->next;
                continue;
            }

            if(curr->next != nullptr)
            {
                // check for repetition
                if(curr->next->val != curr->val) 
                {
                    arr.push_back(curr->val);
                }
                else rep = curr->val;
            }
            else
            {
                // push the last value if it not rep
                if(curr->val != rep) arr.push_back(curr->val);
            }
            
            curr = curr->next;
        }

        // if array is empty 
        if(arr.empty()) return nullptr;

        // now push the array into a linked list in the head
        ListNode* pHead = nullptr;
        for(int i = arr.size()-1; i >=0; i--)
        {
            ListNode* pNew = new ListNode(arr[i]);

            // enter new
            if(pHead == nullptr)
            {
                pHead = pNew;
            }
            else
            {
                pNew->next = pHead;
                pHead = pNew;
            }
        }
        
        return pHead;    
    }
};
