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
    int maxDepth(TreeNode* root) {
        int ans=1;
        if(root==NULL)return 0;
        if(root->left!=NULL)ans=max(ans,maxDepth(root->left)+1);
        if(root->right!=NULL)ans=max(ans,maxDepth(root->right)+1);
        return ans;
    }
};
