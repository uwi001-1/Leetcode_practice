#include<iostream>
using namespace std;

// 1464. Maximum Product of Two Elements in an Array

/***************
Given the array of integers nums, you will choose two different indices i and j of that array. 
Return the maximum value of (nums[i]-1)*(nums[j]-1).

Example 1:
Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, 
that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

Example 2:
Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.

Example 3:
Input: nums = [3,7]
Output: 12
***************/


class Solution {
public:
    int addMinimum(string word) 
    {
        int count = 0;

        // loop the string and add to count as needed
        int i;
        for (i = 0; i < word.size(); i++)
        {
            // a
            if(word[i] == 'a')
            {
                // if a is in the end
                if(i == word.size()-1) 
                {
                    count = count + 2;
                    continue;
                }

                if(i + 2 < word.size() && word[i+1] == 'b' && word[i+2] == 'c') i = i+2;
                else if(i + 1 < word.size() && word[i+1] == 'b')
                {
                    i++; 
                    count++; 
                } 
                else if(i + 1 < word.size() && word[i+1] == 'c') 
                {
                    i++; 
                    count++;
                }
                else count = count + 2;
            }

            // b
            else if(word[i] == 'b')
            {
                // we need to add for a first
                count++;

                // for c, if b is in the end
                if(i == word.size()-1)
                {
                    count++;
                    continue;
                }
                
                if(i + 1 < word.size() && word[i+1] == 'c') i++;
                else count++;
            }

            // b
            else if(word[i] == 'c')
            {
                // handle c when it's the only letter
                count = count + 2;
            }
        } 

        return count;   
    }
};
