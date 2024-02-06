//https://leetcode.com/problems/invert-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void swap_nodes(TreeNode* node){
        if((node)==nullptr) return;
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        swap_nodes(node->left);
        swap_nodes(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        swap_nodes(root);
        return root;
    }
};