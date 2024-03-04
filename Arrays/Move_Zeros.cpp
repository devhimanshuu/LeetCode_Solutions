/*283. Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 */

// Solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                temp.push_back(nums[i]);
            }
        }
        for (int i = 0; i < temp.size(); i++)
        {
            nums[i] = temp[i];
        }
        for (int i = temp.size(); i < n; i++)
        {
            nums[i] = 0;
        }
    }
};