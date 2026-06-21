#include<iostream>
using namespace std;

// 148. Sort List

/***************
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
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
    ListNode* sortList(ListNode* head) 
    {
        // empty case
        if(head == nullptr) return nullptr; 

        // 1st make it into array
        vector<int> arr;    
        
        ListNode* curr = head;

        while(curr != nullptr)
        {
            arr.push_back(curr->val);

            curr = curr->next;
        }
        
        // sort it 
        std::sort(arr.begin(), arr.end());
        
        // push it into the linkelist into head
        ListNode* pHead = nullptr;
        
        // loop from behind
        for(int i =arr.size()-1; i >= 0; i--)
        {
            ListNode* pNew = new ListNode(arr[i]);

            // for the first node in the linked list
            if(pHead == nullptr) pHead = pNew;
            
            else
            {
                pNew->next = pHead;
                pHead = pNew;
            }
        } 

        return pHead;    
    }
};
