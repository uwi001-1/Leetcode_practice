#include<iostream>
using namespace std;

// 61. Rotate List

/***************
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        // base case 
        if(k == 0 || head == nullptr) return head; 

        // first insert the linkedlist into array
        vector<int> arr;
        ListNode* current = head;
        while(current != nullptr)
        {
            arr.push_back(current->val);
            current = current->next;
        }    

        // do this to loop as needed; no over loop
        k = k % arr.size();

        // no need to loop 
        if(k == 0) return head; 

        // loop the rotated side
        ListNode* pHead = nullptr; 
        ListNode* pCurr = pHead;
        for(int i = arr.size() - k; i < arr.size(); i++)
        {
            ListNode* pNew = new ListNode(arr[i]);
            
            // if first element in the linked list 
            if(pHead == nullptr)
            {
                pHead = pNew;
                pCurr = pHead; 
            }
            else
            {
                pCurr->next = pNew;
                pCurr = pNew;
            }
        }

        // loop the left over 
        for(int j = 0; j < arr.size() - k; j++)
        {
            ListNode* pNew = new ListNode(arr[j]);
            pCurr->next = pNew;
            pCurr = pNew;
        }

        return pHead;
    }
};
