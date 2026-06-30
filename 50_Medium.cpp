#include<iostream>
using namespace std;

// 1358. Number of Substrings Containing All Three Characters

/***************
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:
Input: s = "aaacb"
Output: 3
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Example 3:
Input: s = "abc"
Output: 1
***************/


class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        // Brute force checking will cause Time Limit Exceed
        // check every possible substring and count if it has all three letters
        
        // So, do the Sliding Window method
        // keep a "window" (a range [i, j]) over the string, and you grow or shrink it one step at a time
        // updating your knowledge instead of recalculating

        int total = 0;
        
        // left edge of the window
        int i = 0;

        // counts of 'a', 'b', 'c' currently inside the window
        // cnt[0] = how many 'a's are in the window, cnt[1] = how many 'b's, cnt[2] = how many 'c's
        int cnt[3] = {0, 0, 0};
        

        // j is the right edge, moving one step at a time
        for(int j = 0; j < s.size(); j++)
        {
            // "include s[j] in the window," and bump up the count for whichever letter it is
            // s[j] - 'a' converts 'a'→0, 'b'→1, 'c'→2 — just an array index trick
            cnt[s[j] - 'a'] += 1;

            // shrink from left while window has all three
            while(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0)
            {
                // Once the window [i, j] contains at least one of each letter, we try to shrink it from the left as much as possible while still having all three
                cnt[s[i] - 'a'] -= 1;
                i += 1;
            }
            
            // how many valid substrings end at j
            total += i; 
        }

        return total;
    }
};
