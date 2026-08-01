#include<iostream>
using namespace std;

// 345. Reverse Vowels of a String

/***************
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:
Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:
Input: s = "leetcode"
Output: "leotcede"
***************/


class Solution {
public:
    string reverseVowels(string s) 
    {
        vector<char> arr;
        vector<bool> is;

        // if vowel pushed into char array
        // and the bool array index becomes true
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'a' || 
            s[i] == 'A' ||
            s[i] == 'e' ||
            s[i] == 'E' ||
            s[i] == 'i' ||
            s[i] == 'I' ||
            s[i] == 'o' ||
            s[i] == 'O' ||
            s[i] == 'u' ||
            s[i] == 'U')
            {
                arr.push_back(s[i]);
                is.push_back(true);
            }
            else is.push_back(false);
        } 

        int index = 1;
        // based on it being array or not insert the arr from back
        for(int j = 0; j < is.size(); j++)
        {
            if(is[j] == true)
            {
                s[j] = arr[arr.size() - index];
                index++;
            }
        }

        return s;  
    }
};
