#include<iostream>
using namespace std;

// 605. Can Place Flowers

/***************
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, 
return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
***************/


class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        // loop throug both the string and add it to the new string
        // whichever finishes first, add the other one to the end 
        int maxSize = max(word1.size(), word2.size());
        string newWord = "";

        for(int i = 0; i < maxSize; i++)
        {
            if(i <= word1.size()-1) newWord += word1[i];
            if(i <= word2.size()-1) newWord += word2[i];
        }
        return newWord;    
    }
};
