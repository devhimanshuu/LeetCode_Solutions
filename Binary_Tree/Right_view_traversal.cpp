// 199. Binary Tree Right Side View
// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example 1:

// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]
// Example 2:

// Input: root = [1,null,3]
// Output: [1,3]
// Example 3:

// Input: root = []
// Output: []

// Solution
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
    int Levels(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(Levels(root->left), Levels(root->right));
    }
    void Preorder(TreeNode *root, vector<int> &ans, int level)
    {
        if (root == NULL)
            return;
        ans[level] = root->val;
        Preorder(root->left, ans, level + 1);
        Preorder(root->right, ans, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans(Levels(root), 0);
        Preorder(root, ans, 0);
        return ans;
    }
};