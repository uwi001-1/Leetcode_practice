#include<iostream>
using namespace std;

// 2. Add Two Numbers

/***************
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
    Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
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
    vector<int> leftRightDifference(vector<int>& nums) 
    {
        // 1st handle left Sum
        vector<int> leftSum;
        leftSum.push_back(0);

        for(int i = 0; i < nums.size() - 1; i++)
        {
            leftSum.push_back(leftSum[i] + nums[i]);
        }

        // 2nd handle right sum
        vector<int> rightSum;
        rightSum.push_back(0);
        
        int loop = 0;
        for(int j = nums.size() - 1; j > 0; j--)
        {
            rightSum.push_back(rightSum[loop] + nums[j]);
            loop += 1;
        }

        // then reverse the rightSum array
        std::reverse(rightSum.begin(), rightSum.end());

        // 3rd make the left and right difference in an array
        vector<int> arr;
        for(int k = 0; k < nums.size(); k++)
        {
            // make sure the array element is an absolute number
            arr.push_back(abs(leftSum[k] - rightSum[k]));
        }

        return arr;
    }
};