/**7. Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
*/
// Solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        long long reverse = 0;
        while (x != 0)
        {
            int temp = x % 10;
            x /= 10;
            reverse = reverse * 10 + temp;
        }
        if (reverse > INT_MAX || reverse < INT_MIN)
            return 0;
        return static_cast<int>(reverse);
    }
};