#include<iostream>
using namespace std;

// 2645. Minimum Additions to Make Valid String

/***************
Given a string word to which you can insert letters "a", "b" or "c" anywhere and any number of times, 
return the minimum number of letters that must be inserted so that word becomes valid.

A string is called valid if it can be formed by concatenating the string "abc" several times.

Example 1:
Input: word = "b"
Output: 2
Explanation: Insert the letter "a" right before "b", and the letter "c" right next to "b" to obtain the valid string "abc".

Example 2:
Input: word = "aaa"
Output: 6
Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".

Example 3:
Input: word = "abc"
Output: 0
Explanation: word is already valid. No modifications are needed.
***************/


class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());

        // for last three
        int product = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];

        // for taking the negative higher first two and last 1
        int pro = product;
        if(nums[0] < 0 && nums[1] < 0)
        {
            pro = nums[0] * nums[1] * nums[nums.size()-1];
        }

        int ans = max(pro, product);

        // if ans is negative and we have a zero in the array
        if(ans < 0)
        {
            for(int i = 0; i < nums.size(); i++) if(nums[i] == 0) return 0;
        }

        return ans;    
    }
};
