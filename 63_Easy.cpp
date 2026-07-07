#include<iostream>
using namespace std;

// 328. Odd Even Linked List

/***************
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
***************/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} 
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// odd - even - odd - even - odd
// --> odd - odd - odd - even - even

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        vector<int> arr; 

        // push into an array
        ListNode* curr = head;  
        while(curr != nullptr)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        ListNode* pHead = nullptr;
        // if even
        if(arr.size() % 2 == 0) 
        {
            // first even indices
            for(int i = arr.size()-1; i >= 0; i -= 2)
            {
                ListNode* pNew = new ListNode(arr[i]);

                if(pHead == nullptr) pHead = pNew;
                else
                {
                    pNew->next = pHead;
                    pHead = pNew;
                }
            }
            // then odd indices
            for(int j = arr.size()-2; j >= 0; j -= 2)
            {
                ListNode* pNew = new ListNode(arr[j]);

                pNew->next = pHead;
                pHead = pNew;
            }
        }

        // if odd
        else
        {
            // first even indices 
            for(int k = arr.size()-2; k >= 0; k -= 2)
            {
                ListNode* pNew = new ListNode(arr[k]);

                if(pHead == nullptr) pHead = pNew;
                else
                {
                    pNew->next = pHead;
                    pHead = pNew;
                }
            }
            // then odd indices
            for(int l = arr.size()-1; l >= 0; l -= 2)
            {
                ListNode* pNew = new ListNode(arr[l]);

                pNew->next = pHead;
                pHead = pNew;
            }
        }
        
        return pHead;
    }
};
