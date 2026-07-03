#include<iostream>
using namespace std;

// 120. Triangle

/***************
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. 
More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
    Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
    The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10
***************/


class Solution {
public:
    // solve it using recursion
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        // base 1
        if(p == nullptr && q == nullptr) return true;

        // base 2
        if(p == nullptr || q == nullptr) return false;

        // base 3
        if(p->val != q->val) return false;

        // recursion case to check both the right and left tree
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
