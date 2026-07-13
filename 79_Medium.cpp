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


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        // there are only about 45 numbers for 9-digit range
        // all are substrings of "123456789"
        string s = "123456789";

        vector<int> arr;

        for(int i = 2; i <= 9; i++)
        {
            for(int j = 0; i+j <= 9; j++)
            {
                int n = stoi(s.substr(j,i));
                if(n >= low && n <= high) arr.push_back(n);
            }
        }

        return arr;   
    }
};
