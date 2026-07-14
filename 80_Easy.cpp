#include<iostream>
using namespace std;

// 349. Intersection of Two Arrays

/***************
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
    Explanation: [4,9] is also accepted.
***************/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> arr; 

        // let's sort both the array first
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end()); 

        for(int i = 0; i < nums1.size(); i++)
        {
            if(i > 0)
            {
                if(nums1[i] == nums1[i-1]) continue;
            }

            for(int j = 0; j < nums2.size(); j++)
            {
                if(j > 0)
                {
                    if(nums2[j] == nums2[j-1]) continue;
                }
                
                if(nums1[i] == nums2[j]) arr.push_back(nums1[i]);

                if(nums1[i] > nums2[j]) continue;
            }
        } 

        return arr;  
    }
};
