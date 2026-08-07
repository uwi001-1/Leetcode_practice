#include<iostream>
using namespace std;

// 3190. Find Minimum Operations to Make All Elements Divisible by Three

/***************
You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.

Return the minimum number of operations to make all elements of nums divisible by 3.

Example 1:
Input: nums = [1,2,3,4]
Output: 3
Explanation:
All array elements can be made divisible by 3 using 3 operations:
Subtract 1 from 1.
Add 1 to 2.
Subtract 1 from 4.

Example 2:
Input: nums = [3,6,9]
Output: 0
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
