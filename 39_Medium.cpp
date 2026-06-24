#include<iostream>
using namespace std;

// 2574. Left and Right Sum Differences

/***************
You are given a 0-indexed integer array nums of size n.

Define two arrays leftSum and rightSum where:
    leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
    rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.

Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.

Example 1:
Input: nums = [10,4,8,3]
Output: [15,1,11,22]
    Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
    The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].

Example 2:
Input: nums = [1]
Output: [0]
    Explanation: The array leftSum is [0] and the array rightSum is [0].
    The array answer is [|0 - 0|] = [0].
***************/


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