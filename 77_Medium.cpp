#include<iostream>
using namespace std;

// 1331. Rank Transform of an Array

/***************
Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
 

Example 1:
Input: arr = [40,10,20,30]
Output: [4,1,2,3]
    Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

Example 2:
Input: arr = [100,100,100]
Output: [1,1,1]
    Explanation: Same elements share the same rank.

Example 3:
Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
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
