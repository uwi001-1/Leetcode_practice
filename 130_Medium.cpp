#include<iostream>
using namespace std;

// 3302. Find the Lexicographically Smallest Valid Sequence

/***************
You are given two strings word1 and word2.

A string x is called almost equal to y if you can change at most one character in x to make it identical to y.
A sequence of indices seq is called valid if:

The indices are sorted in ascending order.
Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2.
Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. 
If no such sequence of indices exists, return an empty array.

Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.

Example 1:
Input: word1 = "vbcca", word2 = "abc"
Output: [0,1,2]
Explanation:
The lexicographically smallest valid sequence of indices is [0, 1, 2]:
Change word1[0] to 'a'.
word1[1] is already 'b'.
word1[2] is already 'c'.

Example 2:
Input: word1 = "bacdc", word2 = "abc"
Output: [1,2,4]
Explanation:
The lexicographically smallest valid sequence of indices is [1, 2, 4]:
word1[1] is already 'a'.
Change word1[2] to 'b'.
word1[4] is already 'c'.

Example 3:
Input: word1 = "aaaaaa", word2 = "aaabc"
Output: []
Explanation:
There is no valid sequence of indices.

Example 4:
Input: word1 = "abc", word2 = "ab"
Output: [0,1]
***************/


class Solution {
public:
    vector<int> validSequence(string word1, string word2) 
    {
        int n = word1.size(), m = word2.size();
        
        // suf[i] = smallest index in word2 that can be matched EXACTLY 
        // as a subsequence using word1[i..n-1]
        vector<int> suf(n + 1, m);
        
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (suf[i] > 0 && word1[i] == word2[suf[i] - 1]) {
                suf[i]--;   // one more character matched from the back
            }
        }
        
        vector<int> res;
        int i = 0, j = 0;
        bool mismatchUsed = false;
        
        while (j < m) {
            if (i >= n) return {};   // ran out of word1, impossible
            
            if (word1[i] == word2[j]) {
                // free match, take it
                res.push_back(i);
                i++; j++;
            }
            else if (!mismatchUsed && suf[i + 1] <= j + 1) {
                // use this as our ONE allowed change
                res.push_back(i);
                i++; j++;
                mismatchUsed = true;
            }
            else {
                // skip this index of word1, look further
                i++;
            }
        }
        
        return res;    
    }
};
