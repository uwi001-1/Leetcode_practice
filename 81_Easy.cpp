#include<iostream>
using namespace std;

// 3658. GCD of Odd and Even Sums

/***************
You are given an integer n. Your task is to compute the GCD (greatest common divisor) of two values:
sumOdd: the sum of the smallest n positive odd numbers.
sumEven: the sum of the smallest n positive even numbers.

Return the GCD of sumOdd and sumEven.

Example 1:
Input: n = 4
Output: 4
    Explanation:
Sum of the first 4 odd numbers sumOdd = 1 + 3 + 5 + 7 = 16
Sum of the first 4 even numbers sumEven = 2 + 4 + 6 + 8 = 20
Hence, GCD(sumOdd, sumEven) = GCD(16, 20) = 4.

Example 2:
Input: n = 5
Output: 5
    Explanation:
Sum of the first 5 odd numbers sumOdd = 1 + 3 + 5 + 7 + 9 = 25
Sum of the first 5 even numbers sumEven = 2 + 4 + 6 + 8 + 10 = 30
Hence, GCD(sumOdd, sumEven) = GCD(25, 30) = 5.
***************/


// Linear Search 
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
