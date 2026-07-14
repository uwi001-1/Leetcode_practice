#include<iostream>
using namespace std;

// 349. Intersection of Two Arrays

/***************
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
    Explanation: [4,9] is also accepted.
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
    ListNode* removeNodes(ListNode* head) 
    {
        // push the values into an array
        vector<int> arr;
        ListNode* curr = head;

        while(curr != nullptr)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        int max = arr[arr.size()-1];
        
        // push the first one to the head as it will always be there
        ListNode* pHead = new ListNode(max);

        // now loop from behind to select the max values
        for(int i = arr.size()-2; i >= 0; i--)
        {
            if(arr[i] >= max)
            {
                max = arr[i];
                ListNode* pNew = new ListNode(max);
                pNew->next = pHead;
                pHead = pNew;
            }
        }

        return pHead;
    }
};
