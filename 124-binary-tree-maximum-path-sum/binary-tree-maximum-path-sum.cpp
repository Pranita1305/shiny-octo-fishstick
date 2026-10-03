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
    int maxPath=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        diam(root);
        return maxPath;
    }
    int diam(TreeNode* root){
        if(root==NULL) return 0;

        int left=max(diam(root->left),0);
        int right=max(diam(root->right),0);

        maxPath=max(maxPath, left+right+root->val);

        return max(left,right)+root->val;
        
    }
};