#include<iostream>
using namespace std;

// 2487. Remove Nodes From Linked List

/***************
You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

Example 1:
Input: head = [5,2,13,3,8]
Output: [13,8]
    Explanation: The nodes that should be removed are 5, 2 and 3.
    - Node 13 is to the right of node 5.
    - Node 13 is to the right of node 2.
    - Node 8 is to the right of node 3.

Example 2:
Input: head = [1,1,1,1]
Output: [1,1,1,1]
    Explanation: Every node has value 1, so no nodes are removed.
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
