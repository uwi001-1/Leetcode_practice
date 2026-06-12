#include<iostream>
using namespace std;

// 2535. Difference Between Element Sum and Digit Sum of an Array

/***************
Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

Example 1:
Input: s = "lEetcOde"
Output: "lEOtcede"
    Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.

Example 2:
Input: s = "lYmpH"
Output: "lYmpH"
    Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".
***************/


// this is O(nlogn)
class Solution {
public:
    string sortVowels(string s) 
    {
        // make new character to push the vowels
        vector<char> m;

        for(int i = 0; i < s.size(); i++)
        {
            // if the char is not vowel then continue
            if(s[i] != 'A' 
            && s[i] != 'E' 
            && s[i] != 'O'
            && s[i] != 'I' 
            && s[i] != 'U'
            && s[i] != 'a' 
            && s[i] != 'e' 
            && s[i] != 'i'
            && s[i] != 'o' 
            && s[i] != 'u')
                continue;
            
            m.push_back(s[i]);
        }

        // sort the vowels based on their ascii values
        std::sort(m.begin(), m.end());
        
        // for the vowels string
        int num = 0;

        for(int i = 0; i < s.size(); i++)
        {
            // if the char is not vowel then continue
            if(s[i] != 'A' 
            && s[i] != 'E' 
            && s[i] != 'O'
            && s[i] != 'I' 
            && s[i] != 'U'
            && s[i] != 'a' 
            && s[i] != 'e' 
            && s[i] != 'i'
            && s[i] != 'o' 
            && s[i] != 'u')
                continue;
            
            // if it is a vowel replace it with the string in vowel
            s[i] = m[num];
            num += 1;
        }
        return s;
    };
};


// this is O(n^2) as it has selection sort
class Solution {
public:
    string sortVowels(string s) 
    {
        for(int i = 0; i < s.size(); i++)
        {
            // if the char is not vowel then continue
            if(s[i] != 'A' 
            && s[i] != 'E' 
            && s[i] != 'O'
            && s[i] != 'I' 
            && s[i] != 'U'
            && s[i] != 'a' 
            && s[i] != 'e' 
            && s[i] != 'i'
            && s[i] != 'o' 
            && s[i] != 'u')
                continue;

            // assign the ascii value of the char to smallest
            int smallest = s[i];
            int small = i;
            int num;

            // selection sort (O(n2))
            for(int j = i; j < s.size(); j++)
            {
                if(s[j] != 'A' 
                && s[j] != 'E' 
                && s[j] != 'O'
                && s[j] != 'I' 
                && s[j] != 'U'
                && s[j] != 'a' 
                && s[j] != 'e' 
                && s[j] != 'i'
                && s[j] != 'o' 
                && s[j] != 'u')
                    continue;
                num = s[j];
                if(num <= smallest)
                {
                    smallest = num;
                    small = j;
                }
            }
            // swap the smallest ascii value char with the currect char
            swap(s[i], s[small]);
        }
        return s;
    };
};
