#include<iostream>
using namespace std;

// 2130. Maximum Twin Sum of a Linked List

/***************
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

Example 1:
Input: head = [5,4,2,1]
Output: 6
    Explanation:
    Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
    There are no other nodes with twins in the linked list.
    Thus, the maximum twin sum of the linked list is 6. 

Example 2:
Input: head = [4,2,2,3]
Output: 7
    Explanation:
    The nodes with twins present in this linked list are:
    - Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
    - Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
    Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 

Example 3:
Input: head = [1,100000]
Output: 100001
    Explanation:
    There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
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
