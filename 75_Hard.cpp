#include<iostream>
using namespace std;

// 899. Orderly Queue

/***************
You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string.

Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

Example 1:
Input: s = "cba", k = 1
Output: "acb"
    Explanation: 
    In the first move, we move the 1st character 'c' to the end, obtaining the string "bac".
    In the second move, we move the 1st character 'b' to the end, obtaining the final result "acb".

Example 2:
Input: s = "baaca", k = 3
Output: "aaabc"
    Explanation: 
    In the first move, we move the 1st character 'b' to the end, obtaining the string "aacab".
    In the second move, we move the 3rd character 'c' to the end, obtaining the final result "aaabc".
***************/


class Solution {
public:
    int mySqrt(int x) 
    {
        long long val = x;

        for(long long i = 0; i < 46341; i++)
        {
            if(i * i == val) return i;

            // as for example
            // 5 lies between 2^2 and 3^2, the square root should be 2
            if(val > i * i && val < (i+1) * (i+1)) return i;
        } 
        return 0;  
    }
};
