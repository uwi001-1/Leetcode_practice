#include<iostream>
using namespace std;

// 3016. Minimum Number of Pushes to Type Word II

/***************
You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. 
For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. 
The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. 
You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

Example 1:
Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.

Example 2:
Input: word = "xyzxyzxyzxyz"
Output: 12
Explanation: The remapped keypad given in the image provides the minimum cost.
"x" -> one push on key 2
"y" -> one push on key 3
"z" -> one push on key 4
Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
It can be shown that no other mapping can provide a lower cost.
Note that the key 9 is not mapped to any letter: it is not necessary to map letters to every key, but to map all the letters.

Example 3:
Input: word = "aabbccddeeffgghhiiiiii"
Output: 24
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
"f" -> one push on key 7
"g" -> one push on key 8
"h" -> two pushes on key 9
"i" -> one push on key 9
Total cost is 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24.
It can be shown that no other mapping can provide a lower cost.
***************/


class Solution {
public:
    int minimumPushes(string word) 
    {
        // sort the word
        std::sort(word.begin(), word.end());
        vector<int> arr;
        int count = 1;

        // in the array with the size of the word
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == word[i+1]) count++;
            else
            {
                arr.push_back(count);
                count = 1;
            }
        }

        // sort the array in descending order
        std::sort(arr.begin(), arr.end(), greater<int>());
        int ans = 0;

        // add the arr element based on size
        for(int j = 0; j < arr.size(); j++)
        {
            if(j < 8) ans += arr[j];
            else if(j < 16) ans += (arr[j] * 2);
            else if(j < 24) ans += (arr[j] * 3);
            else ans += (arr[j] * 4);
        }

        return ans;
    }
};
