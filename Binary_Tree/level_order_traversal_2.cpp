// 107. Binary Tree Level Order Traversal II
// Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []

// Solution

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    void LOrder(TreeNode *root, vector<vector<int>> &ans)
    {
        int n = Levels(root);
        for (int i = 1; i <= n; i++)
        {
            vector<int> v;
            nthLevel(root, 1, i, v);
            ans.push_back(v);
            cout << endl;
        }
    }
    int Levels(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(Levels(root->left), Levels(root->right));
    }
    void nthLevel(TreeNode *root, int curr, int level, vector<int> &v)
    {
        if (root == NULL)
            return;
        if (curr == level)
        {
            v.push_back(root->val);
            return;
        }
        nthLevel(root->left, curr + 1, level, v);
        nthLevel(root->right, curr + 1, level, v);
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        LOrder(root, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};