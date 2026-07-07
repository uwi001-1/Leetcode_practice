#include<iostream>
using namespace std;

// 328. Odd Even Linked List

/***************
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
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
