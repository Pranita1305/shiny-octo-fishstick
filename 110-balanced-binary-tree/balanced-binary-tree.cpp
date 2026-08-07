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
    bool isBalanced(TreeNode* root) {
       if(root==NULL) return true;
       if(!check(root)) return false;
       return(isBalanced(root->left) && isBalanced(root->right));
    }
    bool check(TreeNode* root){
        if(root==NULL) return true;
        return (abs(depth(root->left)-depth(root->right))<=1);
    }
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
};

