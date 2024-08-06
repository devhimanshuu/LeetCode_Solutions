// 1346. Check If N and Its Double Exist
// Given an array arr of integers, check if there exist two indices i and j such that :

// i != j
// 0 <= i, j < arr.length
// arr[i] == 2 * arr[j]

// Example 1:

// Input: arr = [10,2,5,3]
// Output: true
// Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
// Example 2:

// Input: arr = [3,1,7,11]
// Output: false
// Explanation: There is no i and j that satisfy the conditions.

// Solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        set<int> set;
        for (int i = 0; i < arr.size(); i++)
        {
            if (set.count(2 * arr[i]) > 0 || ((arr[i] % 2 == 0) && set.count(arr[i] / 2) > 0))
                return true;
            set.insert(arr[i]);
        }
        return false;
    }
};