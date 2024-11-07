/** Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.



Example 1:


Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]
Example 2:


Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]


Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104
The value of each node in the tree is unique.
root is guaranteed to be a valid binary search tree.
0 <= low <= high <= 104 **/

// Solution
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    void Trim(TreeNode *root, int lo, int hi)
    {
        if (root == NULL)
            return;
        while (root->left != NULL)
        {
            if (root->left->val < lo)
                root->left = root->left->right;
            else if (root->left->val > hi)
                root->left = root->left->left;
            else
                break;
        }
        while (root->right != NULL)
        {
            if (root->right->val > hi)
                root->right = root->right->left;
            else if (root->right->val < lo)
                root->right = root->right->right;
            else
                break;
        }
        Trim(root->left, lo, hi);
        Trim(root->right, lo, hi);
    }
    TreeNode *trimBST(TreeNode *root, int lo, int hi)
    {
        TreeNode *dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        Trim(dummy, lo, hi);
        return dummy->left;
    }
};
