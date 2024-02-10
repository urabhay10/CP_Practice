// https://leetcode.com/problems/convert-bst-to-greater-tree/
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
    void nodearr(TreeNode* node,vector<pair<TreeNode*,int>> &v){
        if(node==nullptr) return;
        v.push_back({node,node->val});
        nodearr(node->left,v);
        nodearr(node->right,v);
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<pair<TreeNode*,int>> v;
        nodearr(root,v);
        sort(v.begin(),v.end(),[](auto &p1,auto &p2){
            return (p1.second>p2.second);
        });
        long long prefix = 0;
        for(int i=0;i<v.size();i++){
            prefix+=v[i].second;
            v[i].second=prefix;
            v[i].first->val = v[i].second;
        }
        return root;
    }
};