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
    bool isSymmetric(TreeNode* root) {
        
        if(!root)return 1;
        return inorder(root->left, root->right);
    }
   bool  inorder(TreeNode* root1, TreeNode*root2){
        
        if(!root1 && !root2)return 1;
        if(!root1 || !root2)return 0;
       
        
        bool b1=inorder(root1->left , root2->right);
         if(root1->val!=root2->val)return 0;
        bool b2=inorder(root1->right, root2->left);
        return b1&b2;
    }
};
