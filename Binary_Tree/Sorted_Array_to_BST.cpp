// 108. Convert Sorted Array to Binary Search Tree
// Given an integer array nums where the elements are sorted in ascending order, convert it to a
// height-balanced
//  binary search tree.

// Example 1:

// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:

// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

// Solution:-
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    TreeNode *helper(vector<int> &arr, int lo, int hi)
    {
        if (lo > hi)
            return NULL;
        int mid = lo + (hi - lo) / 2;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = helper(arr, lo, mid - 1);
        root->right = helper(arr, mid + 1, hi);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &arr)
    {
        int n = arr.size();
        return helper(arr, 0, n - 1);
    }
};