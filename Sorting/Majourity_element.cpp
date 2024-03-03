/*169. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2*/

// Solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size() / 2;

        for (auto a : nums)
        {
            mp[a]++;
        }

        int ans = 0;

        for (auto a : mp)
        {
            if (a.second > n)
            {
                ans = a.first;
            }
        }

        return ans;
    }
};