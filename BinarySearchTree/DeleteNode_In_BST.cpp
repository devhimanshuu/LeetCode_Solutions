

/**450. Delete Node in a BST
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.


Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []**/

// solution
// Approach: The problem can be solved by using the concept of the Inorder Predecessor of the node to be deleted. The Inorder Predecessor of a node is the node that appears before the current node in the inorder traversal of the Binary Search Tree. The Inorder Predecessor of a node can be found by finding the rightmost node in the left subtree of the node to be deleted.
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
    TreeNode *iop(TreeNode *root)
    {
        TreeNode *pred = root->left;
        while (pred->right)
        {
            pred = pred->right;
        }
        return pred;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {

            if (root->left == NULL && root->right == NULL)
                return NULL;
            if (root->left == NULL || root->right == NULL)
            {
                if (root->left != NULL)
                    return root->left;
                else
                    return root->right;
            }

            if (root->left != NULL && root->right != NULL)
            {
                TreeNode *pred = iop(root);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};