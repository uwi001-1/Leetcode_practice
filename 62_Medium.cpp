#include<iostream>
using namespace std;

// 1338. Reduce Array Size to The Half

/***************
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

Example 1:
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
    Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
    Possible sets of size 2 are {3,5},{3,2},{5,2}.
    Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.

Example 2:
Input: arr = [7,7,7,7,7,7]
Output: 1
    Explanation: The only possible set you can choose is {7}. This will make the new array empty.
***************/


class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        // sort the array to get all the same elements together 
        std::sort(arr.begin(), arr.end());

        vector<int> newArr; 
        int val = 1;
        int check = 0; 

        // count the frequency of each element and push into newArr
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[check] == arr[i])
            {
                if(check == i) continue;
                val += 1;
            }
            else
            {
                newArr.push_back(val);
                val = 1;
                check = i;
            }
        }
        newArr.push_back(val);

        // sort newArr to get the most repeated number's frequency at the end
        std::sort(newArr.begin(), newArr.end());

        int size = arr.size();
        int half = arr.size() / 2;

        int count = 0;
        int j = newArr.size() -1;

        while(j >= 0)
        {
            // return count the number of times we subtract elements till we reach equal or less than half 
            if(size <= half) return count;
            size -= newArr[j];
            j--;
            count += 1; 
        }

        // base case to return 1
        return 1;
    }
};
