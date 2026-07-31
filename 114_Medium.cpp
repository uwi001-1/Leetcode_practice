#include<iostream>
using namespace std;

// 3760. Maximum Substrings With Distinct Start

/***************
You are given a string s consisting of lowercase English letters.

Return an integer denoting the maximum number of substrings you can split s into such that each substring starts with a distinct character 
(i.e., no two substrings start with the same character).

Example 1:
Input: s = "abab"
Output: 2
Explanation:
Split "abab" into "a" and "bab".
Each substring starts with a distinct character i.e 'a' and 'b'. Thus, the answer is 2.

Example 2:
Input: s = "abcd"
Output: 4
Explanation:
Split "abcd" into "a", "b", "c", and "d".
Each substring starts with a distinct character. Thus, the answer is 4.

Example 3:
Input: s = "aaaa"
Output: 1
Explanation:
All characters in "aaaa" are 'a'.
Only one substring can start with 'a'. Thus, the answer is 1.
***************/


class Solution {
public:
    int minimumPushes(string word) 
    {
        // sort the word
        std::sort(word.begin(), word.end());
        vector<int> arr;
        int count = 1;

        // in the array with the size of the word
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == word[i+1]) count++;
            else
            {
                arr.push_back(count);
                count = 1;
            }
        }

        // sort the array in descending order
        std::sort(arr.begin(), arr.end(), greater<int>());
        int ans = 0;

        // add the arr element based on size
        for(int j = 0; j < arr.size(); j++)
        {
            if(j < 8) ans += arr[j];
            else if(j < 16) ans += (arr[j] * 2);
            else if(j < 24) ans += (arr[j] * 3);
            else ans += (arr[j] * 4);
        }

        return ans;
    }
};
