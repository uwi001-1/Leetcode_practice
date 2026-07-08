#include<iostream>
using namespace std;

// 3754. Concatenate Non-Zero Digits and Multiply by Sum I

/***************
You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

Example 1:
Input: n = 10203004
Output: 12340
    Explanation:
    The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
    The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
    Therefore, the answer is x * sum = 1234 * 10 = 12340.

Example 2:
Input: n = 1000
Output: 1
    Explanation:
    The non-zero digit is 1, so x = 1 and sum = 1.
    Therefore, the answer is x * sum = 1 * 1 = 1.
***************/


// Time Limit Exceeded 
/**********
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) 
    {
        const long long MOD = 1e9 + 7;
        
        vector<int> arr;

        for(int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            long long x = 0;
            long long sum = 0;

            for(int j = l; j <= r; j++)
            {
                int digit = s[j] - '0';
                if(digit == 0) continue;
    
                x = (x * 10 + digit) % MOD;
                sum += digit;
            }

            long long ans = (x * (sum % MOD)) % MOD;

            arr.push_back(ans);
        }
        
        return arr;
    }
};
**********/


// As we need to handle the MOD
/****************
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) 
    {
        vector<int> arr;

        for(int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            long long n = stoll(s.substr(l, r - l + 1));

            if(n == 0)
            {
                arr.push_back(0);
                continue;
            }

            int digit;
            long long  sum = 0; 
            long long  x = 0;
            int j = 1; 

            while(n > 0)
            {
                // remainder
                digit = n % 10;

                // remove one digit from back 
                n = n / 10;

                // skip if zero
                if(digit == 0) continue;

                    sum += digit; 
                x += digit * j;
                j *= 10;
            }
        
            long long ans = sum * x;

            arr.push_back(ans);
        }
        
        return arr;
    }
};
**************/
