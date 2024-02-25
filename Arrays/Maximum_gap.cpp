/*
164. Maximum Gap

Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.



Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.*/

// Solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> nums2;
        int n = nums.size();
        if (n < 2)
        {
            return 0;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int diff = nums[i + 1] - nums[i];
            nums2.push_back(diff);
        }
        int max = nums2[0];
        for (int k = 0; k < nums2.size(); k++)
        {
            if (nums2[k] > max)
            {
                max = nums2[k];
            }
        }
        return max;
    }
};