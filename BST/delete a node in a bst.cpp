TC- O(H)
SC- O(H)


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)return NULL; 
        if(root ->val == key )return _delete(root); 
        
        TreeNode * cur= root ; 
        while(root){
            
            if(root->val >key){
                if(root->left && root->left->val==key){
                    root->left = _delete(root->left);
                    break ; 
                }
                else root= root->left; 
            }
            else {
                if(root->right && root->right->val==key){
                    root->right = _delete(root->right);
                    break ; 
                }
                else root= root->right; 
            }
            
        }
        return cur;
        
    }
    TreeNode* _delete(TreeNode* root){
        if(!root->left)return root->right;
        else if(!root->right)return root->left;
        // if both are present
        else {
            TreeNode* rightvala= root->right;
            TreeNode* leftnode= root->left;
            TreeNode* temp= leftnode;
            while(temp->right)temp=temp->right;
            temp->right= rightvala;
            return leftnode;
        }
    }
};
