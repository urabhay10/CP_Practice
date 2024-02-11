//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node) return NULL;
        if(node==p || node==q) return node;
        auto ans1 = lowestCommonAncestor(node->left,p,q);
        auto ans2 = lowestCommonAncestor(node->right,p,q);
        if(ans1 && ans2) return node;
        if(ans1) return ans1;
        return ans2;
    }
};