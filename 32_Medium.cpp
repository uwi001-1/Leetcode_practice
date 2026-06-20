#include<iostream>
using namespace std;

// 148. Sort List

/***************
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []
***************/


class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
       // if s is empty then it can be made by t so return true
        if(s == "") return true;

        bool found = false;

        // initiate it outside to not over loop 
        int i = 0;

        for(char index : s)
        {
            // each new char of s, the bool found becomes false
            found = false;

            // if the t has come to an end and a char of s was not found then it's false
            if(i == t.size()) break;
            
            for(i; i < t.size(); i++)
            {
                if(index == t[i])
                {
                    found = true;

                    // i is incremented as we need to move ahead to another mode for cases like 'aaaaa' as s
                    i += 1;
                    
                    break;
                }
            } 
        }
        return found;
    }
};
