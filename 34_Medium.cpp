#include<iostream>
using namespace std;

// 1833. Maximum Ice Cream Bars

/***************
It is a sweltering summer day, and a boy wants to buy some ice cream bars.
At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

## You must solve the problem by counting sort.

Example 1:
Input: costs = [1,3,2,4,1], coins = 7
Output: 4
    Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.

Example 2:
Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
    Explanation: The boy cannot afford any of the ice cream bars.

Example 3:
Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
    Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
***************/


class Solution {
public:
    // using counting sort 
    
    int maxIceCream(vector<int>& costs, int coins) 
    {
        // count represent how many icecream bars cost exactly index coins
        vector<int> count(100001, 0);
        
        // increase the count of index if the cost of the icecream bar is that index
        // count[5] = 2 means that there are two icecream bars of 5 costs
        for(int i = 0; i < costs.size(); i++)
        {
            count[costs[i]] += 1;
        }

        int total = 0;

        // loop through the count array and buy the most bars starting from cheapest icecream bars
        for(int price = 1; price <= 100000; price++)
        {
            // if we can buy
            while(count[price] > 0 && coins >= price)
            {
                // reduce the number of count of that price
                count[price] -= 1;

                // coins reduces by that cost
                coins -= price;

                // the total buy increases by 1
                total += 1;
            }
        }

        return total;
    }
};
