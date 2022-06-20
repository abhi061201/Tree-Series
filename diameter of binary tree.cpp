NAIVE APPROACH 
FOR EVERY NODE CHECK LEFT AND RIGHT HEIGHT

TC- O(N *N )
SC- o(N) AST;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
         if(root==NULL)return 0;
   
   int l= diameterOfBinaryTree(root->left);
   int r= diameterOfBinaryTree(root->right);
  int lh=height(root->left);
  int rh= height(root->right);
   return max(max(l,r),lh+rh);
        
        
    }
    
int height( TreeNode *root){
    if(root==NULL)return 0;
  
    int l= height(root->left);
    int r= height(root->right);
    return 1+max(l,r);
    
}
};


OPTIMISED
WITH THE HEIGHT RECUSRIVE CALL WE ARE CHECKING THE DIAMETER


TC= O(N)
SC= O(N) AST



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
    int maxi=0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        int max=  go(root);
        return maxi;
    }
    int go(TreeNode* root){
        if(!root )return 0;
        int lh=0,rh=0;
        lh= go(root->left);
        rh= go(root->right);
        
        maxi= max(maxi, lh+rh);
        return 1+max(lh,rh);
        
    }
};
