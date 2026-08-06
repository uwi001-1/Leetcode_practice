#include<iostream>
using namespace std;

// 3345. Smallest Divisible Digit Product I

/***************
You are given two integers n and t. 
Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

Example 1:
Input: n = 10, t = 2
Output: 10
Explanation:
The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

Example 2:
Input: n = 15, t = 3
Output: 16
Explanation:
The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.
***************/


class Solution {
public:
    // DFS (Dept-First Search)
    
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& suspicious)
    {
        suspicious[node] = true;

        for (int nei : graph[node])
        {
            if (!suspicious[nei])
            {
                dfs(nei, graph, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) 
    {
        // Step 1: Build adjacency list
        vector<vector<int>> graph(n);

        for (auto &edge : invocations)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        // Step 2: Find all suspicious methods
        vector<bool> suspicious(n, false);
        dfs(k, graph, suspicious);

        // Step 3: Check if any non-suspicious method calls a suspicious method
        for (auto &edge : invocations)
        {
            int u = edge[0];
            int v = edge[1];

            if (!suspicious[u] && suspicious[v])
            {
                // Cannot remove anything
                vector<int> ans;
                for (int i = 0; i < n; i++)
                {
                    ans.push_back(i);
                }
                return ans;
            }
        }

        // Step 4: Return all remaining (non-suspicious) methods
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (!suspicious[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
