#include<iostream>
using namespace std;

// 1260. Shift 2D Grid

/***************
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:
    Element at grid[i][j] moves to grid[i][j + 1].
    Element at grid[i][n - 1] moves to grid[i + 1][0].
    Element at grid[m - 1][n - 1] moves to grid[0][0].
    Return the 2D grid after applying shift operation k times.

Example 1:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]

Example 2:
Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

Example 3:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]
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
