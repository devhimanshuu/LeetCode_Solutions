/*137. Single Number II
Solved
Medium
Topics
Companies
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 */

// Solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        // Declare the hashmap.
        // And hash the given array:
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }

        // Find the single element and return the answer:
        for (auto it : mpp)
        {
            if (it.second == 1)
                return it.first;
        }

        // This line will never execute
        // if the array contains a single element.
        return -1;
    }
};