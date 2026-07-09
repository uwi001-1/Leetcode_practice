#include<iostream>
using namespace std;

// 242. Valid Anagram

/***************
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
***************/


class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        if(s == t) return true;
        return false;
    }
};
