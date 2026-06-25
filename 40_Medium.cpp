#include<iostream>
using namespace std;

// 3737. Count Subarrays With Majority Element I

/***************
You are given an integer array nums and an integer target.

Return the number of subarrays of nums in which target is the majority element.

The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

Example 1:
Input: nums = [1,2,2,3], target = 2
Output: 5
    Explanation:
    Valid subarrays with target = 2 as the majority element:
nums[1..1] = [2]
nums[2..2] = [2]
nums[1..2] = [2,2]
nums[0..2] = [1,2,2]
nums[1..3] = [2,2,3]
So there are 5 such subarrays.

Example 2:
Input: nums = [1,1,1,1], target = 1
Output: 10
    Explanation:
    ​​​​​​​All 10 subarrays have 1 as the majority element.

Example 3:
Input: nums = [1,2,3], target = 4
Output: 0
    Explanation:
    target = 4 does not appear in nums at all. Therefore, there cannot be any subarray where 4 is the majority element. Hence the answer is 0.
***************/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
       // save the head before advancing
        ListNode* pHead = l1; 
       
        ListNode* curr1 = l1;
        ListNode* prev = nullptr;
        ListNode* curr2 = l2;

        int extra = 0;
        int value;

        while(true)
        {
            // when both the linked list has value
            if(curr1 != nullptr && curr2 != nullptr)
            {
                value = curr1->val + curr2->val + extra;
            
                if(value > 9)
                {
                    // for the carry over ahead
                    extra = value / 10;

                    // take the last digit as the value
                    value = value % 10;
                }
                else extra = 0;
            
                curr1->val = value;

                prev = curr1;
                curr1 = curr1->next;
                curr2 = curr2-> next;
            }

            // when linked list 2 is done
            else if(curr1 != nullptr)
            {
                value = curr1->val + extra;
            
                if(value > 9)
                {
                    extra = value / 10;
                    value = value % 10;
                }
                else extra = 0;
            
                curr1->val = value;

                prev = curr1;
                curr1 = curr1->next;
            }

            // when linked list 1 is done
            else if(curr2 != nullptr)
            {
                if(extra != 0)
                {
                    value = curr2->val + extra;
            
                    if(value > 9)
                    {
                        extra = value / 10;
                        value = value % 10;
                    }
                    else extra = 0;
                }
                else value = curr2->val;

                // add the new value to the end of the linked list 1
                ListNode* pNew = new ListNode(value);

                prev->next = pNew;
                prev = pNew;
                curr2 = curr2-> next;
            }

            // when both the linked list is done but there still remains extra 
            else if(extra != 0)
            {
                ListNode* pNew = new ListNode(extra);
                prev->next = pNew;

                break;
            }
            
            else break;
        }
        // return the head node pointing to the linked list 1
        return pHead;
    }
};
