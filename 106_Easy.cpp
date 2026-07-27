#include<iostream>
using namespace std;

// 2645. Minimum Additions to Make Valid String

/***************
Given a string word to which you can insert letters "a", "b" or "c" anywhere and any number of times, 
return the minimum number of letters that must be inserted so that word becomes valid.

A string is called valid if it can be formed by concatenating the string "abc" several times.

Example 1:
Input: word = "b"
Output: 2
Explanation: Insert the letter "a" right before "b", and the letter "c" right next to "b" to obtain the valid string "abc".

Example 2:
Input: word = "aaa"
Output: 6
Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".

Example 3:
Input: word = "abc"
Output: 0
Explanation: word is already valid. No modifications are needed.
***************/


class Solution {
public:
    int addMinimum(string word) 
    {
        int count = 0;

        // loop the string and add to count as needed
        int i;
        for (i = 0; i < word.size(); i++)
        {
            // a
            if(word[i] == 'a')
            {
                // if a is in the end
                if(i == word.size()-1) 
                {
                    count = count + 2;
                    continue;
                }

                if(i + 2 < word.size() && word[i+1] == 'b' && word[i+2] == 'c') i = i+2;
                else if(i + 1 < word.size() && word[i+1] == 'b')
                {
                    i++; 
                    count++; 
                } 
                else if(i + 1 < word.size() && word[i+1] == 'c') 
                {
                    i++; 
                    count++;
                }
                else count = count + 2;
            }

            // b
            else if(word[i] == 'b')
            {
                // we need to add for a first
                count++;

                // for c, if b is in the end
                if(i == word.size()-1)
                {
                    count++;
                    continue;
                }
                
                if(i + 1 < word.size() && word[i+1] == 'c') i++;
                else count++;
            }

            // b
            else if(word[i] == 'c')
            {
                // handle c when it's the only letter
                count = count + 2;
            }
        } 

        return count;   
    }
};
