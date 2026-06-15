#include<iostream>
using namespace std;

// 2095. Delete the Middle Node of a Linked List

/***************
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

Example 1:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
    Explanation:
    The above figure represents the given linked list. The indices of the nodes are written below.
    Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
    We return the new list after removing this node. 

Example 2:
Input: head = [1,2,3,4]
Output: [1,2,4]
    Explanation:
    The above figure represents the given linked list.
    For n = 4, node 2 with value 3 is the middle node, which is marked in red.

Example 3:  
Input: head = [2,1]
Output: [2]
    Explanation:
    The above figure represents the given linked list.
    For n = 2, node 1 with value 1 is the middle node, which is marked in red.
    Node 0 with value 2 is the only node remaining after removing node 1.
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
    int pairSum(ListNode* head) 
    {
        // create a new int array to push al the values into it
        // so we can handle it as an 
        vector<int> arr;
        ListNode* curr = head;

        // loop through the linked list and push the value into the array
        while(curr != nullptr)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        int largest = 0;
        int sum; 

        // now let's loop through the loop and find the maximum twin sum
        for(int i = 0; i < arr.size()/2 ; i++)
        {
            // add the node and the twin of the node
            sum = arr[i] + arr[arr.size()-1-i];

            if(sum > largest) largest = sum;
        }

        return largest;
    }
};
