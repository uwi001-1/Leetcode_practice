#include<iostream>
using namespace std;

// 2130. Maximum Twin Sum of a Linked List

/***************
You are given a positive integer array nums.

The element sum is the sum of all the elements in nums.
The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
Return the absolute difference between the element sum and digit sum of nums.

Note that the absolute difference between two integers x and y is defined as |x - y|.

Example 1:
Input: nums = [1,15,6,3]
Output: 9
    Explanation: 
    The element sum of nums is 1 + 15 + 6 + 3 = 25.
    The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
    The absolute difference between the element sum and digit sum is |25 - 16| = 9.

Example 2:
Input: nums = [1,2,3,4]
Output: 0
    Explanation:
    The element sum of nums is 1 + 2 + 3 + 4 = 10.
    The digit sum of nums is 1 + 2 + 3 + 4 = 10.
    The absolute difference between the element sum and digit sum is |10 - 10| = 0.
***************/


class Solution {
public:
    int differenceOfSum(vector<int>& nums) 
    {
        // this data type as the element could be long 
        long long ele = 0;
        long long digit = 0; 

        for(int index : nums)
        {
            // add each element 
            ele += index;

            while(true)
            {
                if(index < 10) 
                {
                    digit += index;
                    break;
                }
                else
                {
                    // get the digit and also reduce the number
                    digit += index % 10;
                    index = index /10;
                }
            }
        }

        // this as we need to find the absolute difference
        long long diff; 
        if(ele >= digit) diff = ele - digit;
        if(ele < digit) diff = digit - ele;

        // could use this too abs(ele - digit);
        return diff;    
    }
};


// didn't work
// kinda logic worked
/****************
class Solution {
public:
    int pairSum(ListNode* head) 
    {
        // first get the half size of the list
        int count = 0;
        ListNode* curr = head;
        // loop through the list till the end and count the number of element
        while(curr != nullptr)
        {
            count += 1;
            curr = curr-> next;
        }
        int half = count/2;


        // second copy the half of the list to another linked list
        ListNode* pCurr = head; // to loop OG linked list
        ListNode* pHead = new ListNode(pCurr->val); // create new linked list
        pCurr = pCurr->next;
        // loop till the half of the OG linked list and copy it to the new linked list
        int reach = 0;
        while(true)
        {
            ListNode* pNew = new ListNode(pCurr->val);
            // we add in the head
            pNew->next = pHead;
            pHead = pNew;

            // next element in the OG linked list
            pCurr = pCurr->next;

            reach += 1;
            if(reach == half) break;
        }

        
        // third find the largest sum as we go through the end half of the OG linked list and the new linked list
        int largest = 0;
        int sum;
        ListNode* Pcurr = head;
        ListNode* current = pHead;
        int rr = 1;
        while(Pcurr != nullptr)
        {
            if(rr <= half)
            {
                rr += 1;
                Pcurr = Pcurr->next;
                continue;
            }
            
            sum = Pcurr->val + current->val;
            if(largest < sum) largest = sum;

            Pcurr = Pcurr->next;
            current = current->next;
        }
        return largest;
    }
};
*********/
