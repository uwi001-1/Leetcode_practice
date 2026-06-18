#include<iostream>
using namespace std;

// 3614. Process String with Special Operations II

/***************
You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and '%'.
You are also given an integer k.
Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
    A '*' removes the last character from result, if it exists.
    A '#' duplicates the current result and appends it to itself.
    A '%' reverses the current result.
Return the kth character of the final string result. If k is out of the bounds of result, return '.'.

Example 1:
Input: s = "a#b%*", k = 1
Output: "a"
    Explanation:
i	s[i]	Operation	Current result
0	'a'	Append 'a'	"a"
1	'#'	Duplicate result	"aa"
2	'b'	Append 'b'	"aab"
3	'%'	Reverse result	"baa"
4	'*'	Remove the last character	"ba"
The final result is "ba". The character at index k = 1 is 'a'.

Example 2:
Input: s = "cd%#*#", k = 3
Output: "d"
    Explanation:
i	s[i]	Operation	Current result
0	'c'	Append 'c'	"c"
1	'd'	Append 'd'	"cd"
2	'%'	Reverse result	"dc"
3	'#'	Duplicate result	"dcdc"
4	'*'	Remove the last character	"dcd"
5	'#'	Duplicate result	"dcddcd"
The final result is "dcddcd". The character at index k = 3 is 'd'.

Example 3:
Input: s = "z*#", k = 0
Output: "."
    Explanation:
i	s[i]	Operation	Current result
0	'z'	Append 'z'	"z"
1	'*'	Remove the last character	""
2	'#'	Duplicate the string	""
The final result is "". Since index k = 0 is out of bounds, the output is '.'.
***************/


class Solution {
public:
    char processStr(string s, long long k) 
    {
        long long n = 0;
        vector<long long> arr;

        // forward pass
        for(char i : s)
        {
            // if no special character just increase the n
            if(i != '*' && i != '#' && i != '%')
            {
                n += 1;
            }

            // if "*" decrease the n
            else if(i == '*')
            {
                // but if n is less than 0 
                if(n > 0) n -= 1;
            }

            // if "#" double the n 
            else if(i == '#')
            {
                n += n;
            }

            // push the n in the array
            arr.push_back(n);
        }

        // if k is out of bound return '.'
        if(k >= n) return '.';

        // backward pass
        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] != '*' && s[i] != '#' && s[i] != '%')
            {
                // if k points to this character, return it
                if(k == arr[i] - 1) return s[i];
            }

            else if(s[i] == '*')
            {
                // do nth
                continue;
            }

            else if(s[i] == '#')
            {
                // if k >= half, adjust k
                if(k >= arr[i]/2) k = k - arr[i]/2;
            }

            else if(s[i] == '%')
            {       
                // reverse the index
                k = arr[i] - 1 - k;
            }
        }

        return '.';
    }
};


// doesn't work for too long strings 
// ERROR Memory Limit Exceeded
/**************
class Solution {
public:
    char processStr(string s, long long k) 
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
        if(k >= n.size()) return '.';
        return n.at(k); // this is with bounds checking of (n[k];)

        return '.';
    }
};
*****************/