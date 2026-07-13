#include<iostream>
using namespace std;

// 1291. Sequential Digits

/***************
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:
Input: low = 100, high = 300
Output: [123,234]

Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
***************/


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        // there are only about 45 numbers for 9-digit range
        // all are substrings of "123456789"
        string s = "123456789";

        vector<int> arr;

        for(int i = 2; i <= 9; i++)
        {
            for(int j = 0; i+j <= 9; j++)
            {
                int n = stoi(s.substr(j,i));
                if(n >= low && n <= high) arr.push_back(n);
            }
        }

        return arr;   
    }
};
