#include<iostream>
using namespace std;

// 3756. Concatenate Non-Zero Digits and Multiply by Sum II

/***************
You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].

For each queries[i], extract the substring s[li..ri]. Then, perform the following:

Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
Let sum be the sum of digits in x. The answer is x * sum.
Return an array of integers answer where answer[i] is the answer to the ith query.

Since the answers may be very large, return them modulo 109 + 7.

Example 1:
Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]
Output: [12340, 4, 9]
    Explanation:
s[0..7] = "10203004"
x = 1234
sum = 1 + 2 + 3 + 4 = 10
Therefore, answer is 1234 * 10 = 12340.
s[1..3] = "020"
x = 2
sum = 2
Therefore, the answer is 2 * 2 = 4.
s[4..6] = "300"
x = 3
sum = 3
Therefore, the answer is 3 * 3 = 9.

Example 2:
Input: s = "1000", queries = [[0,3],[1,1]]
Output: [1, 0]
    Explanation:
s[0..3] = "1000"
x = 1
sum = 1
Therefore, the answer is 1 * 1 = 1.
s[1..1] = "0"
x = 0
sum = 0
Therefore, the answer is 0 * 0 = 0.

Example 3:
Input: s = "9876543210", queries = [[0,9]]
Output: [444444137]
    Explanation:
s[0..9] = "9876543210"
x = 987654321
sum = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 45
Therefore, the answer is 987654321 * 45 = 44444444445.
We return 44444444445 modulo (109 + 7) = 444444137.
***************/


class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) 
    {
        const long long MOD = 1e9 + 7;
        int m = s.size();

        // prefix arrays
        vector<long long> prefixSum(m+1, 0);    // sum of non-zero digits
        vector<long long> prefixX(m+1, 0);      // concatenated non-zero number
        vector<long long> prefixCount(m+1, 0);  // count of non-zero digits
        vector<long long> pow10(m+1, 1);        // powers of 10

        for(int i = 0; i < m; i++)
        {
            int digit = s[i] - '0';
            prefixSum[i+1] = prefixSum[i] + digit;
            prefixCount[i+1] = prefixCount[i] + (digit != 0 ? 1 : 0);
            // only append non-zero digits to x
            if(digit != 0)
                prefixX[i+1] = (prefixX[i] * 10 + digit) % MOD;
            else
                prefixX[i+1] = prefixX[i];
            pow10[i+1] = pow10[i] * 10 % MOD;
        }

        vector<int> arr;

        for(auto& q : queries)
        {
            int l = q[0], r = q[1];

            // sum of non-zero digits in [l,r]
            long long sum = prefixSum[r+1] - prefixSum[l];

            // count of non-zero digits in [l,r]
            long long cnt = prefixCount[r+1] - prefixCount[l];

            // x = prefixX[r+1] - prefixX[l] * 10^cnt
            long long x = (prefixX[r+1] - prefixX[l] * pow10[cnt] % MOD + MOD) % MOD;

            long long ans = (x * (sum % MOD)) % MOD;
            arr.push_back((int)ans);
        }

        return arr;
    }
};


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
