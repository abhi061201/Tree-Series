TC- O(N)
SC- O(N) ast
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)return 1;
        
        return BST(root, -1e18, 1e18);
    }
    bool BST(TreeNode* root, long min, long max){
        if(!root)return 1;
    
        if(root->val <=min || root->val >=max)return 0;
        
        bool left= BST(root->left, min, root->val);
        bool right= BST(root->right, root->val, max);
        return left & right;
        
        
    }
};
