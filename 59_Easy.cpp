#include<iostream>
using namespace std;

// 383. Ransom Note

/***************
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true
***************/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // if there are not enough length of magazine, then we can't complete the ransomNote
        if(magazine.size() < ransomNote.size()) return false; 

        bool once = false;

        // loop the ransomNote
        int i = 0;

        while(true)
        {
            once = false; 

            for(int j = 0; j < magazine.size(); j++)
            {
                if(ransomNote[i] == magazine[j])
                {
                    // change the letter of ransomNote found in magazine to ' ' 
                    magazine[j] = ' ';
                    once = true;
                    break;
                }
            }

            i++; 
            
            // if one of the letter is not found or we searched all of the ransomNote
            if(i >= ransomNote.size() || once == false) break;
        }
        return once;
    }
};
