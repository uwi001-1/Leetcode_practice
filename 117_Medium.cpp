#include<iostream>
using namespace std;

// 61. Rotate List

/***************
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
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
