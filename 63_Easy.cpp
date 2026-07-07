#include<iostream>
using namespace std;

// 3754. Concatenate Non-Zero Digits and Multiply by Sum I

/***************
You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

Example 1:
Input: n = 10203004
Output: 12340
    Explanation:
    The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
    The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
    Therefore, the answer is x * sum = 1234 * 10 = 12340.

Example 2:
Input: n = 1000
Output: 1
    Explanation:
    The non-zero digit is 1, so x = 1 and sum = 1.
    Therefore, the answer is x * sum = 1 * 1 = 1.
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
