#include<iostream>
using namespace std;

// 1669. Merge In Between Linked Lists

/***************
You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

Build the result list and return its head.

Example 1:  
Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
    Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place.

Example 2:
Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
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
