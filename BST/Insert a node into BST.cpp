TC= o(H)
SC= O(H)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root){
            TreeNode * cur= new TreeNode(val); 
            return cur; 
        }
        
        if(root->val > val ){
            root->left=  insertIntoBST(root->left, val);
            
        }
       
        else root->right= insertIntoBST(root->right, val);
        
    
        return root;
        
    }
};
