#include<iostream>
using namespace std;

// 3870. Count Commas in Range

/***************
You are given an integer n.
Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

In standard formatting:
A comma is inserted after every three digits from the right.
Numbers with fewer than 4 digits contain no commas.

Example 1:
Input: n = 1002
Output: 3
Explanation:
The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.

Example 2:
Input: n = 998
Output: 0
Explanation:
All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.
***************/


class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) 
    {
        long long total = 0;

        while(true)
        {
            if(need1 != 0 && need2 !=0)
            {
                long long val = min(need1, need2);
                total += val * min(costBoth, cost1 + cost2);
                need1 -= val;
                need2 -= val;
            }

            else if(need1 == 0 && need2 != 0)
            {
                long long val2 = need2;
                total += val2 * min(costBoth, cost2);
                need2 -= val2;
            }

            else if(need2 == 0 && need1 != 0)
            {
                long long val1 = need1;
                total += val1 * min(costBoth, cost1);
                need1 -= val1;
            }
            
            else
                break;
        }

        return total;
    }
};
