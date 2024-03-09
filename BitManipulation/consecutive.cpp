/*2177. Find Three Consecutive Integers That Sum to a Given Number
Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers, return an empty array.



Example 1:

Input: num = 33
Output: [10,11,12]
Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].
Example 2:

Input: num = 4
Output: []
Explanation: There is no way to express 4 as the sum of 3 consecutive integers.*/

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        vector<long long> ans;

        if ((num % 3) != 0)
            return {};

        long long start = (num - 3) / 3;

        ans.push_back(start);
        ans.push_back(start + 1);
        ans.push_back(start + 2);

        return ans;
    }
};