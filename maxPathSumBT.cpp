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
same logic as max diameter of BT 
class Solution {
public:
    int maxi=-1e9;
    
    int maxPathSum(TreeNode* root) {
        go(root);    
        return maxi;    
    }
    int go(TreeNode* root){
        if(!root){
            return 0;
            
        }
        int lh= max(0,go(root->left));
        int rh= max(0,go(root->right));
        maxi= max({maxi,lh+rh+root->val});
        
        return root->val + max(lh,rh);
    }
};
