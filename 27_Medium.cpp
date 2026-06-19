#include<iostream>
using namespace std;

// 1344. Angle Between Hands of a Clock

/***************
Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.

Example 1:
Input: hour = 12, minutes = 30
Output: 165

Example 2:
Input: hour = 3, minutes = 30
Output: 75

Example 3:
Input: hour = 3, minutes = 15
Output: 7.5
***************/


class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        // for the minute hand
        double minHand = minutes * 6;

        // for the hour hand
        double hourHand;
        if(hour == 12) hourHand = 0.0;
        else hourHand = (hour * 30);
        
        // account for hourhand for the minutes
        hourHand += (minutes * 30.0 / 60); 

        // calculate the angle in absolute way
        double angle;
        if(hourHand > minHand) angle = hourHand - minHand;
        else angle = minHand - hourHand;

        // find the smallest angle between them
        if(angle < 360-angle) return angle;
        else return 360-angle;
    }
};
