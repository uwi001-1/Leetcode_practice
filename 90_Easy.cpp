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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        // let's first find x = a-1 and y = b+1
        int index = -1;

        ListNode* curr1 = list1;
        ListNode* x = list1;
        ListNode* y = list1;

        while(curr1 != nullptr)
        {
            index++;

            if(index == a-1) x = curr1;
            if(index == b+1) y = curr1;

            // to loop through the list1
            curr1 = curr1->next;

            // if both x and y has been assigned, break the loop of list1
            if(x != list1 && y != list1) break;
        }
        // if b is the last element and y had not been assigned
        if(y == list1) y = nullptr;

        // now connect x and list2
        x->next = list2;

        // no need to connect list1 and list2 at the end
        if(y == nullptr) return list1;

        // loop list2 to now connect with list1 
        // reach the end of list2
        ListNode* curr2 = list2;
        while(curr2->next != nullptr)
        {
            curr2 = curr2->next;
        }
        curr2->next = y;

        // every changes has been made to list1 so return it
        return list1;
    }
};
