#include<iostream>
using namespace std;

// 3612. Process String with Special Operations I

/***************
You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.
Build a new string result by processing s according to the following rules from left to right:
If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.

Return the final string result after processing all characters in s.

Example 1:
Input: s = "a#b%*"
Output: "ba"
    Explanation:
i	s[i]	Operation	Current result
0	'a'	Append 'a'	"a"
1	'#'	Duplicate result	"aa"
2	'b'	Append 'b'	"aab"
3	'%'	Reverse result	"baa"
4	'*'	Remove the last character	"ba"
Thus, the final result is "ba".

Example 2:
Input: s = "z*#"
Output: ""
    Explanation:
i	s[i]	Operation	Current result
0	'z'	Append 'z'	"z"
1	'*'	Remove the last character	""
2	'#'	Duplicate the string	""
Thus, the final result is "".
***************/


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        // for element with only one element
        // the list becomes empty
        if(head->next == nullptr) return nullptr;
        
        // make an array to find the half element
        vector<int> arr;
        ListNode* curr = head;

        // loop through the linked list and push the value into the array
        while(curr != nullptr)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        int half = (arr.size()/2);

        ListNode* Curr = head;
        int count = 0;
        
        while(true)
        {
            if(count == half -1)
            {
                // for a linked list with two nodes
                if(Curr->next->next == nullptr)
                {
                    Curr->next = nullptr;
                }
                else
                {
                    // remove the element
                    Curr->next = Curr->next->next;
                }
                break;
            }
            Curr = Curr->next;
            count += 1;
        }
        return head;
    }
};
