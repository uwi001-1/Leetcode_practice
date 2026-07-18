#include<iostream>
using namespace std;

// 3312. Sorted GCD Pair Queries

/***************
You are given an integer array nums of length n and an integer array queries.

Let gcdPairs denote an array obtained by calculating the GCD of all possible pairs (nums[i], nums[j]), where 0 <= i < j < n, and then sorting these values in ascending order.
For each query queries[i], you need to find the element at index queries[i] in gcdPairs.

Return an integer array answer, where answer[i] is the value at gcdPairs[queries[i]] for each query.

The term gcd(a, b) denotes the greatest common divisor of a and b.

Example 1:
Input: nums = [2,3,4], queries = [0,2,2]
Output: [1,2,2]
    Explanation:
gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1].
After sorting in ascending order, gcdPairs = [1, 1, 2].
So, the answer is [gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2].

Example 2:
Input: nums = [4,4,2,1], queries = [5,3,1,0]
Output: [4,2,1,1]
    Explanation:
gcdPairs sorted in ascending order is [1, 1, 1, 2, 2, 4].

Example 3:
Input: nums = [2,2], queries = [0,0]
Output: [2,2]
    Explanation:
gcdPairs = [2].
***************/


class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) 
    {
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // count frequency of each number
        vector<long long> freq(maxVal + 1, 0);
        for(int x : nums) freq[x]++;

        // cnt[d] = how many numbers in nums are divisible by d
        vector<long long> cnt(maxVal + 1, 0);
        for(int d = 1; d <= maxVal; d++)
        {
            for(int multiple = d; multiple <= maxVal; multiple += d)
            {
                cnt[d] += freq[multiple];
            }
        }

        // pairsWithGcdExactlyD[d] = pairs where GCD is EXACTLY d
        // using inclusion-exclusion: subtract pairs where GCD is multiple of d
        vector<long long> exact(maxVal + 1, 0);
        for(int d = maxVal; d >= 1; d--)
        {
            // pairs where d divides both = cnt[d] choose 2
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;
            
            // subtract pairs where GCD is a multiple of d (2d, 3d, ...)
            for(int multiple = 2 * d; multiple <= maxVal; multiple += d)
            {
                exact[d] -= exact[multiple];
            }
        }

        // build prefix sum so we can answer queries in O(1)
        vector<long long> prefix(maxVal + 2, 0);
        for(int d = 1; d <= maxVal; d++)
        {
            prefix[d] = prefix[d-1] + exact[d];
        }

        // answer each query using binary search on prefix
        vector<int> arr;
        for(long long q : queries)
        {
            // find smallest d where prefix[d] > q
            int lo = 1, hi = maxVal, ans = maxVal;
            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if(prefix[mid] > q)
                {
                    ans = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
            arr.push_back(ans);
        }

        return arr;
    }
};


// Time Limit Exceeded (713/721)
// this uses brute force
/***************
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) 
    {
        vector<int> gcdPairs;

        // handle gcdPairs array
        for(int i = 0; i < nums.size() - 1; i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                gcdPairs.push_back(std::gcd(nums[i], nums[j]));
            }
        } 

        // sort gcdPairs
        std::sort(gcdPairs.begin(), gcdPairs.end());

        vector<int> arr; 

        // handle arr
        for(int k = 0; k < queries.size(); k++)
        {
            arr.push_back(gcdPairs[queries[k]]);
        }

        return arr;   
    }
};
***************/