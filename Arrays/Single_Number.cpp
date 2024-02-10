/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
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

        // Run a loop for selecting elements:
        for (int i = 0; i < n; i++)
        {
            int num = nums[i]; // selected element
            int cnt = 0;

            // find the occurrence using linear search:
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == num)
                    cnt++;
            }

            // if the occurrence is 1 return ans:
            if (cnt == 1)
                return num;
        }
        return -1;
    }
};