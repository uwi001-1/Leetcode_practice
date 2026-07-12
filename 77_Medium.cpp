#include<iostream>
using namespace std;

// 1276. Number of Burgers with No Waste of Ingredients

/***************
Given two integers tomatoSlices and cheeseSlices. The ingredients of different burgers are as follows:

Jumbo Burger: 4 tomato slices and 1 cheese slice.
Small Burger: 2 Tomato slices and 1 cheese slice.

Return [total_jumbo, total_small] so that the number of remaining tomatoSlices equal to 0 and the number of remaining cheeseSlices equal to 0. If it is not possible to make the remaining tomatoSlices and cheeseSlices equal to 0 return [].

Example 1:
Input: tomatoSlices = 16, cheeseSlices = 7
Output: [1,6]
    Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese.
    There will be no remaining ingredients.

Example 2:
Input: tomatoSlices = 17, cheeseSlices = 4
Output: []
    Explantion: There will be no way to use all ingredients to make small and jumbo burgers.

Example 3:
Input: tomatoSlices = 4, cheeseSlices = 17
Output: []
    Explantion: Making 1 jumbo burger there will be 16 cheese remaining and making 2 small burgers there will be 15 cheese remaining.
***************/


// HASH TABLE
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        // in a temp array and sort it
        vector<int> s = arr;
        std::sort(s.begin(), s.end());   

        // The rank of each element is the number of unique elements smaller than it in the sorted array plus one.
        
        // create a hash table (dictionary)
        // stores number -> rank
        unordered_map<int, int> rankMap;

        int rank = 1;

        // loop through the sorted array
        for(int i = 0; i < s.size(); i++)
        {
            // not seen before
            if(rankMap.find(s[i]) == rankMap.end()) // If this number is not already in the hash table, give it a new rank. 
            {
                rankMap[s[i]] = rank;
                rank++;
            }
            // seen before ignore as the same rank

            // 10 -> 1
            // 20 -> 2

            // It's stored like this 
            // rankMap[40] = 4
        }

        // loop through the original array
        for(int j = 0; j < arr.size(); j++)
        {
            arr[j] = rankMap[arr[j]];
        }

        return arr;
    }
};
