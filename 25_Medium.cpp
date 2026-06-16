#include<iostream>
using namespace std;

// 3612. Process String with Special Operations I

/***************
You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.
Build a new string result by processing s according to the following rules from left to right:
If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.

Return the final string result after processing all characters in s.

Example 1:
Input: s = "a#b%*"
Output: "ba"
    Explanation:
i	s[i]	Operation	Current result
0	'a'	Append 'a'	"a"
1	'#'	Duplicate result	"aa"
2	'b'	Append 'b'	"aab"
3	'%'	Reverse result	"baa"
4	'*'	Remove the last character	"ba"
Thus, the final result is "ba".

Example 2:
Input: s = "z*#"
Output: ""
    Explanation:
i	s[i]	Operation	Current result
0	'z'	Append 'z'	"z"
1	'*'	Remove the last character	""
2	'#'	Duplicate the string	""
Thus, the final result is "".
***************/


class Solution {
public:
    string processStr(string s) 
    {
        string n = "";
        for(char i : s)
        {
            // if no special character just append it to the new string
            if(i != '*' && i != '#' && i != '%')
            {
                n.push_back(i);
            }

            // if "*" pop the last input character
            else if(i == '*')
            {
                // but if the new string is empty just continue as we can't pop an empty string
                if(n.size() == 0) continue;
                n.pop_back();
                
                // could use 
                // if(!n.empty()) n.pop_back();
            }

            // if "#" duplicates the whole of the new string and append 
            else if(i == '#')
            {
                n += n;
            }

            // if "%" reverse the string
            else if(i == '%')
            {
                std::reverse(n.begin(), n.end());
            }
        }
        return n;
    }
};
