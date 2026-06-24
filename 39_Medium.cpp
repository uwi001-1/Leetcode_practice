#include<iostream>
using namespace std;

// 2. Add Two Numbers

/***************
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
    Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
***************/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} 
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
            // when the linked list has value
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

            // when both linked list is done but there still remains extra 
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


// this didn't work out as the numbers could be big(can't fit in long long or int)
// we also can't loop around the int value like an array
/*******
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        int num = 0;
        int n1 = 0, n2 = 0;
        while(curr1 != nullptr)
        {
            if(curr1 != nullptr)
            {
                n1 += (curr1->val * (pow(10, num)));
                curr1 = curr1->next;
            }
            num += 1;
        }

        int number = 0;
        while(curr2 != nullptr)
        {
            if(curr2 != nullptr) 
            {
                n2 += (curr2->val * (pow(10, num)));
                curr2 = curr2->next;
            }
            number += 1;
        }

        int sum = n1 + n2;

        ListNode* pHead = nullptr;
        for(int i =0; i < sum.size(); i++)
        {
            ListNode* pNew = new ListNode(sum[i])

            if(pHead == nullptr) pHead = pNew;
            else
            {
                pNew->next = pHead;
                pHead = pNew;
            }
        }
        return pHead;
********/