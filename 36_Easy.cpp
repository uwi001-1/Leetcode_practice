#include<iostream>
using namespace std;

// 1189. Maximum Number of Balloons

/***************
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:
Input: text = "nlaebolko"
Output: 1

Example 2:
Input: text = "loonbalxballpoon"
Output: 2

Example 3:
Input: text = "leetcode"
Output: 0
***************/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        // (there seems to be no exception cases to be handled)
        int loop = 0;

        // loop and add at the end of the list
        while(loop != n)
        {
            nums1[m + loop] = nums2[loop];
            loop += 1;
        }

        // sort the list nums1
        std::sort(nums1.begin(), nums1.end());
    }
};
