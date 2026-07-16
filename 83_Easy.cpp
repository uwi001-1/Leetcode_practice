#include<iostream>
using namespace std;

// 202. Happy Number

/***************
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
    Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:
Input: n = 2
Output: false
***************/


class Solution {
public:
    int gcd(int a, int b)
    {
        while(b) { a %= b; swap(a,b); }
        return a;
    }    

    long long gcdSum(vector<int>& nums) 
    {
        long long max = 0;
        vector<int> prefixGcd;

        for(int i =0; i < nums.size(); i++)
        {
            // change the max value to the new value if it's higher
            if(max <= nums[i]) max = nums[i];

            prefixGcd.push_back(gcd(nums[i], max));
        } 
        // now we are done with the prefixGcd array

        // next we sort the array
        std::sort(prefixGcd.begin(), prefixGcd.end());

        int front = 0;
        int back = prefixGcd.size() -1;

        long long sum = 0;

        while(true)
        {
            // avoid unpaired            
            if(front == back || front > back) break;

            // sum the gcd of the pairs 
            sum += gcd(prefixGcd[front], prefixGcd[back]);

            front++;
            back--;
        }

        // return the sum of the gcd pairs of the prefixGcd array
        return sum;
    }
};

