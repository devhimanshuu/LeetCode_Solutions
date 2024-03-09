/*75. Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]*/

// Solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &arr)
    {
        int n = arr.size();
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                cnt0++;
            else if (arr[i] == 1)
                cnt1++;
            else
                cnt2++;
        }

        for (int i = 0; i < cnt0; i++)
            arr[i] = 0;

        for (int i = cnt0; i < cnt0 + cnt1; i++)
            arr[i] = 1;

        for (int i = cnt0 + cnt1; i < n; i++)
            arr[i] = 2;
    }
};
