#include<iostream>
using namespace std;

// 2126. Destroying Asteroids

/***************
You are given an integer mass, which represents the original mass of a planet. 
You are further given an integer array asteroids, where asteroids[i] is the mass of the ith asteroid.
You can arrange for the planet to collide with the asteroids in any arbitrary order. 
If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.

Return true if all asteroids can be destroyed. Otherwise, return false.

Example 1:
Input: mass = 10, asteroids = [3,9,19,5,21]
Output: true
    Explanation: One way to order the asteroids is [9,19,5,3,21]:
    - The planet collides with the asteroid with a mass of 9. New planet mass: 10 + 9 = 19
    - The planet collides with the asteroid with a mass of 19. New planet mass: 19 + 19 = 38
    - The planet collides with the asteroid with a mass of 5. New planet mass: 38 + 5 = 43
    - The planet collides with the asteroid with a mass of 3. New planet mass: 43 + 3 = 46
    - The planet collides with the asteroid with a mass of 21. New planet mass: 46 + 21 = 67
    All asteroids are destroyed.

Example 2:
Input: mass = 5, asteroids = [4,9,23,4]
Output: false
    Explanation: The planet cannot ever gain enough mass to destroy the asteroid with a mass of 23.
    After the planet destroys the other asteroids, it will have a mass of 5 + 4 + 9 + 4 = 22.
    This is less than 23, so a collision would not destroy the last asteroid.
***************/


class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        // sort the array in ascending order as that is the most reasonable
        // If you can't destroy a smaller asteroid, you definitely can't destroy a larger one. So sorting ascending and going left to right is optimal.
        std::sort(asteroids.begin(), asteroids.end()); 
        
        // use long long data type as it is 64-bit size as the mass size can be huge
        long long newMass = mass;

        // this is a for loop, in vectors, use .size() makes it complicated
        for(int i : asteroids)
        {
            // if ever can't be destroyed, then return false
            if(i > newMass) return false;
            else
            {
                // destroy and add to the mass of the planet
                newMass += i;
            }
        }
        return true;
    }
};
