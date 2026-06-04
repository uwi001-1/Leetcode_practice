#include<iostream>
using namespace std;

// 203. Remove Linked List Elements

/***************
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []
***************/


class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) 
    {
        int count = 0;
        for(int num : nums)
        {
            while(num > 0)
            {
                int one = num % 10;  // get the last digit
                num = num / 10;      // remove the last digit
                
                // count the number of times the digits are same
                if(one == digit)
                {
                    count += 1;
                }
            }
        }
        return count; 
    }
};
